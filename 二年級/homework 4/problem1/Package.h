#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

class Package {
protected:
    string senderName, recipientName;
    string senderAddress, recipientAddress;
    string senderCity, recipientCity;
    string senderState, recipientState;
    string senderZip, recipientZip;
    double weight;  // in ounces
    double costPerOunce;

public:
    Package(string sender, string recipient, string sAddress, string rAddress,
            string sCity, string rCity, string sState, string rState,
            string sZip, string rZip, double w, double cost);

    // Non-virtual calculateCost function
    double calculateCost() const;

    ~Package() {}
};

#endif