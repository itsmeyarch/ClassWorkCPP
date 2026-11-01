#include <iostream>
#include <string>
#include "MyException.h"

void CheckPasswd(std::string password) {
    bool hasDigit = false;

    if (password.length() < 8) {
        throw MyException();
    }

    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = true;
        }
    }

    if (!hasDigit) {
        throw MyException();
    }
}
int main()
{
    std::string password = "helonah312313";

    try {
        CheckPasswd(password);
        std::cout << "Password is correct nah!\n";
    }
    catch (const MyException& e) {
        std::cout << "First block nah!\n";
        std::cout << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Invalid Error!";
    }
}