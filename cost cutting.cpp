#include <iostream>
using namespace std;

int main(){
   int testnum;
   struct Data
   {
      int size;
      int animal;
      int score;  //friendless
   };
   cin >> testnum;
   while (testnum)
   {
      Data data;
      double budget=0;
      int farmers=0;
      cin >> farmers;
      for (int i = 0; i < farmers; i++)
      {
         cin >> data.size >> data.animal >> data.score;
         budget += (data.size) * data.score ;
      } 
      cout << budget << endl;
      testnum--;
   }
   return 0;
}
