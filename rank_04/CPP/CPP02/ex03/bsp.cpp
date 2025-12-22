#include "Point.hpp"

/*
** Calculate the sign of the cross product of vectors (p1->p2) and (p1->point)
** This tells us which side of the line p1-p2 the point is on
*/
static Fixed sign(Point const p1, Point const p2, Point const point) {
	return (p1.getX() - point.getX()) * (p2.getY() - point.getY()) -
	       (p2.getX() - point.getX()) * (p1.getY() - point.getY());
}

/*
** BSP (Binary Space Partitioning) - checks if point is inside triangle abc
** Returns true if point is strictly inside (not on edges or vertices)
** Returns false if point is on edge, on vertex, or outside
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1, d2, d3;
	bool has_neg, has_pos;

	// Calculate cross products for each edge
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	// Check if any cross product is zero (point on edge or vertex)
	if (d1.toFloat() == 0 || d2.toFloat() == 0 || d3.toFloat() == 0)
		return false;

	// Check if all cross products have the same sign
	has_neg = (d1.toFloat() < 0) || (d2.toFloat() < 0) || (d3.toFloat() < 0);
	has_pos = (d1.toFloat() > 0) || (d2.toFloat() > 0) || (d3.toFloat() > 0);

	// If both positive and negative signs exist, point is outside
	return !(has_neg && has_pos);
}
