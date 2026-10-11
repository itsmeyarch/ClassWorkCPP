#include <iostream>
#include <string>

//Завдання 1
//Написати програму для розбору електронної пошти на ім'я користувача та домен.
//Вимоги до реалізації :
//Введення: Використати std::getline(std::cin, email) для безпечного зчитування рядка з консолі.
//Пошук символу : Використати метод find('@').Обов'язково перевірити результат на std::string::npos.
//Виведення : Вивести ім'я користувача та домен окремими рядками.

int main()
{
    std::string email;

    std::cout << "Put email: ";
    std::getline(std::cin, email);

    int pos = email.find('@');

    if (pos != std::string::npos) {
        std::string name = email.substr(0, pos);
        std::string domain = email.substr(pos + 1);

        std::cout << "Username: " << name << '\n';
        std::cout << "Domain: " << domain << '\n';
    }
    else {
        std::cout << "Incorrect Email\n";
    }
}
