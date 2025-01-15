#include "Account.h"
#include <iostream>

Account::Account(double initialBalance) {
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    } else {
        balance = 0.0;
        std::cout << "Error: Initial balance is invalid, set to 0." << std::endl;
    }
}

void Account::credit(double amount) {
    balance += amount;
}

bool Account::debit(double amount) {
    if (amount > balance) {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    } else {
        balance -= amount;
        return true;
    }
}

double Account::getBalance() const {
    return balance;
}