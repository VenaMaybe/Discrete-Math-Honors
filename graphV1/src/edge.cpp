#include "edge.h"

// Constructor
Edge::Edge(const Vertex* from, const Vertex* to, float weight)
	: from(from), to(to), weight(weight) {}

// Used to render the vert
void Edge::render() const {
	if (!from || !to) return; // Make sure pointers are valid

	DrawLine(from->getX(), from->getY(), to->getX(), to->getY(), RAYWHITE);
	DrawOutlinedText(TextFormat("%.f",weight), getCenterVertex().getX(), getCenterVertex().getY(), 20, 2, RAYWHITE, BLACK);
}

void Edge::update() {}

void Edge::setWeight(float weight) {
	this->weight = weight;
}

Vertex Edge::getCenterVertex() const {
	return  Vertex((from->getX()+to->getX())/2, (from->getY()+to->getY())/2);
}
