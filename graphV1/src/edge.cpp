#include "edge.h"

// Constructor
Edge::Edge(const Vertex* from, const Vertex* to, float weight)
	: from(from), to(to), weight(weight) {}

// Used to render the vert
void Edge::render() const {
	if (!from || !to) return; // Make sure pointers are valid

	DrawLineEx(from->getPos(), to->getPos(), thickness, currentColor);
	DrawOutlinedText(TextFormat("%.f",weight), getCenterVertex().getX(), getCenterVertex().getY(), 20, 2, currentColor, BLACK);
}

void Edge::update() {}

void Edge::setWeight(float weight) {
	this->weight = weight;
}
void Edge::setColor(Color color) {
	this->currentColor = color;
}
void Edge::setThickness(float thickness) {
	this->thickness = thickness;
}
void Edge::setOutlined(bool outlined) {
	this->outlined = outlined;
}

Vertex Edge::getCenterVertex() const {
	return  Vertex((from->getX()+to->getX())/2, (from->getY()+to->getY())/2);
}
const bool& Edge::getOutlined() const {
	return outlined;
}
const Vertex* Edge::getFrom() {
	return from;
}
const Vertex* Edge::getTo() {
	return to;
}