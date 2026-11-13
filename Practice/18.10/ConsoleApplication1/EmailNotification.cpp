#include "EmailNotification.h"
#include <iostream>

EmailNotification::EmailNotification(const std::string& message,
    const std::string& timestamp, const std::string& emailAddress)
    : Notification(message, timestamp) {
    this->emailAddress = emailAddress;
}

void EmailNotification::send() const {
    std::cout << "Відправка email на " << emailAddress
        << ": " << message << "\n";
}