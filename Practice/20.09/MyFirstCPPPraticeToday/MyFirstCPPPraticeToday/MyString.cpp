#include "MyString.h"
#include <cstring>

MyString::MyString() {
	str = nullptr;
	lenght = 0;
}

MyString::MyString(const char* str) {
	lenght = strlen(str);

	this->str = new char[lenght + 1];
	strcpy_s[this->str, lenght + 1, str];
}