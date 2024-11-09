#include <iostream>

using namespace std;

int check(int test[],int many){
   for (int i = 0; i < many; i++)
   {
      if (test[i]!=i+1)
      {
         return 0;
         // break;
      }
      
   }
   return 1;
}
int main(){
   int times;
   cin >> times;
   while (times)
   {
      int many;
      cin >> many;
      int test[many];
      for (int i = 0; i < many; i++)
      {
         cin >> test[i];
      }

      for (int i = 2; i < many; i++)
      {
         if (test[i-2]<test[i-1]&&test[i-1]>test[i])
         {
            swap(test[i-1],test[i]);
         }
         
      }
      // for (int i = 0; i < many; i++)
      // {
      //    cout << test[i] << " ";
      // }
      
      
      if(check(test,many))
      {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;

      times--;
   }
   
}