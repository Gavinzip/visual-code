#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<char,int>  & a,const pair<char,int>  & b){
    return a.second > b.second ||  (a.second == b.second && a.first < b.first);
}

int main(){
    int num;
    cin >> num;
    cin.ignore();
        string total;
        string temp;
        for (int i = 0; i <num; i++){
            getline(cin,temp);
            total+=temp;
        }
        vector <int> freq(26);
        for(char c : total){
            if (isalpha(c))
            {
               c=toupper(c);
               freq[c-'A']++; 
            }
            
            
        }
        vector<pair<char,int> > data;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                data.push_back(make_pair('A' + i, freq[i])); 
            }
        }
        sort(data.begin(),data.end(),compare);

        for(const auto& letter:data){
            cout << letter.first << " " << letter.second << endl;
        }
        
    

}