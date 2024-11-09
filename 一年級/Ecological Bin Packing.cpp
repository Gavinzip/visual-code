#include<iostream>

using namespace std;

int main() {
    const string color[] = { "BCG","BGC","CBG","CGB","GBC","GCB" };
    int b[3], g[3], c[3];
    while (cin >> b[0] >> g[0] >> c[0]) {//直到EOF
        for (int i = 1; i < 3; i++) {
            cin >> b[i] >> g[i] >> c[i];
        }
        int m[6] = {};
        m[0] = g[0] + c[0] + b[1] + g[1] + b[2] + c[2]; //BCG
        m[1] = g[0] + c[0] + b[1] + c[1] + b[2] + g[2]; //BGC
        m[2] = b[0] + g[0] + g[1] + c[1] + b[2] + c[2]; //CBG
        m[3] = b[0] + g[0] + b[1] + c[1] + c[2] + g[2]; //CGB
        m[4] = b[0] + c[0] + c[1] + g[1] + b[2] + g[2]; //GBC
        m[5] = b[0] + c[0] + b[1] + g[1] + c[2] + g[2]; //GCB
        
        int min = 0;
        for (int j = 1; j < 6; j++) {
            if (m[j] < m[min]) {
                min = j;
            }
        }
        cout << color[min] << " " << m[min] << endl;
    }
}