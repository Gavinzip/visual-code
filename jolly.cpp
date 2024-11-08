#include <iostream>
#include <algorithm>
using namespace std;
int main () {
   int many=0;
   int number[3000]={0};
   while (cin >> many)
   {
    for (int i = 0; i < many; i++)
    {
       cin >> number[i];
    }

    int minus[2999]={0};
    for (int i = 0; i < many-1; i++)
    {
        minus[i]=abs(number[i]-number[i+1]);
    }

    sort(minus,minus+many-1);
    int jt=0;
    for ( int i = 0; i < many; i++)
    {
        
        if (minus[i]==i+1)
        {
            jt++;
        }
    }
    if (jt==many-1)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
        
     }
   
   
   return 0;
}

