#include <iostream>
#include<string>
#include "AgeException.h"

void vote(std::string candidate, int age) {
	if (age < 18) {
		throw AgeException(age);
	}

	std::cout << candidate << " Can vote POTUGNO NAH!\n";
}

int main() {
	std::string candidate("Yaroslav");
	int age = 15;
	//int age = 18;

	try {
		vote(candidate, age);
	}
	catch (const AgeException& e) {
		//std::cout << "First Block nah!\n";
		std::cout << e.what() << '\n';
	}
	catch (...) {
		std::cout << "Unknown Error Nah!";
	}
}