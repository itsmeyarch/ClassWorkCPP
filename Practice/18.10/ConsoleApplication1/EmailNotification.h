#pragma once
#include "Notification.h"

class EmailNotification : public Notification {
private:
    std::string emailAddress;

public:
    EmailNotification(const std::string& message, const std::string& timestamp,
        const std::string& emailAddress);

    void send() const;
};