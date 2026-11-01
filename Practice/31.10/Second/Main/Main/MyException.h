#pragma once
#include <exception>
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
class MyException : public std::exception {
public:
    MyException() = default;
    ~MyException() = default;

    MyException(int password);
    const char* what() const noexcept override {
        return "Incorrect password!";
    }
};

#endif
