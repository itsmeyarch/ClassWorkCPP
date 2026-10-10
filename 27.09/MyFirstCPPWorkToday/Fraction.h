#pragma once
class Fraction
{
private: 
	int numerator;
	int denominator;
public: 
	Fraction(int num, int denom);


	static Fraction add(const Fraction& f1, const Fraction& f2);

	Fraction operator+(const Fraction& other) const;
};

