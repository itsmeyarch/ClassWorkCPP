#include "FinanceApp.h"
#include <iostream>

void FinanceApp::showMenu() const {
    std::cout << "\n=== PERSONAL FINANCE MANAGEMENT ===\n";
    std::cout << "1. Show wallets & cards\n";
    std::cout << "2. Add new wallet/card\n";
    std::cout << "3. Deposit money\n";
    std::cout << "4. Add expense\n";
    std::cout << "5. Add income\n";
    std::cout << "6. Generate report\n";
    std::cout << "7. Generate ratings (TOP-3)\n";
    std::cout << "8. Exit\n";
}

void FinanceApp::start() {
    std::string choice;

    while (true) {
        showMenu();

        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            manager.showWallets();
        }
        else if (choice == "2") {
            manager.addWallet();
        }
        else if (choice == "3") {
            manager.depositToWallet();
        }
        else if (choice == "4") {
            manager.addExpense();
        }
        else if (choice == "5") {
            manager.addIncome();
        }
        else if (choice == "6") {
            manager.generateReport();
        }
        else if (choice == "7") {
            manager.generateRatings();
        }
        else if (choice == "8") {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Wrong choice. Try again.\n";
        }
    }
}