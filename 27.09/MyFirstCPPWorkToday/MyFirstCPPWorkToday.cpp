#include <iostream>
#include "Fraction.h"

class Box {
private:
    int width;
public:
    explicit Box(int w) : width(w) {
        std::cout << "Box created with width: " << width << '\n';
    }

    friend void printWidth(const Box& b);
};

void printWidth(const Box& b) {
    std::cout << "Width of box: " << b.width << '\n';
}

int main() {
    //Box box = Box(10);
    //printWidth(box);

    Fraction f1 = Fraction(4, 7);
    Fraction f2 = Fraction(3, 7);

    //Fraction sum = Fraction::add(f1, f2);
    //Fraction sum = f1 + f2;
}