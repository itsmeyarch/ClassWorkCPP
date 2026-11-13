#include <iostream>
#include "Time.h"

int main() {
    Time t1, t2;

    std::cout << "Enter first time (HH:MM:SS): ";
    std::cin >> t1;

    std::cout << "Enter second time (HH:MM:SS): ";
    std::cin >> t2;

    std::cout << "\nFirst time: " << t1 << "\n";
    std::cout << "Second time: " << t2 << "\n";

    Time t3 = t1 + t2;
    std::cout << "Addition: " << t3 << "\n";

    Time t4 = t1 - t2;
    std::cout << "Subtraction: " << t4 << "\n";
}