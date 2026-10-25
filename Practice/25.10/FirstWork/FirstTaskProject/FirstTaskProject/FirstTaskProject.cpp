#include <iostream>
#include  "Dog.h"
#include  "Cat.h"
#include  "Papuga.h"
#include  "HamsterKombat.h"

int main()
{
	Dog dog("Rey");
	Cat cat("Asya");
	Papuga papuga("Vasya");
	Hamster hamsterkombat("Boss");

	dog.Show();
	dog.Type();
	dog.Sound();
	std::cout << '\n';
	cat.Show();
	cat.Type();
	cat.Sound();
	std::cout << '\n';
	papuga.Show();
	papuga.Type();
	papuga.Sound();
	std::cout << '\n';
	hamsterkombat.Show();
	hamsterkombat.Type();
	hamsterkombat.Sound();
}
