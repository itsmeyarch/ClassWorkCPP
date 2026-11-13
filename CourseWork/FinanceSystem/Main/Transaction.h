#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string walletName;
    std::string category;
    double amount;
    bool isIncome;
    long long timestamp;

public:
    Transaction(const std::string& wName, const std::string& cat, double amt, bool income, long long time);

    std::string getWalletName() const;
    std::string getCategory() const;
    double getAmount() const;
    bool getIsIncome() const;
    long long getTimestamp() const;
};

#endif