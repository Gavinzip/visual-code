#include<iostream>
using namespace std;

template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    int x = 10, y = 20;
    cout << "before swap (int): x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "after swap (int): x = " << x << ", y = " << y << endl;


    char c1 = 'A', c2 = 'B';
    cout << "before swap (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    swapValues(c1, c2);
    cout << "after swap (char): c1 = " << c1 << ", c2 = " << c2 << endl;


    float f1 = 1.5f, f2 = 2.5f;
    cout << "before swap (float): f1 = " << f1 << ", f2 = " << f2 << endl;
    swapValues(f1, f2);
    cout << "after swap (float): f1 = " << f1 << ", f2 = " << f2 << endl;

    return 0;
}