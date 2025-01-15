#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance);
    void credit(double amount);
    virtual bool debit(double amount);
    double getBalance() const;
};
#endif 