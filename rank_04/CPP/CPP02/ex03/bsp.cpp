#include "Point.hpp"

/*
** Calculate which side of an edge a point is on
** Returns: positive if point is on left side of edge (v1->v2)
**          negative if point is on right side
**          zero if point is on the edge itself
*/
static Fixed sideOfEdge(Point const v1, Point const v2, Point const testPoint) {
	return (v1.getX() - testPoint.getX()) * (v2.getY() - testPoint.getY()) -
	       (v2.getX() - testPoint.getX()) * (v1.getY() - testPoint.getY());
}

/*
** BSP (Binary Space Partitioning) - checks if point is inside triangle abc
** Returns true if point is strictly inside
** Returns false if point is on edge, on vertex, or outside
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed sideOfAB = sideOfEdge(a, b, point);
	Fixed sideOfBC = sideOfEdge(b, c, point);
	Fixed sideOfCA = sideOfEdge(c, a, point);

	if (sideOfAB.toFloat() == 0 || sideOfBC.toFloat() == 0 || sideOfCA.toFloat() == 0)
		return false;

	bool allPositive = (sideOfAB.toFloat() > 0 && 
						sideOfBC.toFloat() > 0 && 
						sideOfCA.toFloat() > 0);
	
	bool allNegative = (sideOfAB.toFloat() < 0 && 
						sideOfBC.toFloat() < 0 && 
						sideOfCA.toFloat() < 0);

	return allPositive || allNegative;
}