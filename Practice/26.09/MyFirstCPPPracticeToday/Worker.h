#pragma once
#include <string>

class Worker {
private:
    std::string fullName;
    std::string position;
    int hireYear;
    double salary;

public:
    explicit Worker(const std::string& fullName, const std::string& position,
        int hireYear, double salary);

    std::string getPosition() const;
    int getHireYear() const;
    double getSalary() const;

    void Print() const;
};