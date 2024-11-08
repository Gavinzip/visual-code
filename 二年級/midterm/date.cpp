#include <iostream>
#include "date.h"
using namespace std;

Date::Date(int month, int day, int year) {
    setM(month); 
    setD(month,day,year);
    setY(year);
}

void Date::setM(int month) {
    if (month<1||month>12){
        cout << "Please re-enter" << endl;
    }
    
}

int Date::getM() const {
    return dm;
}

void Date::setD(int month,int day,int year) {
    if (month==2) // exceptions
    {
        if (year%400==0){ // yes
            if (1<=day<=29){
                dd=day;
            }
            else{
                cout << "Please re-enter" << endl;
            }
        }
        else if (year%100==0 && year%4==0){ //yes
            if (1<=day<=29){
                dd=day;
            }
            else{
                cout << "Please re-enter" << endl;
            }
            
        }
        else { //no
            if (1<=day<=28)
            {
                dd=day;
            }
            else{
                cout << "Please re-enter" << endl;
            }
            
        }
    }
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) // 31 days
    {
        if (1<=day<=31)
        dd=day;
        else
        cout << "Please re-enter" << endl;
        
    }
    if (month==4||month==6||month==9||month==11) //30 days
    {
        if (1<=day<=30)
        dd=day;
        cout << "Please re-enter" << endl;
    }
    
    
    
    
}

int Date::getD() const {
    return dd;
}

void Date::setY(int year) {
    if(year<1){
        cout << "Please re-enter " << endl;
    }
    else{
        dy=year;
    }
}

int Date::getY() const {
    return dy;
}

void Date::nextDay(){
    if (dm==2) // exceptions
    {
        if (year%400==0){ // yes
            
        }
        else if (year%100==0 && year%4==0){ //yes
            
            
        }
        else { //no
            
        }
    }
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) // 31 days
    {
        if(dd==31){ // cross months
            if(dm=12){ // 12 to 1
                dm=1;
                dd=1;
                dy=dy+1;
            }
            else{ //1-11
                dm=dm+1;
                dd=1;
            }
        }
        else 
        dd=dd+1; // add one day
    }
    if (month==4||month==6||month==9||month==11) //30 days
    {
        if(dd==30){ // cross months 
            dm=dm+1;
            dd=1;
        }
        else 
        dd=dd+1; // add one day
    }
}
void Date::displayDate() const {
    cout << dm << " / " << dd << " / " << dy << endl;
}
