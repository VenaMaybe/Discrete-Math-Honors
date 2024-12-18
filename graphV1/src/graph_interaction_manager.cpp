#include "graph_interaction_manager.h"
#include <iostream>
#include <cassert>

GraphInteractionManager::GraphInteractionManager(Graph* graph)
	: graph(graph) {}

void GraphInteractionManager::onVertexClicked(Vertex* vertex) {
	// Handle the click event
	std::cout << "Vertex clicked at position: (" << vertex->getX() << ", " << vertex->getY() << ")\n";

	// Check first if a startVertex has been selected
	if (startVertex && !endVertex) {
		vertex->setColor(RED);
		endVertex = vertex;

		// Now we get the edges from the graph
		if (graph) { // Just ensuring it exists
			auto path = graph->reconstructPath(startVertex, endVertex);

			assert(path.size() > 1);

			for (int i = 0; i < path.size() - 1; ++i) {
				const Vertex* current = path[i];
				const Vertex* next = path[i + 1];
				
				Edge* edgeBetween = graph->getEdgeBetween(current, next);

				assert(edgeBetween != nullptr);

				if (edgeBetween) { // if it exists
					edgeBetween->setColor(ORANGE);
					edgeBetween->setThickness(3.f);
				}

			}

		}


	} else if (selectingStart) {
		startVertex = vertex;
		vertex->setColor(GREEN);
		selectingStart = false; // Example state transition

		// We can propagate the shortest distances
		if (graph) {
			graph->checkShortestPathFrom(startVertex);
		} 
	}
}