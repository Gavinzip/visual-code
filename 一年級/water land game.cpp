#include <iostream>
using namespace std;

int howmuch(int arr[101],int n);


 int main (){
    int total;
    while (cin >> total)
    {
        for (int i = 0; i < total; i++)
        {
            int test[101];
            int testa;
            cin >> testa ;
            for (int i = 0; i < testa; i++)
            {
                cin >> test[i];
            }
            int player=0;
            cout << howmuch(test,testa) << endl;
            
        }


        
    }
    return 0;
 }

 
int howmuch(int arr[101],int n) {
    int firstwater=0,lastwater = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        if (arr[i]==0 && firstwater == 0) {
            firstwater = i;
        }

        if (arr[i] == 0) {
            lastwater = i;
        }
        else {
            continue;
        }
    }
    if (firstwater == 0) {
        return 0;
    }
    return lastwater - firstwater + 2;
}


