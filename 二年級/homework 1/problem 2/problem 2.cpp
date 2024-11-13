#include<iostream>

using namespace std;

namespace dimensionTwo {
    void print() {
        cout << "This is dimensionTwo.\n";
    }
}


namespace dimensionThree {
    void print() {
        cout << "This is dimensionThree.\n";
    }
}

int main() {
   
    using namespace dimensionTwo;
    print();  
    dimensionThree::print(); 

    return 0;
}