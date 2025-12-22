#include "Point.hpp"

// Default constructor - initializes x and y to 0
Point::Point() : _x(0), _y(0) {
}

// Constructor with two floats
Point::Point(const float x, const float y) : _x(x), _y(y) {
}

// Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

// Copy assignment operator
// NOTE: Since _x and _y are const, we cannot reassign them!
// This assignment operator effectively does nothing after construction
Point& Point::operator=(const Point& other) {
	// Cannot modify const members after construction
	// This is required by Orthodox Canonical Form but will not modify the object
	(void)other;  // Avoid unused parameter warning
	return *this;
}

// Destructor
Point::~Point() {
}

// Getters
Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}
