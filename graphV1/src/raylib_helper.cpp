#include "raylib_helper.h"

void DrawOutlinedText(const char* text, int posX, int posY, int fontSize, int thickness, Color textColor, Color outlineColor) {
	// Draw the outline
	for (int dx = -thickness; dx <= thickness; dx++) {
		for (int dy = -thickness; dy <= thickness; dy++) {
			// Skip the center (main text position)
			if (dx == 0 && dy == 0) continue;

			DrawText(text, posX + dx, posY + dy, fontSize, outlineColor);
		}
	}
	// Draw the main text
	DrawText(text, posX, posY, fontSize, textColor);
}