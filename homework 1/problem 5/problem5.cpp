#include <iostream>
using namespace std;

void swap1(int* a, int* b) {
    int temp = *a;  
    *a = *b;      
    *b = temp;    
}
void swap2(int& a, int& b) {
    int temp = b;   
    b = a;          
    a = temp;       
}

int main() {
    int a = 1;
    int b = 2;

    cout << "before swapping: a = " << a << ", b = " << b << endl;
    swap1(&a, &b);  
    cout << "after swap1 (pointer): a = " << a << ", b = " << b << endl;
    swap2(a, b);  
    cout << "after swap2 (reference): a = " << a << ", b = " << b << endl;

    return 0;
}