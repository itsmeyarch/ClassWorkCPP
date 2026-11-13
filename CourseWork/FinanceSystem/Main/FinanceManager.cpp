#include "FinanceManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>
#include <algorithm>
#include <iomanip>

FinanceManager::FinanceManager() {
    loadData();
    if (wallets.empty()) {
        wallets.push_back(Wallet("Main Cash", 0.0, false));
        wallets.push_back(Wallet("Debit Card", 1000.0, false));
    }
}

void FinanceManager::loadData() {
    std::ifstream file("finance_data.txt");
    if (!file.is_open()) {
        return;
    }

    wallets.clear();
    transactions.clear();

    std::string line;
    bool readingWallets = true;

    while (std::getline(file, line)) {
        if (line.empty() || line == "\r") {
            continue;
        }

        if (line == "---TRANSACTIONS---" || line == "---TRANSACTIONS---\r") {
            readingWallets = false;
            continue;
        }

        std::stringstream ss(line);
        if (readingWallets) {
            std::string name;
            double balance;
            bool isCredit;
            if (ss >> std::quoted(name) >> balance >> isCredit) {
                if (!name.empty()) {
                    wallets.push_back(Wallet(name, balance, isCredit));
                }
            }
        }
        else {
            std::string wName, cat;
            double amount;
            bool isIncome;
            long long time;
            if (ss >> std::quoted(wName) >> std::quoted(cat) >> amount >> isIncome >> time) {
                transactions.push_back(Transaction(wName, cat, amount, isIncome, time));
            }
        }
    }
}

void FinanceManager::saveData() const {
    std::ofstream file("finance_data.txt");
    if (!file.is_open()) {
        std::cerr << "Cannot save finance data\n";
        return;
    }

    for (const auto& w : wallets) {
        file << std::quoted(w.getName()) << " " << w.getBalance() << " " << w.getIsCredit() << "\n";
    }

    file << "---TRANSACTIONS---\n";

    for (const auto& t : transactions) {
        file << std::quoted(t.getWalletName()) << " "
            << std::quoted(t.getCategory()) << " "
            << t.getAmount() << " "
            << t.getIsIncome() << " "
            << t.getTimestamp() << "\n";
    }
}

void FinanceManager::addWallet() {
    std::string name;
    double balance;
    int creditChoice;

    std::cout << "\nEnter wallet/card name: ";
    std::cin >> name;
    std::cout << "Enter initial balance: ";
    std::cin >> balance;
    std::cout << "Is it a credit card? (1 - Yes, 0 - No): ";
    std::cin >> creditChoice;

    wallets.push_back(Wallet(name, balance, creditChoice == 1));
    saveData();
    std::cout << "Wallet added successfully!\n";
}

void FinanceManager::showWallets() const {
    std::cout << "\n--- WALLETS AND CARDS ---\n";
    for (std::size_t i = 0; i < wallets.size(); ++i) {
        std::cout << i + 1 << ". " << wallets[i].getName()
            << " | Balance: " << std::fixed << std::setprecision(2) << wallets[i].getBalance()
            << " | Type: " << (wallets[i].getIsCredit() ? "Credit" : "Debit") << "\n";
    }
}

void FinanceManager::depositToWallet() {
    if (wallets.empty()) {
        std::cout << "No wallets available.\n";
        return;
    }

    showWallets();
    int choice;
    double amount;

    std::cout << "Choose wallet number to deposit: ";
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(wallets.size())) {
        std::cout << "Invalid choice.\n";
        return;
    }

    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "Invalid amount.\n";
        return;
    }

    wallets[choice - 1].deposit(amount);
    transactions.push_back(Transaction(wallets[choice - 1].getName(), "Deposit", amount, true, std::time(nullptr)));
    saveData();
    std::cout << "Deposit successful!\n";
}

void FinanceManager::addExpense() {
    if (wallets.empty()) {
        std::cout << "No wallets available.\n";
        return;
    }

    showWallets();
    int choice;
    double amount;
    std::string category;

    std::cout << "Choose wallet number for expense: ";
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(wallets.size())) {
        std::cout << "Invalid choice.\n";
        return;
    }

    std::cout << "Enter category (e.g., Food, Transport): ";
    std::cin >> category;
    std::cout << "Enter expense amount: ";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "Invalid amount.\n";
        return;
    }

    wallets[choice - 1].withdraw(amount);
    transactions.push_back(Transaction(wallets[choice - 1].getName(), category, amount, false, std::time(nullptr)));
    saveData();
    std::cout << "Expense added successfully!\n";
}

void FinanceManager::addIncome() {
    if (wallets.empty()) {
        std::cout << "No wallets available.\n";
        return;
    }

    showWallets();
    int choice;
    double amount;
    std::string category;

    std::cout << "Choose wallet number for income: ";
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(wallets.size())) {
        std::cout << "Invalid choice.\n";
        return;
    }

    std::cout << "Enter category (e.g., Salary, Gift): ";
    std::cin >> category;
    std::cout << "Enter income amount: ";
    std::cin >> amount;

    if (amount <= 0) {
        std::cout << "Invalid amount.\n";
        return;
    }

    wallets[choice - 1].deposit(amount);
    transactions.push_back(Transaction(wallets[choice - 1].getName(), category, amount, true, std::time(nullptr)));
    saveData();
    std::cout << "Income added successfully!\n";
}

void FinanceManager::generateReport() const {
    int periodChoice;
    std::cout << "\nChoose period for report:\n";
    std::cout << "1. Day\n";
    std::cout << "2. Week\n";
    std::cout << "3. Month\n";
    std::cout << "Your choice: ";
    std::cin >> periodChoice;

    long long currentTime = std::time(nullptr);
    long long secondsInPeriod = 86400;

    if (periodChoice == 2) {
        secondsInPeriod = 86400 * 7;
    }
    else if (periodChoice == 3) {
        secondsInPeriod = 86400 * 30;
    }
    else if (periodChoice != 1) {
        std::cout << "Wrong choice.\n";
        return;
    }

    double totalExpenses = 0.0;
    double totalIncomes = 0.0;
    std::map<std::string, double> expenseCategories;

    std::cout << "\n--- FINANCIAL REPORT ---\n";
    for (const auto& t : transactions) {
        if (currentTime - t.getTimestamp() <= secondsInPeriod) {
            if (t.getIsIncome()) {
                totalIncomes += t.getAmount();
            }
            else {
                totalExpenses += t.getAmount();
                expenseCategories[t.getCategory()] += t.getAmount();
            }
        }
    }

    std::cout << "Total Income: " << std::fixed << std::setprecision(2) << totalIncomes << "\n";
    std::cout << "Total Expenses: " << totalExpenses << "\n";
    std::cout << "Expenses by category:\n";
    for (const auto& pair : expenseCategories) {
        std::cout << "  - " << pair.first << ": " << pair.second << "\n";
    }

    std::ofstream reportFile("report.txt");
    if (reportFile.is_open()) {
        reportFile << "--- FINANCIAL REPORT ---\n";
        reportFile << "Total Income: " << totalIncomes << "\n";
        reportFile << "Total Expenses: " << totalExpenses << "\n";
        reportFile << "Expenses by category:\n";
        for (const auto& pair : expenseCategories) {
            reportFile << "  - " << pair.first << ": " << pair.second << "\n";
        }
        std::cout << "Report saved to report.txt\n";
    }
}

void FinanceManager::generateRatings() const {
    int periodChoice;
    std::cout << "\nChoose period for ratings:\n";
    std::cout << "1. Week\n";
    std::cout << "2. Month\n";
    std::cout << "Your choice: ";
    std::cin >> periodChoice;

    long long currentTime = std::time(nullptr);
    long long secondsInPeriod = 86400 * 7;

    if (periodChoice == 2) {
        secondsInPeriod = 86400 * 30;
    }
    else if (periodChoice != 1) {
        std::cout << "Wrong choice.\n";
        return;
    }

    std::vector<Transaction> periodExpenses;
    std::map<std::string, double> categoryMap;

    for (const auto& t : transactions) {
        if (!t.getIsIncome() && (currentTime - t.getTimestamp() <= secondsInPeriod)) {
            periodExpenses.push_back(t);
            categoryMap[t.getCategory()] += t.getAmount();
        }
    }

    std::sort(periodExpenses.begin(), periodExpenses.end(), [](const Transaction& a, const Transaction& b) {
        return a.getAmount() > b.getAmount();
        });

    std::vector<std::pair<std::string, double>> sortedCategories(categoryMap.begin(), categoryMap.end());
    std::sort(sortedCategories.begin(), sortedCategories.end(), [](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return a.second > b.second;
        });

    std::cout << "\n--- TOP-3 EXPENSES ---\n";
    int count = 0;
    for (const auto& t : periodExpenses) {
        if (count >= 3) break;
        std::cout << count + 1 << ". " << t.getCategory() << " - " << t.getAmount() << " (" << t.getWalletName() << ")\n";
        count++;
    }

    std::cout << "\n--- TOP-3 CATEGORIES ---\n";
    count = 0;
    for (const auto& p : sortedCategories) {
        if (count >= 3) break;
        std::cout << count + 1 << ". " << p.first << " - " << p.second << "\n";
        count++;
    }

    std::ofstream ratingFile("ratings.txt");
    if (ratingFile.is_open()) {
        ratingFile << "--- TOP-3 EXPENSES ---\n";
        count = 0;
        for (const auto& t : periodExpenses) {
            if (count >= 3) break;
            ratingFile << count + 1 << ". " << t.getCategory() << " - " << t.getAmount() << "\n";
            count++;
        }
        ratingFile << "\n--- TOP-3 CATEGORIES ---\n";
        count = 0;
        for (const auto& p : sortedCategories) {
            if (count >= 3) break;
            ratingFile << count + 1 << ". " << p.first << " - " << p.second << "\n";
            count++;
        }
        std::cout << "Ratings saved to ratings.txt\n";
    }
}