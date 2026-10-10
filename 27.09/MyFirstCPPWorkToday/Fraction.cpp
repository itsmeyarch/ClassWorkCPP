#include "Fraction.h"
#include <iostream>
#include <cmath>


namespace {
	int getGCD(int a, int b) {
		a = std::abs(a);
		b = std::abs(b);
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return (a == 0) ? 1 : a;
	}
	void simplifyFraction(int& num , int& denom) {
		if (denom = 0) return;
		
		int gcd = getGCD(num, denom);
		num /= gcd;
		denom /= gcd;

		if (denom < 0) {
			num = -num;
			denom = -denom;
		}
	}
}

Fraction::Fraction(int num, int denom) 
	: numerator(num) , denominator(denom == 0 ? 1 : denom)
{ 
	if (denom == 0) {
		std::cout << "Denominator cannot be zero. Setting to 1." << '\n';
	}

	simplifyFraction(numerator, denominator);
}

Fraction Fraction::add(const Fraction& f1, const Fraction& f2) {
	int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	int denom = f1.denominator * f2.denominator;

	return Fraction(num, denom);
}

Fraction Fraction::operator+(const Fraction& right)  const{
	int num = this->numerator * right.denominator + right.numerator * this->denominator;
	int denom = this->denominator * right.denominator;

	return Fraction(num, denom);
}