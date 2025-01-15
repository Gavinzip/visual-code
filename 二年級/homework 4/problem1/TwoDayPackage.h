#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(string sender, string recipient, string sAddress, string rAddress,
                  string sCity, string rCity, string sState, string rState,
                  string sZip, string rZip, double w, double cost, double fee);

    double calculateCost() const;  // No override here
};

#endif