#include <iostream>

class Book {
private:
    char* author = nullptr;
    char* title = nullptr;
    char* publisher = nullptr;
    int year = 0;
    int pages = 0;
public: 
    explicit Book(const char* author, const char* title, const char* publisher, int year, int pages) {

        this->author = new char[strlen(author) + 1];
        strcpy_s(this->author, strlen(author) + 1, author);

        this->title = new char[strlen(title) + 1];
        strcpy_s(this->title, strlen(title) + 1, title);

        this->publisher = new char[strlen(publisher) + 1];
        strcpy_s(this->publisher, strlen(publisher) + 1, publisher);

        this->year = year;
        this->pages = pages;
    }

    ~Book() {
        if (author != nullptr) delete[] author;
        if (title != nullptr) delete[] title;
        if (publisher != nullptr) delete[] publisher;
    }

    Book(const Book& other) {

        author = new char[strlen(other.author) + 1];
        strcpy_s(author,strlen(other.author) +1, other.author);

        title = new char[strlen(other.title) + 1];
        strcpy_s(title, strlen(other.title) + 1, other.title);

        publisher = new char[strlen(other.publisher) + 1];
        strcpy_s(publisher, strlen(other.publisher) + 1, other.publisher);

        year = other.year;
        pages = other.pages;
    }

    const char* getAuthor() const {
        return author;
    }

    const char* getTitle() const {
        return title;
    }

    const char* getPublisher() const {
        return publisher;
    }

    int getYear() const {
        return year;
    }

    int getPages() const {
        return pages;
    }

    void PrintBook() const {
        std::cout << author << ' ' << title << ' ' << publisher << ' ' << year << ' ' << pages << '\n';
    }
};

int main()
{
    Book books[] = {
        Book("Golly Jackson", "Five Will Survive", "Readberry", 2024,448),
        Book("Karen M McManus", "One of Us Is Lying", "Knigolove", 2018,384),
        Book("Natalia D. Richards", "Five Total Strangers", "Ranok", 2024,352),
        Book("Jennifer Lynn Barnes", "The Inheritance Games", "Vivat", 2024,416)
    };

    std::cout << "Book by Golly Jackson: \n";

    for (int i = 0; i < 4; i++) {
        if (strcmp(books[i].getAuthor(), "Golly Jackson") == 0) {
            books[i].PrintBook();
        }
    }

    std::cout << "Book by Knigolove: \n";

    for (int i = 0; i < 4; i++) {
        if (strcmp(books[i].getPublisher(), "Knigolove") == 0) {
            books[i].PrintBook();
        }
    }

    std::cout << "Book after 2018: \n";

    for (int i = 0; i < 4; i++) {
        if (books[i].getYear() > 2018) {
            books[i].PrintBook();
        }
    }
}