#include <iostream>
using namespace std;


int main() {
    int n;
    while (cin >> n)
    {
        if (n==0)
            break;
        
        if (n%2==1||n<4)
        {
            cout << "Impossible" << endl;
            continue;
        }
        cout << n+n/2 << endl;
        for (int i = 1; i < n; i++)
        {
            cout << i << " " << i+1 << endl;
            if (i<i+n/2&&i+n/2<=n)
            {
                cout << i <<" " << i+n/2 << endl;
            }
            if (i==1)
                cout << i <<" " <<  n << endl;
            
        }
    }
    return 0;
}
