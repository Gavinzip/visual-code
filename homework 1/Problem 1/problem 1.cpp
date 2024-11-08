// no_inline_test.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include <ctime>

using namespace std;

double diffclock(clock_t clock1,clock_t clock2)
{
 double diffticks=clock1-clock2;
 double diff=(diffticks)/CLOCKS_PER_SEC;
 return diff;
}

double cube(const double s) { return s * s * s; } 
//inline double cube(const double s) { return s * s * s; } //inline �禡


int main() 
{
	double side;

	clock_t begin=clock();
	for(int k=1; k<30000 ; k++)  
	{
		side = k;
		cout  << "The side length of your cube: "<< side << endl;
		cout << "Volume of cube with side "
			<<side<<" is "<< cube(side)<<endl;     
	}
	clock_t end=clock();
	cout<<"\n\n<------------------------- Done ------------------------> "<<endl;
	cout<<"\n\nTotal execution time: "<<diffclock(end,begin)<<" seconds."<<endl;
	cout<<"\n\n<-------------------------------------------------------> "<<endl;
	return 0; 
}
