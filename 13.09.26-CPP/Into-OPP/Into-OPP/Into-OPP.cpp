#include <iostream>

#define MAX_NAME_LEN 50

class Monkey {
private:
    char* name = nullptr; //[MAX_NAME_LEN];
    int age;
public:

    ~Monkey() {
        std::cout << name << " died :(" << '\n';
    }

    Monkey() : Monkey("Mac-Junior", 9) {
        //setName("Mac-Junior");
        //setAge(9);
    }

    Monkey(const char* initialName, int initialAge) : age(initialAge) {
        setName(initialName);
        //setAge(initialAge);
    }

    void setName(const char* newName) {
        if (newName == nullptr)
        {
            strcpy_s(name, strlen("Mac-Junior") + 1, "Mac-Junior");
        }
        else
        {
            if (name != nullptr) {
                delete[] name;
            }
        }
        name = new char[strlen(newName) + 1];
        strcpy_s(name, MAX_NAME_LEN, newName);
    }
    void setAge(int newAge) {
        age = age < newAge ? newAge : age;
    }

    const char* const getName() { return name; }
    int getAge() { return age; }
};

int main()
{
    Monkey monkey1 = Monkey("MacChiken-burge",46);
    //monkey1.setName("Yarik");
    Monkey monkey2;

    std::cout << monkey1.getName() << '\n';
    std::cout << monkey1.getAge() << '\n';

    std::cout << monkey2.getName() << '\n';
    std::cout << monkey2.getAge() << '\n';


    Monkey* dynamicMonkey = new Monkey("Double Cheezburge", 13);
    delete[] dynamicMonkey;
    Monkey* monkeys = new Monkey[3];

    for (int i = 0; i < 3; i++) {
        std::cout << monkeys[i].getName() << ' ' << monkeys[i].getAge() << '\n';
    }

    delete[] monkeys;

}
