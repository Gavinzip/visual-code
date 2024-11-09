#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    while (getline(cin,input) && input!="END")
    {
        int last;
        cout << char(toupper(input[0]));
        for (size_t i = 0; i < input.size(); i++)
        {
            if (input[i]==' '){
                cout << char(toupper(input[i+1]));
                last=i+1;
            }
        }
        cout << ' ' ;
        for (size_t i = last; i < input.size(); i++)
        {
            cout << char(input[i]);
        }
        
        
    }
    return 0;
}