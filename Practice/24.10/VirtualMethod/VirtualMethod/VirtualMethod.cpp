#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

int main()
{
    int choice;

    std::cout << "Figure list\n";
    std::cout << "1. Rectangle\n";
    std::cout << "2. Circle\n";
    std::cout << "3. Triangle\n";
    std::cout << "Put your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        double width, height;
  
    std::cout << "Enter rectangle width and height: ";
    std::cin >> width >> height;

    Rectangle figure(width, height);

    std::cout << "Area: " << figure.GetArea() << '\n';
    }
    else if (choice == 2) {
        double radius;
        
        std::cout << "Enter radius: ";
        std::cin >> radius;

        Circle figure(radius);
        std::cout << "Area: " << figure.GetArea() << '\n';
    }
    else if (choice == 3) {
        double base, height;

        std::cout << "Enter triangle base and height: ";
        std::cin >> base >> height;

        Triangle figure(base, height);

        std::cout << "Area: " << figure.GetArea() << '\n';
    }
    else {
        std::cout << "Ti daun invalid choice\n";
    }

}
