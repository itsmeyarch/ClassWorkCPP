#include "Book.h"
#include <iostream>

Book::Book(const std::string& author, const std::string& title,
    const std::string& publisher, int year, int quantity, int pages) {
    this->author = author;
    this->title = title;
    this->publisher = publisher;
    this->year = year;
    this->quantity = quantity;
    this->pages = pages;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

void Book::Print() const {
    std::cout << "Author: " << author << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Publisher: " << publisher << "\n";
    std::cout << "Year: " << year << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Pages: " << pages << "\n\n";
}