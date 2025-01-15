#include <iostream>
#include <iomanip>
#include "Savingsaccount.h"
#include "Checkingaccount.h"

using namespace std;

int main() {
    SavingsAccount account_1(1000, 0.05);
    cout << fixed << setprecision(2);

    cout << "Initializing SavingsAccount with balance: 1000.00 and interest rate: 5%\n";
    double interest = account_1.calculateInterest();
    cout << "Calculated interest: " << interest << endl;
    account_1.credit(interest);
    cout << "After adding interest, SavingsAccount balance: " << account_1.getBalance() << endl;

    CheckingAccount account_2(500, 2);
    cout << "\nInitializing CheckingAccount with balance: 500.00 and transaction fee: 2.00\n";

    cout << "Crediting 200 to CheckingAccount\n";
    account_2.credit(200);
    cout << "CheckingAccount balance: " << account_2.getBalance() << endl;

    cout << "Debiting 100 from CheckingAccount\n";
    account_2.debit(100);
    cout << "CheckingAccount balance: " << account_2.getBalance() << endl;

    cout << "Attempting to debit 700 from CheckingAccount\n";
    account_2.debit(700);
    cout << "CheckingAccount balance: " << account_2.getBalance() << endl;

    return 0;
}