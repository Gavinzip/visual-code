#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int month, int day, int year) {
    setMonth(month); 
    setDay(day);
    setYear(year);
}

void Date::setMonth(int month) {
    dm = (month >= 1 && month <= 12) ? month : 1;  
}

int Date::getMonth() const {
    return dm;
}

void Date::setDay(int day) {
    dd = day;
}

int Date::getDay() const {
    return dd;
}

void Date::setYear(int year) {
    dy = year;
}

int Date::getYear() const {
    return dy;
}

void Date::displayDate() const {
    cout << dm << " / " << dd << " / " << dy << endl;
}
