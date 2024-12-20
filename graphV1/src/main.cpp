#include <iostream>
#include "main_render.h"
#include "random.h"
#include "obj_manager.h"

int main() {
	// The object manager
	ObjMan manager;

	// The main graph
	Graph &graph = manager.getGraph();

//	for (int i = 0; i < 6; i++) {
//		graph.addVertex(Random::getRandomInt(0, 800), Random::getRandomInt(0, 450));
//	}
//
//	// Iteration with shrinking loops to avoid duplicates
//	const auto& verts = graph.getVerts();
//	for (int i = 0; i < verts.size(); ++i) {
//		for (int j = i + 1; j < verts.size(); ++j) {
//			if(Random::getRandomInt(0,1)) {
//				Vertex* v1 = verts[i].get();
//				Vertex* v2 = verts[j].get();
//
//				graph.addEdge(v1, v2, Random::getRandomInt(1,5));
//			}
//		}
//	}


	// We'll create a layered structure:
	// 1. A single start vertex at a known position
	// 2. Several "layers" of vertices, each placed at increasing x positions
	//    and spaced along the y-axis.
	// 3. A single end vertex at the final layer position

	// You can adjust these values to tweak the layout


	int numLayers = 4;        // number of intermediate layers
	int minPerLayer = 4;
	int maxPerLayer = 4;
	int layerSpacingX = 100;  // distance between layers horizontally
	int vertexSpacingY = 60;  // vertical spacing between vertices
	int startX = 50;
	int startY = 450/2;         // starting point for the top vertex in a layer

	// Start vertex at a known position
	Vertex* start = graph.addVertex((float)startX, (float)startY);
	startY -= (vertexSpacingY * (maxPerLayer-1))/2;

	// Helper lambda to create a set of vertices in a layer
	auto createLayer = [&](int layerIndex, int count) {
		std::vector<Vertex*> layer;
		
		// We'll place the layer at x = startX + (layerIndex+1)*layerSpacingX
		// Vertices in the layer will be placed vertically spaced along Y
		int baseX = startX + (layerIndex + 1) * layerSpacingX;
		
		for (int i = 0; i < count; i++) {
			float x = (float)baseX;
			float y = (float)(startY + i * vertexSpacingY);
			Vertex* v = graph.addVertex(x, y);
			layer.push_back(v);
		}
		return layer;
	};

	// Create intermediate layers
	std::vector<std::vector<Vertex*>> layers;
	for (int l = 0; l < numLayers; l++) {
		int count = Random::getRandomInt(minPerLayer, maxPerLayer);
		layers.push_back(createLayer(l, count));
	}

	// End vertex after the last layer
	int endX = startX + (numLayers + 1) * layerSpacingX;
	Vertex* end = graph.addVertex((float)endX, (float)startY + (vertexSpacingY * (maxPerLayer-1))/2);

	// Connect start to every vertex in the first layer
	for (auto v : layers[0]) {
		graph.addEdge(start, v, Random::getRandomInt(1,5));
	}

	// Connect each layer to the next layer with some randomness
	for (int i = 0; i < (int)layers.size() - 1; i++) {
		for (auto v1 : layers[i]) {
			for (auto v2 : layers[i+1]) {
				if (Random::getRandomInt(0, 1)) {
					graph.addEdge(v1, v2, Random::getRandomInt(1,5));
				}
			}
		}
	}

	// Connect every vertex in the last layer to the end vertex
	for (auto v : layers.back()) {
		graph.addEdge(v, end, Random::getRandomInt(1,5));
	}



	// Optional: If for some reason no connections were made in some spots,
	// you could ensure at least one connection per layer, but that's up to you.


	graph.printInfo();
	graph.printAdjList();
	
	// Calls all necessary game loop shit
	mainGameLoop(manager);

	// Meows back to the computer
	return 0;
}