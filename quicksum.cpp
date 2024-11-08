#include <iostream>
 using namespace std;

 int main(){
    char input[256];
    while (cin.getline(input, 256))
    {
        if (input[0]=='#')
        {
            return 0;
        }
        
        int out=0;
        int ascii;
        for (size_t i = 0; i < strlen(input); i++)
            if (input[i]==' '){
                ascii=0;
            }
            else
            ascii=input[i]-64;

            out+=(i+1)*ascii;
        }
        cout << out << endl;
    }
    return 0;
 }