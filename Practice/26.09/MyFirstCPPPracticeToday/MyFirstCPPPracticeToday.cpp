#include <iostream>
#include <string>
#include <ctime>
#include "Book.h"
#include "Worker.h"

int main() {
    // Task 1

    Book books[] = {
        Book("Golly Jackson", "Five Will Survive", "Readberry", 2024, 1000, 448),
        Book("Karen M McManus", "One of Us Is Lying", "Knigolove", 2018, 800, 384),
        Book("Natalia D. Richards", "Five Total Strangers", "Ranok", 2024, 500, 352),
        Book("Jennifer Lynn Barnes", "The Inheritance Games", "Vivat", 2024, 1200, 416)
    };

    int bookCount = sizeof(books) / sizeof(books[0]);

    std::string author = "Golly Jackson";
    std::string publisher = "Knigolove";
    int year = 2018;

    std::cout << "Books by " << author << ":\n";

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getAuthor() == author) {
            books[i].Print();
        }
    }

    std::cout << "Books published by " << publisher << ":\n";

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getPublisher() == publisher) {
            books[i].Print();
        }
    }

    std::cout << "Books published after " << year << ":\n";

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getYear() > year) {
            books[i].Print();
        }
    }

    // Task 2

    Worker workers[] = {
        Worker("John Smith", "Manager", 2015, 30000),
        Worker("Alice Brown", "Developer", 2020, 25000),
        Worker("Michael Wilson", "Designer", 2018, 22000),
        Worker("Emma Davis", "Developer", 2012, 35000)
    };

    int workerCount = sizeof(workers) / sizeof(workers[0]);

    std::time_t now = std::time(nullptr);
    std::tm* currentTime = std::localtime(&now);
    int currentYear = currentTime->tm_year + 1900;

    int experience = 5;
    double salary = 25000;
    std::string position = "Developer";

    std::cout << "\nWorkers with more than " << experience << " years of experience:\n";

    for (int i = 0; i < workerCount; i++) {
        if (currentYear - workers[i].getHireYear() > experience) {
            workers[i].Print();
        }
    }

    std::cout << "Workers with salary greater than " << salary << ":\n";

    for (int i = 0; i < workerCount; i++) {
        if (workers[i].getSalary() > salary) {
            workers[i].Print();
        }
    }

    std::cout << "Workers with position " << position << ":\n";

    for (int i = 0; i < workerCount; i++) {
        if (workers[i].getPosition() == position) {
            workers[i].Print();
        }
    }
}