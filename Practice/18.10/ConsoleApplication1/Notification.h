#pragma once
#include <string>

class Notification {
protected:
    std::string message;
    std::string timestamp;

public:
    Notification(const std::string& message, const std::string& timestamp);
};