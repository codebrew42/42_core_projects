#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const _x;
	Fixed const _y;

public:
	// Default constructor
	Point();

	// Constructor with two floats
	Point(const float x, const float y);

	// Copy constructor
	Point(const Point& other);

	// Copy assignment operator
	Point& operator=(const Point& other);

	// Destructor
	~Point();

	// Getters (useful for BSP)
	Fixed getX() const;
	Fixed getY() const;
};

#endif
