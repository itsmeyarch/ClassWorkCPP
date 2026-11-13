#include "Time.h"
#include <iomanip>

Time::Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    normalize();
}

void Time::normalize() {
    if (seconds < 0) {
        minutes--;
        seconds += 60;
    }

    minutes += seconds / 60;
    seconds %= 60;

    if (minutes < 0) {
        hours--;
        minutes += 60;
    }

    hours += minutes / 60;
    minutes %= 60;

    if (hours < 0) {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << std::setfill('0')
        << std::setw(2) << time.hours << ":"
        << std::setw(2) << time.minutes << ":"
        << std::setw(2) << time.seconds;

    return out;
}

std::istream& operator>>(std::istream& in, Time& time) {
    char separator1, separator2;

    in >> time.hours >> separator1 >> time.minutes >> separator2 >> time.seconds;

    if (in && (separator1 != ':' || separator2 != ':')) {
        in.setstate(std::ios::failbit);
    }

    if (in) {
        time.normalize();
    }

    return in;
}

Time Time::operator+(const Time& other) const {
    return Time(
        hours + other.hours,
        minutes + other.minutes,
        seconds + other.seconds
    );
}

Time Time::operator-(const Time& other) const {
    int total1 = hours * 3600 + minutes * 60 + seconds;
    int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

    int result = total1 - total2;

    if (result < 0) {
        result = 0;
    }

    return Time(0, 0, result);
}