#pragma once
#ifndef FINANCE_APP_H
#define FINANCE_APP_H

#include "FinanceManager.h"

class FinanceApp {
private:
    FinanceManager manager;

    void showMenu() const;

public:
    void start();
};

#endif