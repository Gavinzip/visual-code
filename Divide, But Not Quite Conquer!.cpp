#include <iostream>
#include <set>
using namespace std;

int ornot(int n, int m) {  
    while (n != 1) {
        if (n % m != 0) {
            return 0;
        }
        n = n / m;
    }
    return 1;
}

int main() {
    int num, div;
    while (cin >> num >> div) {
        if (div <= 1 || num <= 1) {
            cout << "Boring!" << endl;
            continue;
        }

        if (ornot(num, div)) { 
            while (num != 1) {
                cout << num << " "; 
                num /= div;
            }
            cout << "1" << endl;
        } else {
            cout << "Boring!" << endl;
        }
    }
    return 0;
}