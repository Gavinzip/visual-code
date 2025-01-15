#include <iostream>
using namespace std;

class Animal {
public:
    virtual void dosomething() { 
        cout << "Animal does something." << endl;
    }
};

class Fish : public Animal {
public:
    void dosomething() override { 
        cout << "Fish swims." << endl;
    }
};

int main() {
    Animal* jack = new Fish;
    jack->dosomething(); 
    delete jack;
    return 0;
}