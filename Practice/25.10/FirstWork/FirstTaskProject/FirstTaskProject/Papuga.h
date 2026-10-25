#pragma once
#ifndef PAPUGA_H
#define PAPUGA_H
#include "Pet.h"
class Papuga : public Pet
{
public:
	Papuga(std::string name);
		void Sound() override;
		void Type() override;
};

#endif