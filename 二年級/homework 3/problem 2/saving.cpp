#include <iostream>
#include "savings.h"
using namespace std;

savings::savings(double money):savingsb(money){}

double savings::intrestrate=0;  


void savings::annualirprint(){
    savingsb=savingsb+savingsb*intrestrate/12;
    cout << savingsb <<endl;; // monthly
}

void savings::modifyintrestrate(double newrate){
    intrestrate=newrate;
}