#include "PushNotification.h"
#include <iostream>

PushNotification::PushNotification(const std::string& message,
    const std::string& timestamp, const std::string& deviceId)
    : Notification(message, timestamp) {
    this->deviceId = deviceId;
}

void PushNotification::send() const {
    std::cout << "Відправка пуша на пристрій " << deviceId
        << ": " << message << "\n";
}