#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;


Time::Time(int total) : flag(false) { 
    setTime(total);
}
void Time::setTime(int t) {
    if (t < 86400) {
        hour = t / 3600;
        t %= 3600;
        minute = t / 60;
        t %= 60;
        second = t;
        flag = true;
    }
    else {
        hour = 0;
        minute = 0;
        second = 0;
        flag = false;
    }
    
}

unsigned int Time::getHour() const {
    return hour;
}

unsigned Time::getMinute() const {
    return minute;
}

unsigned Time::getSecond() const {
    return second;
}

void Time::printUniversal() const {
    if (flag) {
        cout << setfill('0') 
             << setw(2) << getHour() << ":"
             << setw(2) << getMinute() << ":"
             << setw(2) << getSecond() 
             << endl;
    } 
    else {
        cout << "Please re-enter:" << endl;
    }
}
void Time::printStandard() const {
    if (flag) {
        unsigned int displayHour = (getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12;

        cout << displayHour << ":"
             << setfill('0') << setw(2) << getMinute() << ":"
             << setw(2) << getSecond()
             << (getHour() < 12 ? " AM" : " PM")
             << endl;
    }
}