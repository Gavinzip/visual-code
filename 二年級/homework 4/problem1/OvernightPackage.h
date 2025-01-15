#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
private:
    double additionalCostPerOunce;

public:
    OvernightPackage(string sender, string recipient, string sAddress, string rAddress,
                     string sCity, string rCity, string sState, string rState,
                     string sZip, string rZip, double w, double cost, double additionalCost);

    double calculateCost() const;  // No override here
};

#endif