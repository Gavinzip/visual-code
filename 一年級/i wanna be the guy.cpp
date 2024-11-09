#include <iostream>
#include <vector>
using namespace std;

int main(){
    int total;
    while (cin >> total)
    {
        vector <int> levels(total);
        int amout,pass;
        for (int j = 0; j < 2; j++)
        {
            cin >> amout;
            for (int i = 0; i < amout; i++)
            {
                cin >> pass;
                levels[pass-1]=1;
            }
        }
        for (int i = 0; i < total; i++) // check to see if pass
        {
            if (levels[i]==0)
            {
                cout << "Oh, my keyboard!" << endl;
                break;
            }
            if (i==total-1)
            {
                cout << "I become the guy." << endl;
            }
            
        }

        // for (int i = 0; i < total; i++)
        // {
        //     cout << levels[i] << " ";
        // }
        

        
        
    }
    
}