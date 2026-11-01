#pragma once
#ifndef HAMSTERKOMBAT_H
#define HAMSTERKOMBAT_H
#include "Pet.h"

class Hamster : public Pet {
public: 
	Hamster(std::string name);
	void Sound() override;
	void Type() override;
};

#endif