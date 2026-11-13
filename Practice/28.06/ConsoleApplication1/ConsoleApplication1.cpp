#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void task1()
{
    std::ifstream input("input.txt");
    std::ofstream output("task1.txt");

    std::string word;

    if (!input.is_open() || !output.is_open())
    {
        std::cout << "File error\n";
        return;
    }

    while (input >> word)
    {
        if (word.length() >= 7)
            output << word << " ";
    }

    input.close();
    output.close();

    std::cout << "Task 1 completed\n";
}

void task2()
{
    std::ifstream input("input.txt");
    std::ofstream output("task2.txt");

    std::string line;

    if (!input.is_open() || !output.is_open())
    {
        std::cout << "File error\n";
        return;
    }

    while (std::getline(input, line))
        output << line << "\n";

    input.close();
    output.close();

    std::cout << "Task 2 completed\n";
}

void task3()
{
    std::ifstream input("input.txt");
    std::ofstream output("task3.txt");

    std::vector<std::string> lines;
    std::string line;

    if (!input.is_open() || !output.is_open())
    {
        std::cout << "File error\n";
        return;
    }

    while (std::getline(input, line))
        lines.push_back(line);

    for (int i = static_cast<int>(lines.size()) - 1; i >= 0; i--)
        output << lines[i] << "\n";

    input.close();
    output.close();

    std::cout << "Task 3 completed\n";
}

void task4()
{
    std::ifstream input("input.txt");
    std::ofstream output("task4.txt");

    std::vector<std::string> lines;
    std::string line;
    int position = -1;

    if (!input.is_open() || !output.is_open())
    {
        std::cout << "File error\n";
        return;
    }

    while (std::getline(input, line))
    {
        lines.push_back(line);

        if (line.find(' ') == std::string::npos)
            position = static_cast<int>(lines.size()) - 1;
    }

    for (int i = 0; i < static_cast<int>(lines.size()); i++)
    {
        output << lines[i] << "\n";

        if (i == position)
            output << "------------\n";
    }

    if (position == -1)
        output << "------------\n";

    input.close();
    output.close();

    std::cout << "Task 4 completed\n";
}

int main()
{
    int choice;

    do
    {
        std::cout << "\n1. Copy words with at least 7 letters\n";
        std::cout << "2. Copy lines in the same order\n";
        std::cout << "3. Copy lines in reverse order\n";
        std::cout << "4. Add a line of dashes\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose task: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 0:
            std::cout << "Exit\n";
            break;
        default:
            std::cout << "Wrong choice\n";
        }

    } while (choice != 0);
}