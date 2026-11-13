#include "MyString.h"
#include <cstring>

MyString::MyString()
{
    str = nullptr;
    length = 0;
}

MyString::MyString(const char* str)
{
    if (str == nullptr)
    {
        this->str = nullptr;
        length = 0;
    }
    else
    {
        length = strlen(str);

        this->str = new char[length + 1];
        strcpy(this->str, str);
    }
}

MyString::MyString(const MyString& other)
{
    length = other.length;

    if (other.str == nullptr)
    {
        str = nullptr;
    }
    else
    {
        str = new char[length + 1];
        strcpy(str, other.str);
    }
}

MyString::~MyString()
{
    delete[] str;
}

int MyString::getLength() const
{
    return length;
}

const char* MyString::c_str() const
{
    return str;
}