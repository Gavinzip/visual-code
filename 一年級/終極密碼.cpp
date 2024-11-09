#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <random>
#include <stdio.h>
#include<chrono>
#include<thread>
using namespace std;

void bs(vector<int>& vec, int n) { // bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j],vec[j+1]);
            }
        }
    }
}

int main() {

    int range= 100;
    vector <int>  number; 
    
    for ( int i = 0; i < range; i++)
    {
        number.push_back(i+1);
    }// set range
    
    random_device rd;
    mt19937 r(rd());
    shuffle(number.begin(),number.end(),r);//shuffle
    auto startIterator = number.begin() + 50;
    auto endIterator = number.begin() + 100;  // One past the last element to be erased

    // Erase elements in the specified range
    number.erase(startIterator, endIterator);

    
    bs(number,50);// sort the 50 numbers from the start

    for (int i = 0; i < 50; i++)
    {
        cout<< number[i] << " ";
    }
    cout << endl;

    srand(time(NULL));
    int ans,vec,s,e;
    vec=rand()%50;
    ans=number[vec];
    int t=1;
    
    cout << number[0] <<"~" << number[49] << endl;
    s=number[0];
    e=number[49];
    
    int guess,ns=0,ne=49,half; 
    while (t)
    {
        
       
        
        half=(ns+ne)/2;
        // cout << half;
        guess=number[half];
        cout<<"Auto guess: "<<guess << endl;
        
        if (guess<ans)
        {
            cout << "higher" << endl;
            cout << guess << "~" << e << endl;
            ns=half;
            s=guess;

        }
        else if (guess>ans)
        {
            cout << "lower" << endl;
            cout << s << "~" << guess << endl;
            ne=half;
            e=guess;
        }
        else 
        {
            cout << "correct" << endl;
            t--;
        }
    }
    
    
    

   return 0;
}