#include <iostream>
#include <string>

//Завдання 2
//Створити "Текстовий фільтр" : програма має знайти у введеному реченні заборонене слово, замінити його на зірочки та додати системний тег у кінець рядка.
//Вимоги до реалізації :
//Введення: Зчитати речення та слово - паразит через std::getline().
//Пошук слова : Використати find() для пошуку цільового слова.
//Заміна тексту : Замінити знайдене слово на * ***.
//Конкатенація : Використати оператор +=, щоб приклеїти в кінець фінального речення текст "[Відредаговано]".
//Вивести результат.

int main()
{
    std::string text;
    std::string word;

    std::cout << "Write sentence: ";
    std::getline(std::cin, text);

    std::cout << "Write banned word: ";
    std::getline(std::cin, word);

    int pos = text.find(word);

    if (pos != std::string::npos) {
        text.replace(pos, word.length(), "*banned*");
    }
    text += " [Edited]";

    std::cout << text << '\n';
}
