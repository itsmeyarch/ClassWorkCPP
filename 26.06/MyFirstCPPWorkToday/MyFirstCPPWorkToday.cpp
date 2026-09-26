#include <iostream>

enum Breed {
	Maincoon, Siamese, Sphynx
};

class Cat {
private: 
	char* name = nullptr;
	int age;
	const Breed breed;
	mutable int getNameCounter = 0;
public:
	Cat(const char* name, int age , Breed breed) : age(age), breed(breed) {
		if (name != nullptr) {
			int nameSize = strlen(name) + 1;
			this->name = new char[nameSize];
			strcpy_s(this->name, nameSize, name);
		}
	}
	Cat(const Cat& other) : age(other.age) , breed(breed) {
		if (other.name != nullptr) {
			int nameSize = strlen(other.name) + 1;
			name = new char[nameSize];
			strcpy_s(name, nameSize, other.name);
		}
	}
	~Cat() {
		if (name != nullptr) delete[] name;
	}

	char* getName() const { getNameCounter++; return name; }
	int getAge() const { return age; }

	void setName(const char* newName) {
		if (name != nullptr) delete[] name;  
		if (newName != nullptr) {
			int nameSize = strlen(newName) + 1;
			name = new char[nameSize] + 1;
			strcpy_s(name, nameSize, newName);
		}
	}

	void setAge(int newAge) {
		age = newAge > age ? newAge : age;
	}
};

void PrintCat(Cat cat) {
		std::cout << cat.getName() << ' ' << cat.getAge() << "y.o.\n";
	}
int main()
{
	const Cat cat = Cat("Cat1", 10, Breed::Sphynx);
	//char* name = cat.getName();

	//name[1] = 'C';

	//std::cout << cat.getName() << '\n';
	//PrintCat(cat);
}
