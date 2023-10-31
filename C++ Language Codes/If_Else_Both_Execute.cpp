#include<iostream>
using namespace std;

int main()
{ 
    bool input = 1;
    if(input==1)
    {
       cout<<"\nHello From If Block\n";
       goto ELSE;
    }
    else
    {
        ELSE:
        cout<<"\nHello From Else Block\n";
    }
    cout<<endl;
    return 0;
}