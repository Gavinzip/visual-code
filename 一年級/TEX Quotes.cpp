#include <iostream>
#include <string>
using namespace std;

int main(){
    string s ;
    bool count=true ;
    while(getline(cin,s)){
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i]=='"'){
            if (count)
            {
                s.replace(i,1,"``");
                i++;
            }
            else
            {
                s.replace(i,1,"''");
                i++;
            }
             count=!count;
        }
       
    }
    cout << s << endl ;
    }
    
    
}