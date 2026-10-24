#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Figure.h"

class Triangle : public Figure {
private:
	double base;
	double height;
public:
	Triangle(double base, double height);
	double GetArea() override;
};

#endif
