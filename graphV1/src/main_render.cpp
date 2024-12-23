#include "main_render.h"
#include "random.h"


void mainGameLoop(ObjMan& objMan) {
	// Don't want INFO logs
	SetTraceLogLevel(LOG_WARNING);

	// Initialize the window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Graph Plotter v1");
	SetTargetFPS(30);
	
	// Main game loop
	while (!WindowShouldClose()) { // Detect window close button or ESC key
		// Start drawing
		BeginDrawing();
		ClearBackground(BLACK);

		// My Draw Function
		objMan.render();
		objMan.update();

		// End drawing
		EndDrawing();
	}

	// Close window and OpenGL context
	CloseWindow();
}