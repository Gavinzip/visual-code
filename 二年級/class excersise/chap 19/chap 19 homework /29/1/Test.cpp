#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    cout << fixed << setprecision(2);

    {
        CommissionEmployee employee1("Bob", "Lewis", "333-33-3333", 5000, .04);
    }
    cout << endl;
    BasePlusCommissionEmployee employee2("Lisa", "Jones", "555-55-5555", 2000, .06, 800);

    cout << endl;
    BasePlusCommissionEmployee employee3("Mark", "Sands", "888-88-8888", 8000, .15, 2000);
    cout << endl;

    for (int i = 0; i < 2; i++) {
        if(i==0){
            BasePlusCommissionEmployee employee4("bisa", "ands", "888-88-8883", 7000, .15, 3000);
        }else{
             BasePlusCommissionEmployee employee5("aisa", "Snds", "888-88-8888", 7000, .15, 5000);
        }
        cout << endl;
    }
}