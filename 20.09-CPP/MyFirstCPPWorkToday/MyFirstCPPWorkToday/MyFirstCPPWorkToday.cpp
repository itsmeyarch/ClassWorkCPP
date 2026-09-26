#include <iostream>

using namespace std;

class Book {
private:
    char* title = nullptr;
    char* author = nullptr;
    int pages = 0;
public:
    Book(const char* title, const char* author, int pages) : pages(pages) {
        int titleSize = strlen(title) + 1;
        int authorSize = strlen(author) + 1;

        this->title = new char[titleSize];
        strcpy_s(this->title, titleSize, title);

        this->author = new char[authorSize];
        strcpy_s(this->author, authorSize, author);
    }
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy_s(title, strlen(other.title) + 1, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy_s(author, strlen(other.author) + 1, other.author);

        this->pages = other.pages;
    }

    const char* getTitle() const {
        return title;
    }
    const char* getAuthor() const {
        return author;
    }
    int getPage() const {
        return pages;
    }

    ~Book() {
        if (title != nullptr) {
            delete[] title;
        }
        if (author != nullptr) {
            delete[] author;
        }
    }

    void PrintBook(Book book) {
        cout << book.getTitle()
            << "By: " << book.getAuthor() << '\n';
    }

    Book CreateBook() {
        Book book = Book("Dead Animales", "Neznay", 600);
        return book;
    }

    void setTitle(const char* newTitle) {
        if (title != nullptr) delete[] title;
            title = new char[strlen(newTitle) + 1];
            strcpy_s(title, strlen(newTitle) + 1, newTitle);
    }

        void setAuthor(const char* newAuthor) {
            if (author != nullptr) delete[] author;
                author = new char[strlen(newAuthor) + 1];
                strcpy_s(author, strlen(newAuthor) + 1, newAuthor);
      }
};

int main()
{
    Book book = Book("Dead Animales", "HZ", 600);
    Book book2 = book;
    //PrintBook(book);
}
