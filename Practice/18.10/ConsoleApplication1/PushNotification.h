#pragma once
#include "Notification.h"

class PushNotification : public Notification {
private:
    std::string deviceId;

public:
    PushNotification(const std::string& message, const std::string& timestamp,
        const std::string& deviceId);

    void send() const;
};