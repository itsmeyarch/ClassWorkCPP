#pragma once
#ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
private:
    std::string name;
    double balance;
    bool isCredit;

public:
    Wallet(const std::string& walletName, double initialBalance, bool credit);

    std::string getName() const;
    double getBalance() const;
    bool getIsCredit() const;

    void deposit(double amount);
    void withdraw(double amount);
};

#endif