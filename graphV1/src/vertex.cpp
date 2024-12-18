#include "vertex.h"

// Constructors
Vertex::Vertex(int x, int y) : pos({static_cast<float>(x), static_cast<float>(y)}) {}

// Used to render the vert
void Vertex::render() const {
	DrawCircle(pos.x, pos.y, radius, RAYWHITE);
}

// Used to update info about it every tick
void Vertex::update() {
	Vector2 mousePos = GetMousePosition();
	updateDragging(mousePos);
}

// Doesn't modify state or mousePos
bool Vertex::isHovered(const Vector2& mousePos) const {
	// Is the mouse within a certain distance
	float radius = 10.f;
	return CheckCollisionPointCircle(mousePos, pos, radius);
}

// Modifies state but doesn't modify mousePos
void Vertex::updateDragging(const Vector2& mousePos) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isHovered(mousePos)) {
		isDragging = true;
	}
	if (isDragging) {
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			pos = mousePos;
		} else {
			isDragging = false; // letting go of it
		}
	}
}


void Vertex::setPos(int x, int y) {
	this->pos.x=x;
	this->pos.y=y;
}

void Vertex::setRad(int radius) {
	this->radius = radius;
}

Vector2 Vertex::getPos() const {
	return pos;
}

int Vertex::getX() const {
	return pos.x;
}
int Vertex::getY() const {
	return pos.y;
}