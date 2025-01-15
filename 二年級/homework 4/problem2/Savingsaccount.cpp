#include "Savingsaccount.h"
using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double rate) 
    : Account(initialBalance) {
    interestRate = rate;
}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}