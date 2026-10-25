#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name) : Pet(name) {}

void Dog::Sound() {
	std::cout << "Gav balya\n";
}

void Dog::Type() {
	std::cout << "Type: ti che slepoy?DOG\n";
}