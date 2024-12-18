#include "vertex.h"

// Constructor
Vertex::Vertex(int x, int y) : pos({static_cast<float>(x), static_cast<float>(y)}) {}

// Callback
void Vertex::setOnClickCallback(std::function<void(const Vertex*)> callback) {
	onClickCallback = callback;
}

// 
void Vertex::handleClickEvent() {
	// This if is just to ensure that it is not null
	if (onClickCallback) {
		// When we think a click has occurred on this vertex, we call the callback
		onClickCallback(this);
	}
}

// Called every frame
void Vertex::render() const {
	DrawCircle(pos.x, pos.y, radius, currentColor);
}

// Called every frame
void Vertex::update() {
	Vector2 mousePos = GetMousePosition();

	// Trigger the callback if it's isn't null 
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isHovered(mousePos)) {
		handleClickEvent();
	}

	// Just lets you move the position around
	updateDragging(mousePos);

	// updateStartEnd(mousePos); Not gonna use rn
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

// Allows you to toggle what node is the start for pathfinding
void Vertex::updateStartEnd(const Vector2& mousePos) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && isHovered(mousePos)) {
		if (isStart == false) {
			isEnd = false;
			isStart = true;
			currentColor = GREEN;
		} else if (isEnd == false ) {
			isEnd = true;
			isStart = false;
			currentColor = RED;
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