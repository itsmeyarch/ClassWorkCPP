#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int a = numerator < 0 ? -numerator : numerator;
        int b = denominator;

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        if (a != 0) {
            numerator /= a;
            denominator /= a;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;

        if (denominator == 0) {
            this->denominator = 1;
        }

        simplify();
    }

    void input() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;

        std::cout << "Enter denominator: ";
        std::cin >> denominator;

        if (denominator == 0) {
            denominator = 1;
        }

        simplify();
    }

    void print() const {
        std::cout << numerator << "/" << denominator << "\n";
    }

    Fraction add(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction subtract(const Fraction& other) const {
        return *this - other;
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }

    Fraction divide(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator,
            denominator * other.numerator
        );
    }

    // Prefix decrement
    Fraction& operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

    // Postfix decrement
    Fraction operator--(int) {
        Fraction temp = *this;
        numerator -= denominator;
        simplify();
        return temp;
    }

    // Fraction - Fraction
    Fraction operator-(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    // Fraction - int
    Fraction operator-(int value) const {
        return Fraction(
            numerator - value * denominator,
            denominator
        );
    }

    // int - Fraction
    friend Fraction operator-(int value, const Fraction& fraction) {
        return Fraction(
            value * fraction.denominator - fraction.numerator,
            fraction.denominator
        );
    }
};

#endif