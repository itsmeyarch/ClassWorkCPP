#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>

class MyString {
private:
    char* data;
    size_t length;

public:
    MyString() {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }

    MyString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    ~MyString() {
        delete[] data;
    }

    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }

        delete[] data;

        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);

        return *this;
    }

    char& operator[](int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    const char& operator[](int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    void print() const {
        std::cout << data << '\n';
    }
};