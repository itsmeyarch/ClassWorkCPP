#include "Circle.h"

Circle::Circle(double r) {
	radius = r;
}

double Circle::GetP() {
	return 2 * 3.14 * radius;
}