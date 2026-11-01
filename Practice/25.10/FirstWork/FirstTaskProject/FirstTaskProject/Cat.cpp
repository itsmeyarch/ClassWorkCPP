#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name) : Pet(name) {}

void Cat::Sound() {
	std::cout << "Meow balya\n";
}

void Cat::Type() {
	std::cout << "Type: ti che slepoy?CAT\n";
}