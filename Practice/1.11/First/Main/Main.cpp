#include <iostream>

//Завдання 1.
//Написати функцію, що приймає double і повертає int, використовуючи static_cast.

int convert(double number) {
    return static_cast<int>(number);
}


int main()
{
    double number = 14.15;

    int result = convert(number);

    std::cout << result << '\n';
}

