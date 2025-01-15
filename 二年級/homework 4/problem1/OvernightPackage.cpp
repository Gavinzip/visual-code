#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(string sender, string recipient, string sAddress, string rAddress,
                                   string sCity, string rCity, string sState, string rState,
                                   string sZip, string rZip, double w, double cost, double additionalCost)
    : Package(sender, recipient, sAddress, rAddress, sCity, rCity, sState, rState, sZip, rZip, w, cost) {
    additionalCostPerOunce = (additionalCost > 0) ? additionalCost : 0;
}

double OvernightPackage::calculateCost() const {
    return weight * (costPerOunce + additionalCostPerOunce);
}