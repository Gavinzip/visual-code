// main.cpp
#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

int main() {
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Date leave(3, 20, 1988);
    Employee manager("Bob", "Blue", birth, hire, leave);

    cout << endl;
    manager.print();
    return 0;
}