#pragma once
#pragma once
#pragma once
#ifndef COMMISSIONEMPLOYEE_H 
#define COMMISSIONEMPLOYEE_H
#include <string> 
using namespace std;

class CommissionEmployee {
public:
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
    ~CommissionEmployee();

    void setFirstName(const string&);
    string getFirstName() const;
    void setLastName(const string&);
    string getLastName() const;
    void setSocialSecurityNumber(const string&);
    string getSocialSecurityNumber() const;
    void setGrossSales(double);
    double getGrossSales() const;
    void setCommissionRate(double);
    double getCommissionRate() const;
    double earnings() const;
    void print() const;
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};
#endif