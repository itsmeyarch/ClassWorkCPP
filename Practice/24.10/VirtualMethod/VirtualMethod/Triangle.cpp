#include "Triangle.h"

Triangle::Triangle(double base, double height) {
	this->base = base;
	this->height = height;
}

double Triangle::GetArea() {
	return base * height / 2;
}