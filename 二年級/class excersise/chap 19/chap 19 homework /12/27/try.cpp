#include<iostream>
#include<string>
using namespace std;

int main(){
    int a,b;
    cout << "輸入被除數";
    cin >> a;
    cout << "輸入除數";
    while (cin >> b) //除數 不能為0
    {
        try{
            if (b==0){
                throw "除數不能為0,請重新輸入";
            }
            else{
                throw a/b;
            }
        }
        catch(int out){
            cout << "答案為" << out <<endl;
            break;
        }
        catch(const char * s){
            cout << s  << endl;
        }
    }
    
    
}