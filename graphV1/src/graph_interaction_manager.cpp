#include "graph_interaction_manager.h"
#include <iostream>

void GraphInteractionManager::onVertexClicked(Vertex* vertex) {
	// Handle the click event
	std::cout << "Vertex clicked at position: (" << vertex->getX() << ", " << vertex->getY() << ")\n";

	// Check first if a startVertex has been selected
	if (startVertex && !endVertex) {
		vertex->setColor(RED);
		endVertex = vertex;
	} else if (selectingStart) {
		startVertex = vertex;
		vertex->setColor(GREEN);
		selectingStart = false; // Example state transition

		// Now we get the edges from the graph



	}
}