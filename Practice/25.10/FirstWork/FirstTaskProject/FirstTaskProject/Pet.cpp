#include "Pet.h"
#include <iostream>
Pet::Pet(std::string name) {
	this->name = name;
}

void Pet::Show() {
	std::cout << "Name: " << name << '\n';
}