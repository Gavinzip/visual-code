#include <iostream>
#include <stdexcept>
#include "SalariedEmployee1.h"
using namespace std;

SalaryEmploy1::SalaryEmploy1(const string &first, const string &last, const string &ssn, double salary)
    : Employee(first, last, ssn) {
    setMonthlySalary(salary);
}

void SalaryEmploy1::setMonthlySalary(double salary) {
    if (salary >= 0.0)
        monthlySalary = salary;
    else
        throw invalid_argument("Monthly salary must be >= 0.0");
}

double SalaryEmploy1::getMonthlySalary() const {
    return monthlySalary;
}

double SalaryEmploy1::earnings() const {
    return getMonthlySalary();
}

void SalaryEmploy1::print() const {
    cout << "salary employee: ";
    Employee::print();
    cout << "\nmonthly salary: " << getMonthlySalary();
}