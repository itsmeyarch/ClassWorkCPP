#include "Papuga.h"
#include <iostream>

Papuga::Papuga(std::string name) : Pet(name) {}



void Papuga::Sound() {
	std::cout << "Hz balya\n";
}

void Papuga::Type() {
	std::cout << "Type: ti che slepoy?Papuga\n";
}