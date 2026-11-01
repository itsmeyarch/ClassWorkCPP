#pragma once
#ifndef CAT_H
#define CAT_H
#include "Pet.h"
class Cat : public Pet
{
public:
	Cat(std::string name);
	void Sound() override;
	void Type() override;

};
#endif
