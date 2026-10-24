#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
class Rectangle : public Figure {
private:
	double width;
	double height;
public:
	Rectangle(double width, double height);
	double GetArea() override;
};

#endif
