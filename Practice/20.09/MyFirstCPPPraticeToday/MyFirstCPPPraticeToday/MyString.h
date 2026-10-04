#pragma once
class MyString
{
private:
	char* str = nullptr;
	int lenght = 0 ;
public:
	MyString();
	MyString() {
		const char* str;
	}
	MyString(MyString& other){} 

	const char* c_str() const;

	int getLen() const;

	~MyString();
};

