#include<iostream>
using namespace std;

int main()
{
    int i=1;
    ifs:
    if(i<=100)
    {
        cout<<" "<<i++<<" ";
        goto ifs;
    }    
}