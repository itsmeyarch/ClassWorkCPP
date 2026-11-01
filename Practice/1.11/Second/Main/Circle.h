#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double r);
	double GetP();
};

#endif