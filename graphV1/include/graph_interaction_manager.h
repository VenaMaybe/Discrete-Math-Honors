#ifndef GRAPH_INTERACTION_MANAGER_H
#define GRAPH_INTERACTION_MANAGER_H

/* This should control the UI for selecting start and end points for shortest graph */

#include "vertex.h"

class GraphInteractionManager {
public:
	void onVertexClicked(Vertex* vertex);
	
	void setSelectingStart(bool selecting) {
		selectingStart = selecting;
	}

private:
	const Vertex* startVertex = nullptr; // For pathing
	const Vertex* endVertex = nullptr; // 
	
	bool selectingStart = true;
};




#endif // GRAPH_INTERACTION_MANAGER_H