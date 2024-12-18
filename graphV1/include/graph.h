#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <memory>
#include <deque>
#include <iostream>
#include "vertex.h"
#include "edge.h"

class Graph {
public:
	Graph();
	void render() const;
	void update();

	void addVertex(Vector2 location);
	void addVertex(float x, float y);
	void addEdge(const Vertex* v1, const Vertex* v2, float weight);

	// Returns references and pointers
	const std::deque<std::shared_ptr<Vertex>>& getVerts();
	std::vector<Edge>& getEdges();

	void printInfo() const;
	
private:
	// This is like an Edge List since both are stored independently
	// Deque is a double-ended queue
	std::deque<std::shared_ptr<Vertex>> verts;
	//		We use a shared_ptr so it can be we can use weak_ptrs
	std::vector<Edge> edges;

	// Adjacency List where each key is a node and its value is a list of tuples (neighbor, weight)
	// Dictionary (VertexKey : List{(neighbor, weight), ...})
	std::unordered_map<std::weak_ptr<const Vertex>, std::vector<std::pair<const Vertex*, float>>> adjacencyList;
	//		We use a weak_ptr since the dictionary doesn't need to own the Vertex
};


#endif // GRAPH_H