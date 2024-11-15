#include <iostream>
#include "date.h"
using namespace std;

Date::Date(int month, int day, int year) {
    setM(month); 
    setD(month,day,year);
    setY(year);
}

int Date::check(int month,int day ,int year){
    if (setM(month)==1 && setD(month,day,year)==1 && setY(year)==1 )
    {
        return 1;
    }
    else
    {
        cout << "Please re-enter" << endl;
        return 0;
         
    }
   
}

int Date::setM(int month) {
    if (month<1||month>12){
        return 0;
    }
    else{
    dm=month; 
    return 1;
    }   
}

int Date::setD(int month,int day,int year) {
    if (month == 2) {  
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {  // 閏年
                if (day >= 1 && day <= 29) {
                    dd = day;
                    return 1;
                } else {
                    return 0;
                }
            } else {  
                if (day >= 1 && day <= 28) {
                    dd = day;
                    return 1;
                } else {
                    return 0;
                }
            }
    }
    else if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) // 31 days
    {
        if (day >= 1 && day <= 31){
        dd=day;
        return 1;
        }
        else
        return 0;
        
    }
    else if (month==4||month==6||month==9||month==11) //30 days
    {
        if (day >= 1 && day <= 30){
        dd=day;
        return 1;
        }
        else{
        return 0;
        }
    }  
    else return 0;
}
int Date::setY(int year) {
    if(year<1){
        return 0;
    }
    else{
        dy=year;
        return 1;
    }
}


void Date::nextDay(){

     if (dm == 2) {
            if ((dy % 4 == 0 && dy % 100 != 0) || (dy % 400 == 0)) {  // 閏年
                if (dd == 29) {
                    dm += 1;
                    dd = 1;
                } else {
                    dd += 1;
                }
            } else {  // 非閏年
                if (dd == 28) {
                    dm += 1;
                    dd = 1;
                } else {
                    dd += 1;
                }
            }
     }
    else if (dm==1||dm==3||dm==5||dm==7||dm==8||dm==10||dm==12) // 31 days
    {
        if(dd==31){ // cross months
            if(dm==12){ // 12 to 1
                dm=1;
                dd=1;
                dy=dy+1;
            }
            else{ //1-11
                dm=dm+1;
                dd=1;
            }
        }
        else {
        dd+=1;
        } 
    }
    else if  (dm==4||dm==6||dm==9||dm==11) //30 days
    {
        if(dd==30){ // cross months 
            dm=dm+1;
            dd=1;
        }
        else {
        dd+=1; 
        }
    }
    else
    ;
}
void Date::displayDate()  {
    cout << dy << " / " << dm << " / " << dd << endl;
}


