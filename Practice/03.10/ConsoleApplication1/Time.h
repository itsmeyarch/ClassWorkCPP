#pragma once
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize();

public:
    Time();
    Time(int hours, int minutes, int seconds);

    friend std::ostream& operator<<(std::ostream& out, const Time& time);
    friend std::istream& operator>>(std::istream& in, Time& time);

    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;
};