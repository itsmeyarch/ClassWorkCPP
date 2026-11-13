#include "Notification.h"

Notification::Notification(const std::string& message, const std::string& timestamp) {
    this->message = message;
    this->timestamp = timestamp;
}