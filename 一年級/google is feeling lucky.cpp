#include <iostream>
using namespace std;

int main()
{

    struct ggf
   {
       string name;
       int v;
   };

    int t,cs=1;
    cin>>t;

    while(t-- )
{
    struct ggf web[10];
    int mx=-1;

    for(int i=0;i<10;i++)
    {
    cin>>web[i].name>>web[i].v;
    mx=max(mx,web[i].v);
    }
    cout<<"Case #"<< cs++ <<":\n";
    for(int i=0;i<10;i++)
    {
        if(web[i].v==mx)
        cout<<web[i].name<<endl;
    }
    }
    return 0;
}
