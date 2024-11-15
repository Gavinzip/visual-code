#include <iostream>
#include "time.h"
using namespace std;

int main() {
    Time time;
    int total_second;
    while (cin >> total_second) {
        time.setTime(total_second);
        time.printUniversal();
        time.printStandard();
    }
    return 0;
}