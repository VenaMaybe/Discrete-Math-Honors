#ifndef OBJ_MANAGER_H
#define OBJ_MANAGER_H

#include "graph.h"
#include "graph_interaction_manager.h"

class ObjMan {
private:
	Graph graph; // Member variable to store the Graph
	GraphInteractionManager interactionManager;

public:
	ObjMan();
	void render() const;
	void update();

	// Getter for the graph
	Graph& getGraph(); // Returns a reference to allow modification of the graph
};

#endif // OBJ_MANAGER_H
