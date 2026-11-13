#include <iostream>
#include "EmailNotification.h"
#include "PushNotification.h"

int main() {
    EmailNotification email(
        "Hello! Your order has been shipped.",
        "2026-11-13 12:00",
        "user@gmail.com"
    );

    PushNotification push(
        "You have a new message!",
        "2026-11-13 12:05",
        "DEVICE123"
    );

    email.send();
    push.send();
}