#include "Transaction.h"

Transaction::Transaction(const std::string& wName, const std::string& cat, double amt, bool income, long long time)
    : walletName(wName), category(cat), amount(amt), isIncome(income), timestamp(time) {
}

std::string Transaction::getWalletName() const {
    return walletName;
}

std::string Transaction::getCategory() const {
    return category;
}

double Transaction::getAmount() const {
    return amount;
}

bool Transaction::getIsIncome() const {
    return isIncome;
}

long long Transaction::getTimestamp() const {
    return timestamp;
}