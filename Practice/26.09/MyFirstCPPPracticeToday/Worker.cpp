#include "Worker.h"
#include <iostream>

Worker::Worker(const std::string& fullName, const std::string& position,
    int hireYear, double salary) {
    this->fullName = fullName;
    this->position = position;
    this->hireYear = hireYear;
    this->salary = salary;
}

std::string Worker::getPosition() const {
    return position;
}

int Worker::getHireYear() const {
    return hireYear;
}

double Worker::getSalary() const {
    return salary;
}

void Worker::Print() const {
    std::cout << "Full name: " << fullName << "\n";
    std::cout << "Position: " << position << "\n";
    std::cout << "Hire year: " << hireYear << "\n";
    std::cout << "Salary: " << salary << "\n\n";
}