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

void Graph::checkShortestPathFrom(const Vertex* start) {
	// Initialize the dictionary of distances
	for (const auto& vertex : verts) {
		totalDistanceTo.emplace(vertex.get(), std::numeric_limits<float>::infinity());
	}

	// We set our start node with distance 0
	totalDistanceTo.at(start) = 0.f;

	// Keep track of how we got to each vertex to reconstruct paths
	std::unordered_map<const Vertex*, const Vertex*> previous;
		// previous[v] will tell us which vertex we cae from to reach v along the shortest path

	for (const auto& vertex : verts) {
		// Initially, no vertex has a predecessor so all values are set to nullptr
		previous[vertex.get()] = nullptr;
			// We have to use the operator[] since it inserts a default value if the key doesn't exist
	}

	// This is a priority queue to get the vertex with the current smallest distance
	// < Elements stored, Container used for storage, Comparison function for ordering>
	std::priority_queue<
        std::pair<float, const Vertex*>,
        std::vector<std::pair<float, const Vertex*>>,
        std::greater<>
    > pq;
    pq.push({0.0f, start});

	// Main Dijkstra's Loop
	while (!pq.empty()) {
		// Get the vertex with the smallest distance
		float currentDist = pq.top().first;
		const Vertex* currentVertex = pq.top().second;
		pq.pop();

		// If this distance doesn't match the one in totalDistanceTo, it's outdated so we skip it
		if (currentDist > totalDistanceTo.at(currentVertex)) {
			continue;
		}

		// Check all neighbors of currentVertex
		for (const auto& [neighbor, weight] : adjacencyList.at(currentVertex)) {

			// Calculate the alternate route distance
			float altDistance = totalDistanceTo.at(currentVertex) + weight;

			// If we find a shorter path to neighbor
			if (altDistance < totalDistanceTo.at(neighbor)) {
				// Store the path
				totalDistanceTo.at(neighbor) = altDistance; 
				
				// Record the path
				previous[neighbor] = currentVertex;

				// Push the updated distance to the priority queue
				pq.push({altDistance, neighbor});
			}
		}
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
			std::cout << "\t└─Neighbors: " << neighborWeight.first 
					  << " with weight: " << neighborWeight.second << std::endl;
		}
	}
}