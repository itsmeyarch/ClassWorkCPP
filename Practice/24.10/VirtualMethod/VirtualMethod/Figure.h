#pragma once
#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
	virtual double GetArea() = 0;
	virtual ~Figure() {}
};

#endif