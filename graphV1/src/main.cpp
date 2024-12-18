#include <iostream>
#include "main_render.h"
#include "random.h"
#include "obj_manager.h"

int main() {
	// The object manager
	ObjMan manager;

	// The main graph
	Graph& graph = manager.getGraph();

	for (int i = 0; i < 6; i++) {
		graph.addVertex(Random::getRandomInt(0, 800), Random::getRandomInt(0, 450));
	}

	// Iteration with shrinking loops to avoid duplicates
	const auto& verts = graph.getVerts();
	for (int i = 0; i < verts.size(); ++i) {
		for (int j = i + 1; j < verts.size(); ++j) {
			if(Random::getRandomInt(0,1)) {
				Vertex* v1 = verts[i].get();
				Vertex* v2 = verts[j].get();

				graph.addEdge(v1, v2, Random::getRandomInt(1,5));
			}
		}
	}

	graph.printInfo();
	
	// Calls all necessary game loop shit
	mainGameLoop(manager);

	// Meows back to the computer
	return 0;
}