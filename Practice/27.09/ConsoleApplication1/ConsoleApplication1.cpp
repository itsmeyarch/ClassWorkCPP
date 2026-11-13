#include <iostream>
#include "Fraction.h"

int main() {
    Fraction a(3, 4);
    Fraction b(1, 2);

    std::cout << "Fraction - Fraction: ";
    (a - b).print();

    std::cout << "Fraction - int: ";
    (a - 1).print();

    std::cout << "int - Fraction: ";
    (2 - a).print();

    std::cout << "\nPrefix decrement:\n";
    (--a).print();

    std::cout << "Postfix decrement:\n";
    (a--).print();

    std::cout << "After postfix decrement:\n";
    a.print();
}