#include <iostream>
#include <string>
#include <stdexcept>

int toInt(const std::string& s) {
    size_t pos;
    int number = std::stoi(s, &pos);

    if (pos != s.length()) {
        throw
            std::invalid_argument("String is not a number loshara!");
    }

    return number;
}

int main()
{
    std::string s = "123131232132131abc";

    try {
        std::cout << toInt(s) << '\n';
    }
    catch (const std::invalid_argument& s) {
        std::cout << "Invalid argument block" << '\n';
        std::cout << s.what() << '\n';
    }
    catch (const std::out_of_range& s) {
        std::cout << "Out of range block\n";
        std::cout << s.what() << '\n';
    }
    catch (...) {
        std::cout << "UNKNOWN ERROR LOSHARA!";
    }
}