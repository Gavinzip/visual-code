#include "Checkingaccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance) {
    transactionFee = fee;
}

void CheckingAccount::chargeFee() {
    if (!Account::debit(transactionFee)) {
        std::cout << "Transaction fee could not be charged due to insufficient balance." << std::endl;
    }
}

void CheckingAccount::credit(double amount) {
    Account::credit(amount);
    chargeFee();
}

bool CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        chargeFee();
        return true;
    }
    return false;
}