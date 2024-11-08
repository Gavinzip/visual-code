#include<iostream>
using namespace std;

int mulValue(int count) {
    count = count * count;
    return count;
}

void mulReference(int &count) {
    count = count * count;
}

int main() {
    int count1 = 5;
    int count2 = 5;

    int result = mulValue(count1);
    cout << "result of multipleByValue:" << result << endl; 
    cout << "count1 after multipleByValue:" << count1 << endl; 

    mulReference(count2);
    cout << "count2 after multipleByReference:" << count2 << endl; 

    return 0;
}