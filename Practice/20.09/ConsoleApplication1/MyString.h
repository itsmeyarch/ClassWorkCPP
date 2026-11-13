#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
private:
    char* str;
    int length;

public:
    MyString();

    MyString(const char* str);

    MyString(const MyString& other);

    ~MyString();

    int getLength() const;

    const char* c_str() const;
};

#endif