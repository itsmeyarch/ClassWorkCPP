
#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;

        do {
            cout << "Enter denominator: ";
            cin >> denominator;

            if (denominator == 0) {
                cout << "Denominator cannot be zero!\n";
            }
        } while (denominator == 0);
    }

    void simplify() {
        int gcdValue = gcd(abs(numerator), abs(denominator));

        numerator /= gcdValue;
        denominator /= gcdValue;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void display() {
        cout << numerator << "/" << denominator << '\n';
    }

    Fraction add(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.denominator +
            other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction subtract(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.denominator -
            other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction multiply(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction divide(Fraction other) {
        Fraction result;

        if (other.numerator == 0) {
            cout << "Division by zero is impossible!\n";
            return result;
        }

        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.simplify();
        return result;
    }
};

int main() {
    Fraction first, second, result;

    cout << "Enter first fraction:\n";
    first.input();

    cout << "\nEnter second fraction:\n";
    second.input();

    cout << "\nFirst fraction: ";
    first.display();

    cout << "Second fraction: ";
    second.display();

    cout << "\nAddition: ";
    result = first.add(second);
    result.display();

    cout << "Subtraction: ";
    result = first.subtract(second);
    result.display();

    cout << "Multiplication: ";
    result = first.multiply(second);
    result.display();

    cout << "Division: ";
    result = first.divide(second);
    result.display();

}
