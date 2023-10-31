#include<iostream>
using namespace std;

void swap(int &a,int &b);

int main()
{
   int x,y;
   x++;
   cout<<"Enter the value of A : "; cin>>x;
   cout<<"Enter the value of B : "; cin>>y;
   cout<<endl<<"Before swap : A = "<<x<<" B = "<<y<<endl;
   swap(x,y);
   cout<<endl<<"After swap : A = "<<x<<" B = "<<y<<endl;
   cout<<endl;
   return 0;
}

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}