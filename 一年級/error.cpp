#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

bool compare(const vector<double> & a,const vector<double> & b){
    return a[0] * b[1] > b[0] * a[1];
}


int main(){
    int many;
    double capacity;
    cin >> many >> capacity;
    vector<vector<double> > data(many,vector<double>(2));
    for (int i = 0; i < many; i++){
        for (int j = 0; j < 2; j++){
            cin>>data[i][j];
        }
    }
    sort(data.begin(),data.end(),compare);

    // for (int i = 0; i < many; i++){
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    double value=0;
     for (int i = 0; i < many; i++) {
        if (capacity== 0) {
            break;
        }
        if (capacity >= data[i][1]) {
            value += data[i][0];
            capacity -= data[i][1];
        }
        else {
            value += ((data[i][0]/data[i][1]) * capacity);
            capacity = 0;
            break;
        }
    }
    
    cout << fixed << setprecision(6) << value  << endl;

    
    return 0;
}