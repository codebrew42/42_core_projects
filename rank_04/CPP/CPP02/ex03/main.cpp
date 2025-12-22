#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printTest(const char* description, bool result, bool expected) {
	std::cout << description << ": ";
	if (result == expected)
		std::cout << "\033[32m✓ PASS\033[0m";
	else
		std::cout << "\033[31m✗ FAIL\033[0m";
	std::cout << " (result: " << (result ? "inside" : "outside") << ")" << std::endl;
}

int main(void) {
	std::cout << "=== BSP (Binary Space Partitioning) Tests ===" << std::endl;
	std::cout << std::endl;

	// Define a triangle: (0,0), (10,0), (5,10)
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "  A(0, 0)" << std::endl;
	std::cout << "  B(10, 0)" << std::endl;
	std::cout << "  C(5, 10)" << std::endl;
	std::cout << std::endl;

	// Test 1: Point clearly inside
	Point inside(5.0f, 5.0f);
	printTest("Point (5, 5) - Inside", bsp(a, b, c, inside), true);

	// Test 2: Point clearly outside
	Point outside(15.0f, 5.0f);
	printTest("Point (15, 5) - Outside", bsp(a, b, c, outside), false);

	// Test 3: Point on vertex A
	Point onVertexA(0.0f, 0.0f);
	printTest("Point (0, 0) - On vertex A", bsp(a, b, c, onVertexA), false);

	// Test 4: Point on vertex B
	Point onVertexB(10.0f, 0.0f);
	printTest("Point (10, 0) - On vertex B", bsp(a, b, c, onVertexB), false);

	// Test 5: Point on vertex C
	Point onVertexC(5.0f, 10.0f);
	printTest("Point (5, 10) - On vertex C", bsp(a, b, c, onVertexC), false);

	// Test 6: Point on edge AB (midpoint)
	Point onEdgeAB(5.0f, 0.0f);
	printTest("Point (5, 0) - On edge AB", bsp(a, b, c, onEdgeAB), false);

	// Test 7: Point on edge BC
	Point onEdgeBC(7.5f, 5.0f);
	printTest("Point (7.5, 5) - On edge BC", bsp(a, b, c, onEdgeBC), false);

	// Test 8: Point on edge CA
	Point onEdgeCA(2.5f, 5.0f);
	printTest("Point (2.5, 5) - On edge CA", bsp(a, b, c, onEdgeCA), false);

	// Test 9: Another inside point
	Point inside2(6.0f, 3.0f);
	printTest("Point (6, 3) - Inside", bsp(a, b, c, inside2), true);

	// Test 10: Another outside point
	Point outside2(0.0f, 15.0f);
	printTest("Point (0, 15) - Outside", bsp(a, b, c, outside2), false);

	std::cout << std::endl;
	std::cout << "=== Additional Triangle Tests ===" << std::endl;
	std::cout << std::endl;

	// Different triangle: (0,0), (0,10), (10,0)
	Point a2(0.0f, 0.0f);
	Point b2(0.0f, 10.0f);
	Point c2(10.0f, 0.0f);

	std::cout << "Triangle 2 vertices:" << std::endl;
	std::cout << "  A(0, 0)" << std::endl;
	std::cout << "  B(0, 10)" << std::endl;
	std::cout << "  C(10, 0)" << std::endl;
	std::cout << std::endl;

	Point inside3(2.0f, 2.0f);
	printTest("Point (2, 2) - Inside", bsp(a2, b2, c2, inside3), true);

	Point outside3(6.0f, 6.0f);
	printTest("Point (6, 6) - Outside", bsp(a2, b2, c2, outside3), false);

	return 0;
}
