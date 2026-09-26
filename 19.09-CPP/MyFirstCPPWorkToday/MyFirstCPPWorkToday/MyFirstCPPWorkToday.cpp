#include <iostream>
#include <Windows.h>
using namespace std;

class Dog {
private:

	char* name;

	int age;

float weight;public:

	Dog(const char* nameP, int ageP, float weighP) : age(ageP), weight(weighP) {

		name = new char[strlen(nameP) + 1];

		strcpy_s(name, strlen(nameP) + 1, nameP);

	}


	~Dog() {

		if (name != nullptr) {

			delete[] name;

		}

	}


	void Bark() {

		cout << "BARK-BARK" << '\n';

	}


	const char* GetName() { return name; }

	int GetAge() { return age; }

	float GetWeight() { return weight; }

};

int main()

{

	SetConsoleOutputCP(1251);

	Dog dog = Dog("Yaroslav", 1, 24.5);

	Dog dog2 = Dog("Kaducei", 7, 65.0);
	
	cout << dog.GetName() << '\n';              

}






















