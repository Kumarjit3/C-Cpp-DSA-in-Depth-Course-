#include<iostream>
#include<list>
using namespace std;

int main()
{
    //How to create list object ?

    list<int> l1 = {30,60,20,40};
    list<int> l2;

    //How to access list elements
    //[] and at() are not there in list

    //1. Implicit Iterator
    for(auto X:l1)
    {
        cout<<X<<" ";
    } 
    cout<<endl;

    //2. Explicit Iterator
    list<int>::iterator it;
    for(it=l1.begin(); it!=l1.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;

    cout<<l1.back()<<endl;
    cout<<l1.front()<<endl;
    

    cout<<endl;
    return 0;
}