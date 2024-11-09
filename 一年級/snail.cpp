#include <iostream>
using namespace std;

int main(){
   double h,u,d,f;
   while (cin >> h >> u >> d >> f) //6 3 1 10
   {
      if (h==0)
      {
         break;
      }
      int day=1;
      double hn=0;
      while (1){
         double up=u-(u*f*0.01*(day-1));
         if (up<=0)
         {
            up=0;
         }
         hn+=up;    // first day up 
         
         if (hn>h)
         {
            cout << "success on day " << day << endl;
            break;
         }
         hn+=-d; //a cycle end
         
         if (hn<0)
         {
            cout << "failure on day " << day << endl;
            break;

         }
         day++;  // next day 
      }
   }
   
   return 0;
}