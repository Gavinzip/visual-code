#include<iostream>
using namespace std;
class Date {
public:
    Date(int month, int day, int year);
    int check(int month,int day ,int year);
    int setM(int month);
    
    int setD(int month,int day,int year);
    
    int setY(int year);
    
    void nextDay();
    void displayDate() ;

private:
    int dm;
    int dd;
    int dy;
};

