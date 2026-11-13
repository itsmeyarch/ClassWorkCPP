#include <iostream>
#include <string>
#include <fstream>

class Student
{
private:
    std::string fullName;
    std::string birthDate;
    std::string phone;
    std::string city;
    std::string country;
    std::string institution;
    std::string institutionCity;
    std::string institutionCountry;
    std::string groupNumber;

public:
    void inputData()
    {
        std::cout << "Enter full name: ";
        std::getline(std::cin, fullName);

        std::cout << "Enter birth date: ";
        std::getline(std::cin, birthDate);

        std::cout << "Enter phone: ";
        std::getline(std::cin, phone);

        std::cout << "Enter city: ";
        std::getline(std::cin, city);

        std::cout << "Enter country: ";
        std::getline(std::cin, country);

        std::cout << "Enter educational institution: ";
        std::getline(std::cin, institution);

        std::cout << "Enter institution city: ";
        std::getline(std::cin, institutionCity);

        std::cout << "Enter institution country: ";
        std::getline(std::cin, institutionCountry);

        std::cout << "Enter group number: ";
        std::getline(std::cin, groupNumber);
    }

    void showData()
    {
        std::cout << "\nStudent information:\n";
        std::cout << "Full name: " << fullName << "\n";
        std::cout << "Birth date: " << birthDate << "\n";
        std::cout << "Phone: " << phone << "\n";
        std::cout << "City: " << city << "\n";
        std::cout << "Country: " << country << "\n";
        std::cout << "Institution: " << institution << "\n";
        std::cout << "Institution city: " << institutionCity << "\n";
        std::cout << "Institution country: " << institutionCountry << "\n";
        std::cout << "Group: " << groupNumber << "\n";
    }

    std::string getFullName()
    {
        return fullName;
    }

    std::string getPhone()
    {
        return phone;
    }

    std::string getGroupNumber()
    {
        return groupNumber;
    }
};

class Point
{
private:
    double x;
    double y;
    double z;

public:
    void inputData()
    {
        std::cout << "Enter x: ";
        std::cin >> x;

        std::cout << "Enter y: ";
        std::cin >> y;

        std::cout << "Enter z: ";
        std::cin >> z;
    }

    void showData()
    {
        std::cout << "X: " << x << "\n";
        std::cout << "Y: " << y << "\n";
        std::cout << "Z: " << z << "\n";
    }

    void setX(double value)
    {
        x = value;
    }

    void setY(double value)
    {
        y = value;
    }

    void setZ(double value)
    {
        z = value;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    double getZ()
    {
        return z;
    }

    void saveToFile()
    {
        std::ofstream file("point.txt");

        if (file.is_open())
        {
            file << x << "\n";
            file << y << "\n";
            file << z << "\n";

            file.close();
            std::cout << "Data saved\n";
        }
        else
        {
            std::cout << "File error\n";
        }
    }

    void loadFromFile()
    {
        std::ifstream file("point.txt");

        if (file.is_open())
        {
            file >> x >> y >> z;

            file.close();
            std::cout << "Data loaded\n";
        }
        else
        {
            std::cout << "File error\n";
        }
    }
};

int main()
{
    std::cout << "TASK 1\n";

    Student student;
    student.inputData();
    student.showData();

    std::cout << "\nTASK 2\n";

    Point point;
    point.inputData();

    std::cout << "\nPoint coordinates:\n";
    point.showData();

    point.saveToFile();

    Point secondPoint;
    secondPoint.loadFromFile();

    std::cout << "\nLoaded coordinates:\n";
    secondPoint.showData();
}