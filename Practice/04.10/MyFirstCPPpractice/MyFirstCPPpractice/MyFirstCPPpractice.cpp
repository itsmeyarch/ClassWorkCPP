#include <iostream>
#include "MyString.h"

int main() {
    MyString str1("Hello world");

    std::cout << "Start string: ";
    str1.print();

    str1[0] = 'A';

    std::cout << "After change: ";
    str1.print();

    MyString str2 = str1;
    str2[0] = 'a';

    std::cout << "First string: ";
    str1.print();

    std::cout << "Copy: ";
    str2.print();

    MyString str3;
    str3 = str1;

    std::cout << "After assignment: ";
    str3.print();

    const MyString str4("Constant string");

    std::cout << "Const string: " << str4[0] << '\n';
}