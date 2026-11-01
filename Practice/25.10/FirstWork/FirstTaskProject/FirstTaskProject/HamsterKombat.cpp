#include "HamsterKombat.h"
#include <iostream>

Hamster::Hamster(std::string name) : Pet(name) {}

void Hamster::Sound() {
	std::cout << "Idk balya\n";
}

void Hamster::Type() {
	std::cout << "Type: ti che slepoy?Hamster Kombat\n";
}