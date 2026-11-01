#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) {
	this->width = width;
	this->height = height;
}

double Rectangle::GetArea() {
	return width * height;
}