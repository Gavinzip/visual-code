#include "Package.h"

Package::Package(string sender, string recipient, string sAddress, string rAddress,
                 string sCity, string rCity, string sState, string rState,
                 string sZip, string rZip, double w, double cost)
    : senderName(sender), recipientName(recipient),
      senderAddress(sAddress), recipientAddress(rAddress),
      senderCity(sCity), recipientCity(rCity),
      senderState(sState), recipientState(rState),
      senderZip(sZip), recipientZip(rZip) {
    weight = (w > 0) ? w : 0;
    costPerOunce = (cost > 0) ? cost : 0;
}

double Package::calculateCost() const {
    return weight * costPerOunce;
}