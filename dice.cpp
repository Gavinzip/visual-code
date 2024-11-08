#include <iostream>
#include <string>
using namespace std;
int main() {
    int input;
    string north = "north";
    string south = "south";
    string east = "east";
    string west = "west";
    
    
    while(cin >> input){
        int n = 2, s = 5, w = 3, e = 4, t = 1, b = 6;
        if (input == 0) {
        return 0;
        }
    for (int i = 0;  i< input; i++) {
        string dir;
        int temp;
        
        cin >> dir;
        
    if (dir == north) {
        temp = b;
        b = n;
        n = t;
        t = s;
        s = temp;
    } 
    else if (dir == south) {
        temp = b;
        b = s;
        s = t;
        t = n;
        n = temp;
    } 
    else if (dir == west) {
        temp = b;
        b = w;
        w = t;
        t = e;
        e = temp;
    } 
    else if (dir == east) {
        temp = b;
        b = e;
        e = t;
        t = w;
        w = temp;
    }
    }
    cout << t << endl;
}
return 0;
}
