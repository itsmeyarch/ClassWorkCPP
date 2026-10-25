#pragma once
#ifndef PET_H
#define PET_H
#include <string>
class Pet
{
protected:
	std::string name;
public:
	Pet(std::string name);
	virtual void Sound() = 0;
	virtual void Show();
	virtual void Type() = 0;
	virtual ~Pet() {}
};

#endif