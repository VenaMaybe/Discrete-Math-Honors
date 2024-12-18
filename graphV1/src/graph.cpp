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

void Graph::addVertex(Vector2 location) {
	auto vertex = 
	verts.push_back(std::make_unique<Vertex>(location.x, location.y));
	adjacencyList.emplace(
		verts.back().get(),
		);
}

void Graph::addVertex(float x, float y) {
	verts.push_back(std::make_unique<Vertex>(x, y));
}

void Graph::addEdge(const Vertex* v1, const Vertex* v2, float weight) {
	// emplace_back takes the constructor arguments for the element type as its parameters
	edges.emplace_back(v1, v2, weight); // <- basically Edge()
}

const std::deque<std::shared_ptr<Vertex>>& Graph::getVerts() {
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