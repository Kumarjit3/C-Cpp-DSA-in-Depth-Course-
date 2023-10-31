#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int,4> a1 = {2,1,3,4};
    array<string,3> s1 = {"Kumar","Niloy","Arun"}; 
    for(int i:a1)    //by using int
    {
      cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:s1) //by using auto
    {
      cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
