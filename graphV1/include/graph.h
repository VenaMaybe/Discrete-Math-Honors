#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <memory>
#include <deque>
#include <iostream>
#include <limits> // For std::numeric_limits
#include <queue> // For std::priority_queue
#include <functional> // For std::greater
#include "vertex.h"
#include "edge.h"
#include "graph_interaction_manager.h"

//for later
//using NeighborAndWeight = std::vector<std::pair<const Vertex*, float>>;

class Graph {
public:
	Graph(GraphInteractionManager* graphInteractionManager);
	void render() const;
	void update();

	// Called when updating shortest path information (Using Dijkstra's)
	void checkShortestPathFrom(const Vertex* start);

	// Printers
	void printInfo() const;
	void printAdjList() const;

	// Adders
	void addVertex(Vector2 location);
	void addVertex(float x, float y);
	void addEdge(const Vertex* from, const Vertex* to, float weight);
		// void removeVertex(const Vertex* vertex);

	// Returns references and pointers
	const std::deque<std::unique_ptr<Vertex>>& getVerts();
	std::vector<Edge>& getEdges();

private:
	GraphInteractionManager* graphInteractionManager;

	// This is like an Edge List since both are stored independently
	// Deque is a double-ended queue
	std::deque<std::unique_ptr<Vertex>> verts;
	std::vector<Edge> edges;

	// Adjacency List where each key is a node and its value is a list of tuples (neighbor, weight)
	// Dictionary (VertexKey : List{(neighbor, weight), ...})
	std::unordered_map<
		const Vertex*, 
		std::vector<std::pair<const Vertex*, float>>
	> adjacencyList;

	// From the starting vertex
	// Dictionary (destinationVertex : costFromStartVertex)
	std::unordered_map<const Vertex*, float> totalDistanceTo;
};


#endif // GRAPH_H