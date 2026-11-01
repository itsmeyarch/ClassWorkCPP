#include <iostream>
#include <vector>

class MyException : public std::exception {
public:
    MyException() = default;
    ~MyException() = default;

    const char* what() const noexcept override {
        return "custom error SOSI!";
    }

};

int main()
{
    srand(time(NULL));
    try {
        std::vector<int> vect = { 10,12,14 };
        //switch(rand() %2) {
        switch(0) {
        case 0:
            std::cout << vect.at(5) << '\n'; break;
        case 1:
            throw std::exception("some exception!");
        }
    }
    catch (const std::out_of_range& e) {
        std::cout << "out of range block" << '\n';
        std::cout << e.what() << '\n';
    }

    catch (const std::exception& e) {
        std::cout << "first block" << '\n';
        std::cout << e.what() << '\n';
    }

    catch (...) {
        std::cout << "unknown error balya!" << '\n';
    }
}