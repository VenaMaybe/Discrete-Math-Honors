#include "obj_manager.h"

// Constructor
ObjMan::ObjMan() {
	// Initialize the graph if needed (default constructor is called automatically)
}

// Getter for the graph
Graph& ObjMan::getGraph() {
	return graph;
}

// Render chain
void ObjMan::render() const {
	graph.render();
}

void ObjMan::update() {
	graph.update();
}