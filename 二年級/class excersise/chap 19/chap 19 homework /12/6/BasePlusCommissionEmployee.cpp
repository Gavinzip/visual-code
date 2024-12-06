#include <iostream>
#include "BasePlusCommissionEmployee.h"
using std::cout;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary)
 : CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);

}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    cout << "BasePlusCommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    CommissionEmployee::print();

    cout << "\nbase salary: " << getBaseSalary();
}