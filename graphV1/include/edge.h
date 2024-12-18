#ifndef EDGE_H
#define EDGE_H

#include "raylib.h"
#include "vertex.h"
#include "raylib_helper.h"

// A vertex of the graph
class Edge {
public:
	// Constructors
	Edge() = default;
	Edge(const Vertex* from, const Vertex* to, float weight = 0.f);
	// Render & update
	void render() const;
	void update();
	
	void setWeight(float weight);
	Vertex getCenterVertex() const;
private:
	// We set these as const to enforce read-only behavior
	//		Edge only observes the vertices. Edges cannot change their connected vertices
	const Vertex* from = nullptr;
	const Vertex* to = nullptr;
	// make these std::weak_ptr so no dangling ptrs


	float weight = 0.f;
};

#endif // EDGE_H