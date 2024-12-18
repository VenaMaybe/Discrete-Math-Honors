#include "obj_manager.h"

// Constructor
ObjMan::ObjMan() 
	: graph(&graphInteractionManager), // We link them together
	  graphInteractionManager(&graph) {}

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