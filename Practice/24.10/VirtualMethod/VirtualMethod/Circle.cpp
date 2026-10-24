#include "Circle.h"

Circle::Circle(double radius) {
	this->radius = radius;
}

double Circle::GetArea() {
	const double PI = 3.14;
	return PI * radius * radius;
}