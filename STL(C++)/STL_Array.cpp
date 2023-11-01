#include<iostream>
#include<array>
using namespace std;

int main()
{
    //ways of creating array objects
    
    //1.
    array<int,4> a1 = {10,20,30,40};
    //2.
    array<int,4> a2=a1;
    //3.
    array<int,4> a3; //a3 container contain garbage values

    //ways of access array elements

    cout<<endl; 
    //1.By using for loop and subscript operator
    for(int i=0; i<4; i++)
    {
        cout<<a1[i]<<" ";
    }
    cout<<endl;

    //2.By using for loop and at() function
    for(int i=0; i<4; i++)
    {
        cout<<a2.at(i)<<" ";
    }
    cout<<endl;

    //3.By using implicit iterator or range-for loop
    for(int X:a1) //we also can use auto at the place of int
    {
        cout<<X<<" ";
    }
    cout<<endl;
    
    //4.By using explicit iterator
    array<int,4>::iterator i1; //creating i1 explicit iterator
    for(i1=a1.begin(); i1!=a1.end(); i1++)
    {
        cout<<(*i1)<<" ";
    }
    cout<<endl;

    //4.1 explicit reverse_iterator
    array<int,4>::reverse_iterator i2; //creating i2 explicit iterator
    for(i2=a1.rbegin(); i2!=a1.rend(); i2++)
    {
        cout<<(*i2)<<" ";
    }
    cout<<endl;
    return 0;
}
