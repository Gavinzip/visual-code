#ifndef SALARYEMPLOY1_H
#define SALARYEMPLOY1_H

#include "Employee.h"
#include <string>

class SalaryEmploy1 : public Employee {
public:
    SalaryEmploy1(const std::string &first, const std::string &last, const std::string &ssn, double monthlySalary);

    void setMonthlySalary(double);
    double getMonthlySalary() const;

    virtual double earnings() const override;
    virtual void print() const override;

private:
    double monthlySalary;
};

#endif