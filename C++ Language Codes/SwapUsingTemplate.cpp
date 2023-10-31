#include<iostream>
using namespace std;

template <typename X>

X IsBig(X a, X b)
{
    if(a>b)
    return a;
    else
    return b;
}

int main()
{
    cout<<IsBig(2,3)<<endl;
    cout<<IsBig(3.4,4.2)<<endl;
}