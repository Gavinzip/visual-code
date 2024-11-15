#include <iostream>
#include "date.h"
using namespace std;

int main() {
    int month, day, year;
    Date Date(month, day, year);
    while(cin >> year >> month >> day){ 
        if (Date.check(month,day,year))
        {
            Date.nextDay();
            Date.displayDate();
        }

    }

    return 0;
}