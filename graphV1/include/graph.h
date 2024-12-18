#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <memory>
#include <deque>
#include <iostream>
#include "vertex.h"
#include "edge.h"

//for later
//using NeighborAndWeight = std::vector<std::pair<const Vertex*, float>>;

class Graph {
public:
	Graph();
	void render() const;
	void update();

	void addVertex(Vector2 location);
	void addVertex(float x, float y);
	// void removeVertex(const Vertex* vertex);
	void addEdge(const Vertex* v1, const Vertex* v2, float weight);

	// Returns references and pointers
	const std::deque<std::unique_ptr<Vertex>>& getVerts();
	std::vector<Edge>& getEdges();

	void printInfo() const;
	
private:
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
};


#endif // GRAPH_H