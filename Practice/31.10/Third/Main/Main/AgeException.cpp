#include "AgeException.h"

AgeException::AgeException(int age) {
	this->age = age;
}

const char* AgeException::what() const noexcept {
	return "Age less than 18 you can not vote!";
}
