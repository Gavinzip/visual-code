// Date.h
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
public:
    static const int monthsPerYear = 12;
    Date(int m = 1, int d = 1, int y = 1900);
    void print() const;
    ~Date();

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int checkDay(int) const;
};

#endif