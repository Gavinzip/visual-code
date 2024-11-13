#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    Date date1(13, 25, 2024); 
    Date date2(7, 15, 2023);   

    cout << "Date 1: ";
    date1.displayDate(); 
    cout << "Date 2: ";
    date2.displayDate(); 

    return 0;
}
