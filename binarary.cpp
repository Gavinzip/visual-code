#include <iostream>

using namespace std;

void bs(int ary[],int m){
   for (int i = 0; i < m-1; i++)
   {
      for (int j = 0; j < m-1-i ; j++)
      {
         if (ary[j]>ary[j+1])
         {
            swap(ary[j],ary[j+1]);
         }
      }
   }
}

int findnum(int ary[],int many,int guess){
   int as=0,ae=many-1;
   while (as<=ae)
   {
      int half=(as+ae)/2;
      if (ary[half]==guess)
         return 1;
      else if (ary[half]>guess)
      {
         ae=half-1;
      }
      else
         as=half+1;
      
   }
   return 0;
}
int main(){
   int many;
   cin >> many;
   int number[many];
   for (int i = 0; i < many; i++)
   {
      cin >> number[i];
   }
   
   bs(number,many);

   // for (int i = 0; i < many; i++)
   // {
   //    cout << number[i] << " " ;
   // }
   int guess,times;
   cin >> times;
   while (times)
   {
      cin >> guess;
      if (findnum(number,many,guess))
         cout << "1" << endl;
      else
         cout << "0" << endl;
      times--;
   }
   
   
   
   return 0;
   
}