#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double transactionFee;

    void chargeFee();

public:
    CheckingAccount(double initialBalance, double fee);
    void credit(double amount);
    bool debit(double amount);
};

#endif