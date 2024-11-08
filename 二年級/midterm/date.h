#include<iostream>
using namespace std;
class Date {
public:
    Date(int month, int day, int year);
    
    void setM(int month);
    int getM() const;
    
    void setD(int month,int day,int year);
    int getD() const;
    
    void setY(int year);
    int getY() const;
    
    void nextDay()const;
    void displayDate() const;

private:
    int dm;
    int dd;
    int dy;
};

