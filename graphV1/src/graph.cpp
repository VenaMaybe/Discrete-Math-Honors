#include "graph.h"

Graph::Graph() {}

void Graph::render() const {
	for (const auto& v : verts) {
		v->render();
	}
	for (const auto& e : edges) {
		e.render();
	}
}

void Graph::update() {
	for (auto& v : verts) {
		v->update();
	}
	for (auto& e : edges) {
		e.update();
	}
}

// using raw pointer to Vertex as the key
void Graph::addVertex(Vector2 location) {
	addVertex(location.x, location.y);
}

void Graph::addVertex(float x, float y) {
	verts.push_back(std::make_unique<Vertex>(x, y));
	adjacencyList.emplace( // creates a list emplace for each added vertex
		verts.back().get(), // pointer from last vertex added to verts
							// back() returns unique_ptr<Vertex>& reference
							// get()  returns raw pointer managed by unique_ptr
		std::vector<std::pair<const Vertex*, float>>() // initialize with an empty adjacency list
	);
}

void Graph::addEdge(const Vertex* from, const Vertex* to, float weight) {
	// emplace_back takes the constructor arguments for the element type as its parameters
	edges.emplace_back(from, to, weight); // <- basically Edge()
	// We want to link both together so it's an undirected graph
	adjacencyList.at(from).emplace_back(to, weight);
	adjacencyList.at(to).emplace_back(from, weight);
}

const std::deque<std::unique_ptr<Vertex>>& Graph::getVerts() {
	return verts;
}

std::vector<Edge>& Graph::getEdges() {
	return edges;
}

// =========== util

void Graph::printInfo() const {
	std::cout << "# Edges: " << edges.size() << std::endl;
	std::cout << "# Verts: " << verts.size() << std::endl;
}

void Graph::printAdjList() const {
	for (const auto& vertexEntry : adjacencyList) {
		std::cout << "Vert: " << vertexEntry.first << std::endl; // throw a name in eventually
		for (const auto& neighborWeight : vertexEntry.second) {
			std::cout << "\t └─Neighbors: " << neighborWeight.first 
					  << " with weight: " << neighborWeight.second << std::endl;
		}
	}
}