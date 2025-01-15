// Aiming base-class and derived-class references at base-class
// and derived-class objects, respectively.
#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    // Base-class object
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, .06);

    // Derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    cout << fixed << setprecision(2);

    cout << "Print base-class and derived-class objects:\n\n";
    commissionEmployee.print();
    cout << "\n\n";
    basePlusCommissionEmployee.print();

    // Reference to base-class object
    CommissionEmployee& commissionEmployeeRef = commissionEmployee;
    cout << "\n\n\nCalling print with base-class reference to "
         << "\nbase-class object invokes base-class print function:\n\n";
    commissionEmployeeRef.print();

    // Reference to derived-class object
    BasePlusCommissionEmployee& basePlusCommissionEmployeeRef = basePlusCommissionEmployee;
    cout << "\n\n\nCalling print with derived-class reference to "
         << "\nderived-class object invokes derived-class "
         << "print function:\n\n";
    basePlusCommissionEmployeeRef.print();

    // Reference to base-class object pointing to derived-class object
    CommissionEmployee& baseClassRefToDerived = basePlusCommissionEmployee;
    cout << "\n\n\nCalling print with base-class reference to "
         << "derived-class object\ninvokes base-class print "
         << "function on that derived-class object:\n\n";
    baseClassRefToDerived.print(); // invokes base-class print
    cout << endl;

    return 0;
}