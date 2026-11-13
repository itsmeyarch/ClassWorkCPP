#pragma once
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int quantity;
    int pages;

public:
    explicit Book(const std::string& author, const std::string& title,
        const std::string& publisher, int year, int quantity, int pages);

    std::string getAuthor() const;
    std::string getPublisher() const;
    int getYear() const;

    void Print() const;
};