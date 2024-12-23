#ifndef MAIN_RENDER_H
#define MAIN_RENDER_H

#include "raylib.h"
#include "obj_manager.h"

// Constants for screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

// Raylib preamble
void mainGameLoop(ObjMan& objMan);

#endif // MAIN_RENDER_H