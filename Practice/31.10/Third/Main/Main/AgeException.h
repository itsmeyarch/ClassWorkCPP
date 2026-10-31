#pragma once
#ifndef AGEEXCEPTION_H
#define AGEEXCEPTION_H
#include <exception>
class AgeException : public std::exception {
private:
	int age;
public:
	AgeException(int age);
	const char* what() const noexcept override;
};

#endif
