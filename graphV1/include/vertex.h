#ifndef VERTEX_H
#define VERTEX_H

#include "raylib.h"
#include <functional>

// A vertex of the graph
class Vertex {
public:
	// Constructors
	Vertex() = default;
	Vertex(int x, int y);

	// Render this vertex
	void render() const;

	// Update realtime info about it (pos w/ mouse)
	void update();

	// Getters and Setters
	Vector2 getPos() const;
	int getX() const;
	int getY() const;
	void setRad(int radius);
	void setPos(int x, int y);

	// Equality operator for Vertex
	bool operator==(const Vertex& other) const;
private:
	// UTIL: Is the mouse within a certain distance? 
	bool isHovered(const Vector2& mousePos) const;
	void updateDragging(const Vector2& mousePos);

	// Rendering
	Vector2 pos = {0, 0};
	int radius = 10;

	// Updating
	bool isDragging;

	// Grant access to the hash specialization
	friend struct std::hash<Vertex>;
};

// From chatgpt
// Hash specialization for Vertex (needed for std::unordered_map)
namespace std {
	template <>
	struct hash<Vertex> {
		std::size_t operator()(const Vertex& v) const {
			// Combine the hashes of `x`, `y`, and `radius`
			std::size_t h1 = std::hash<int>()(v.pos.x);
			std::size_t h2 = std::hash<int>()(v.pos.y);
			std::size_t h3 = std::hash<int>()(v.radius);
			return h1 ^ (h2 << 1) ^ (h3 << 2); // Combine with bitwise shifts and XOR
		}
	};
}

#endif // VERTEX_H