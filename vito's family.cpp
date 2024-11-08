#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >> t ;
    while (t)
    {
        int relatives;
        cin >> relatives;
        int place[3000]={0};
        int output=0;
        for (int i = 0; i < relatives; i++)
        {
            cin >> place[i];
        }
        sort(place,place+relatives);
        for (int i = 0; i < relatives; i++)
        {
            output+=abs(place[relatives/2]-place[i]);
        }
        cout << output << endl;
        t--;
    }
    
    return 0;
}