#include <iostream>
#include <string>
using namespace std;

 int main (){
    string s;
    string t;
    while (cin >> s >> t) //sequence subsequence
    {
        size_t cnt=0;
        size_t j=0;
        for (size_t i = 0; i < s.size(); i++) //s
        {
           
            
            if (j==t.size())
            {
                break;
            }
            if (s[i]==t[j])
            {
                cnt++;
                j++;
            }
         else{
            for ( j ;j < t.size(); j++)
            {
                if (s[i]==t[j])
                {
                    cnt++;
                    j++; //
                    break;
                }
            }
         }
       }
       if (cnt==s.size())
       {
            cout << "Yes" << endl;
       }
       else
        cout << "No" <<endl;
    }
    
 }