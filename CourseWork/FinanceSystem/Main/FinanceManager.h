#pragma once
#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

#include <vector>
#include <string>
#include "Wallet.h"
#include "Transaction.h"

class FinanceManager {
private:
    std::vector<Wallet> wallets;
    std::vector<Transaction> transactions;

    void loadData();
    void saveData() const;

public:
    FinanceManager();

    void addWallet();
    void depositToWallet();
    void addExpense();
    void addIncome();
    void showWallets() const;
    void generateReport() const;
    void generateRatings() const;
};

#endif