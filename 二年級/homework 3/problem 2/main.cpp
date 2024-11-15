#include <iostream>
#include "savings.h"
using namespace std;

int main(){
    savings saver1(2000);
    savings saver2(3000);
    savings::modifyintrestrate(0.03);
    saver1.annualirprint();
    saver2.annualirprint();
    savings::modifyintrestrate(0.04);
    saver1.annualirprint();
    saver2.annualirprint();
}