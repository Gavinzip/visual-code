#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(string sender, string recipient, string sAddress, string rAddress,
                             string sCity, string rCity, string sState, string rState,
                             string sZip, string rZip, double w, double cost, double fee)
    : Package(sender, recipient, sAddress, rAddress, sCity, rCity, sState, rState, sZip, rZip, w, cost) {
    flatFee = (fee > 0) ? fee : 0;
}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + flatFee;
}