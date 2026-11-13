#include "Wallet.h"

Wallet::Wallet(const std::string& walletName, double initialBalance, bool credit)
    : name(walletName), balance(initialBalance), isCredit(credit) {
}

std::string Wallet::getName() const {
    return name;
}

double Wallet::getBalance() const {
    return balance;
}

bool Wallet::getIsCredit() const {
    return isCredit;
}

void Wallet::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Wallet::withdraw(double amount) {
    if (amount > 0) {
        balance -= amount;
    }
}