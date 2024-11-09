#include <iostream>
#include <string>
using namespace std;

int main(){
   string s; // 0-9 A-Z a-z
   int d;
   while (cin >> s)
   {
      int max=1,sum=0,j;
      for (int i = 0; i < s.size(); i++)
      {
         d=0; //  for exceptions
         if (s[i]>='0'&& s[i]<='9')
         {
            d=s[i]-'0';
         }
         if (s[i]>='A'&& s[i]<='Z')
         {
            d=s[i]-'A'+10;
         }
         if (s[i]>='a'&& s[i]<='z')
         {
            d=s[i]-'a'+36;
         }
         sum+=d;
         if (max<d)
            max=d;
      }
      for ( j = max+1; j <=62 ; j++)
      {
         if (sum%(j-1)==0)
         {
            break;
         }
      }
      if (j<=62)
         cout << j << endl;
      else
         cout << "such number is impossible!" << endl;
      
   }
   

}