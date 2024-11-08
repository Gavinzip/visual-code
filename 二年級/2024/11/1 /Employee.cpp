// Employee.cpp
#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const string& first, const string& last, const Date& dateOfBirthday, const Date& dateOfHire, const Date& dateOfLeave)
    : firstName(first), lastName(last), birthDate(dateOfBirthday), hireDate(dateOfHire), leaveDate(dateOfLeave) {
    cout << "Employee object constructor: " << firstName << " " << lastName << endl;
}

void Employee::print() const {
    cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << " Leave Date: ";
    leaveDate.print();
    cout << endl;
}

Employee::~Employee() {
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}