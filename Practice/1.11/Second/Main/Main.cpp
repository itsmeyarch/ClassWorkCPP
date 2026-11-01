#include <iostream>
#include "Shape.h"
#include "Circle.h"

int main()
{
	Circle circle(1);

	Shape* shape = static_cast<Shape*>(&circle);

	Circle* circlep = static_cast<Circle*>(shape);

	std::cout << "Perimetr: " << circlep->GetP() << '\n';

}
