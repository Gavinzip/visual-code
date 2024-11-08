#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    int num ;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> input;
        if(input.size()>10)
            cout << input[0] << input.size()-2 << input[input.size()-1] <<endl;
        else
            cout <<input << endl;
        
    }
    
    return 0;
}