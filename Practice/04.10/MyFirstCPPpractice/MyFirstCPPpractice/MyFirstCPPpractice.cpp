#include <iostream>

class MyString {
private:
	char* data;
	int lenght;
public:
	MyString() {
		lenght = 0;
		data = new char[1];
		data[0] = '\0';
	}

	MyString(const char* str) {
		lenght = 0;
		while (str[lenght] != '\0') {
			lenght++;
		}
		data = new char[lenght + 1];

		for (int i = 0; i < lenght; i++) {
			data[i] = str[i];
		}
		data[lenght] = '\0';
	}

	~MyString() {
		delete[] data;
	}

	MyString(const  MyString& other) {
		lenght = other.lenght;
		data = new char[lenght + 1];

		for (int i = 0; i < lenght;i++) {
			data[i] = other.data[i];
		}

		data[lenght] = '\0';
	}

	MyString& operator=(const MyString& other) {
		if (this == &other) {
			return *this;

			delete[] data;

			lenght = other.lenght;
			data = new char[lenght + 1];

			for (int i = 0; i < lenght; i++) {
				data[i] = other.data[i];
			}

			data[lenght] = '\0';

			return *this;
		}
	}

	char& operator[](int index) {
		if (index < 0 || index >= lenght)
			return data[index];
	}

	const char& operator[](int index) const {
		if (index < 0 || index >= lenght)
			return data[index];
	}

	void print() const {
		std::cout << data << '\n';
	}
};

int main()
{
	MyString str1("Hello world");

	std::cout << "Startove pole: ";
	str1.print();
	str1[0] = 'A';

	std::cout << "After change: ";
	str1.print();

	MyString str2 = str1;
	str2[0] = 'a';

	std::cout << "First Pole: ";
	str1.print();
		
	std::cout << "Copy: ";
	str2.print();

	MyString str3;
	str3 = str1;

	std::cout << "After  prisvoenya: ";
	str3.print();

}