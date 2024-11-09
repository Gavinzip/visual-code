#include <iostream>
#include <stack>

using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        stack<char> s;
        char c;
        while (cin.get(c))
        {
            if(c == ' '){
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            }else if(c == '\n'){
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << endl;
                break;
            }else{
                s.push(c);
            }
        }
    }
    
}