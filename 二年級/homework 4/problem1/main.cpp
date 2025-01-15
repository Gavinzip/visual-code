#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main() {
    // Create Package objects
    Package basicPackage("Alice", "Bob", "123 Main St", "456 Oak St", "CityA", "CityB", 
                         "StateA", "StateB", "12345", "67890", 10, 0.5);
    TwoDayPackage twoDayPackage("Alice", "Bob", "123 Main St", "456 Oak St", "CityA", "CityB", 
                                 "StateA", "StateB", "12345", "67890", 10, 0.5, 2.0);
    OvernightPackage overnightPackage("Alice", "Bob", "123 Main St", "456 Oak St", "CityA", "CityB", 
                                       "StateA", "StateB", "12345", "67890", 10, 0.5, 0.25);

    // Call calculateCost explicitly on objects
    cout << "Basic Package Cost: $" << basicPackage.calculateCost() << endl;
    cout << "Two-Day Package Cost: $" << twoDayPackage.calculateCost() << endl;
    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;

    return 0;
}