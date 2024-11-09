#include <iostream>
using namespace std;
 int main (){
    int input;
    while (cin >> input)
    {
        int walls;
        for (int i = 0; i < input; i++) // test1
        {
            int wall[51];
            int high=0;
            int low=0;
            cin >> walls;
            for (int j = 0; j < walls; j++) // input all the walls
            {
                cin >> wall[j];
            }
            for (int j = 0; j < walls-1; j++) // check high low 1 4 2 2 3 5 3 4
            {
                if (wall[j]< wall[j+1] )
                    high++;
                if (wall[j]>wall[j+1])
                    low++;
            }
            cout << "Case " << i+1 << ": " << high << " " << low << endl;
            
        }
        
    }
    
    
    
 }