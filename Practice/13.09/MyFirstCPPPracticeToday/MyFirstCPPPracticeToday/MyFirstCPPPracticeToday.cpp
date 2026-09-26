#include <iostream>

#define MAX_NAME_LEN 50

class Group {
private: 
    char* name = nullptr;
    int age;
public: 
    ~Group() {
        if (name != nullptr) {
            delete[] name;
        }
    }

    Group() : Group("Unknown", 0) {}

    Group(const char* initialName, int initialAge) :age(initialAge) {
        setName(initialName);
    }

    Group(const Group&)

    void setName(const char* newName) {
        if (name != nullptr) {
            delete[] name;
        }
        if (newName == nullptr) {
            newName = "Unknown";
        }
        name = new
        char[strlen(newName) + 1, newName];
        strcpy_s(name, strlen(newName) +1, newName);
    }

    void setAge(int newAge) {
        age = newAge;
    }

    const char* const getName() {
        return name;
    }
    
    int getAge() {
        return age;
    }
};


int main()
{
    
}