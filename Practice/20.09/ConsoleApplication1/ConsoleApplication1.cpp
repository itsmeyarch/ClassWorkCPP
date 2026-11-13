#include <iostream>
#include "MyString.h"

int main()
{
    MyString first("Hello World");

    MyString second(first);

    std::cout << "First string: " << first.c_str() << "\n";
    std::cout << "Second string: " << second.c_str() << "\n";

    std::cout << "First length: " << first.getLength() << "\n";
    std::cout << "Second length: " << second.getLength() << "\n";

    MyString third;

    std::cout << "Third string length: " << third.getLength() << "\n";
}