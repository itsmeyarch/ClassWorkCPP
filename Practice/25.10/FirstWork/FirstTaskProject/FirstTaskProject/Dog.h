#pragma once
#ifndef DOG_H
#define DOG_H
#include "Pet.h"
class Dog : public Pet {
public:
	Dog(std::string name);
	void Sound() override;
	void Type() override;
};

#endif