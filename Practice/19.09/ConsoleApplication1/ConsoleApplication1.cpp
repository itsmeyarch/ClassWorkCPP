#include <iostream>
#include <cstring>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 1, int month = 1, int year = 2000)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }
};

class Person
{
private:
    char* id;
    char* surname;
    char* name;
    char* patronymic;
    Date birthDate;

    static int count;

public:
    Person(const char* id, const char* surname, const char* name,
        const char* patronymic, Date birthDate)
    {
        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);

        this->surname = new char[strlen(surname) + 1];
        strcpy(this->surname, surname);

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->patronymic = new char[strlen(patronymic) + 1];
        strcpy(this->patronymic, patronymic);

        this->birthDate = birthDate;

        count++;
    }

    Person() : Person("000000", "Unknown", "Unknown", "Unknown", Date())
    {
    }

    ~Person()
    {
        delete[] id;
        delete[] surname;
        delete[] name;
        delete[] patronymic;

        count--;
    }

    static int getCount()
    {
        return count;
    }

    const char* getId()
    {
        return id;
    }

    const char* getSurname()
    {
        return surname;
    }

    const char* getName()
    {
        return name;
    }

    const char* getPatronymic()
    {
        return patronymic;
    }

    Date getBirthDate()
    {
        return birthDate;
    }

    Person& setId(const char* id)
    {
        delete[] this->id;

        this->id = new char[strlen(id) + 1];
        strcpy(this->id, id);

        return *this;
    }

    Person& setSurname(const char* surname)
    {
        delete[] this->surname;

        this->surname = new char[strlen(surname) + 1];
        strcpy(this->surname, surname);

        return *this;
    }

    Person& setName(const char* name)
    {
        delete[] this->name;

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        return *this;
    }

    Person& setPatronymic(const char* patronymic)
    {
        delete[] this->patronymic;

        this->patronymic = new char[strlen(patronymic) + 1];
        strcpy(this->patronymic, patronymic);

        return *this;
    }

    Person& setBirthDate(Date birthDate)
    {
        this->birthDate = birthDate;
        return *this;
    }

    void showInfo()
    {
        std::cout << "\nID: " << id << "\n";
        std::cout << "Surname: " << surname << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Patronymic: " << patronymic << "\n";

        std::cout << "Birth date: "
            << birthDate.getDay() << "."
            << birthDate.getMonth() << "."
            << birthDate.getYear() << "\n";
    }
};

int Person::count = 0;

int main()
{
    Person firstPerson(
        "123456789",
        "Ivanenko",
        "Ivan",
        "Ivanovych",
        Date(15, 5, 2005)
    );

    Person secondPerson;

    secondPerson.setId("987654321")
        .setSurname("Petrenko")
        .setName("Petro")
        .setPatronymic("Petrovych")
        .setBirthDate(Date(20, 8, 2004));

    std::cout << "First person:";
    firstPerson.showInfo();

    std::cout << "\nSecond person:";
    secondPerson.showInfo();

    std::cout << "\nNumber of objects: "
        << Person::getCount() << "\n";
}