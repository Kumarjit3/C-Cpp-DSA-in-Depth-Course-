#include<iostream>
using namespace std;

template <typename X>

X s(X &A,X &B)
{
    X c;
    c=A;
    A=B;
    B=c;
} 

int main()
{
    system("cls");
   int a,b;
   cout<<endl<<"Enter 1st Integer Value : "; cin>>a;
   cout<<endl<<"Enter 2nd Integer Value : "; cin>>b;
   cout<<endl<<"Before Swap The Values Are "<<endl;
   cout<<endl<<a<<" : "<<b<<endl;
   s(a,b);
   cout<<endl<<"After Swap The Values are "<<endl;
   cout<<endl<<a<<" : "<<b<<endl;
   cout<<endl;
   char x,y;
   cout<<endl<<"Enter 1st Character Value : "; cin>>x;
   cout<<endl<<"Enter 2nd Character Value : "; cin>>y;
   cout<<endl<<"Before Swap The Values Are "<<endl;
   cout<<endl<<x<<" : "<<y<<endl;
   s(x,y);
   cout<<endl<<"After Swap The Values Are "<<endl;
   cout<<endl<<x<<" : "<<y<<endl;
   cout<<endl;
   float e,f;
   cout<<endl<<"Enter 1st Float Value : "; cin>>e;
   cout<<endl<<"Enter 2nd Float Value : "; cin>>f; 
   cout<<endl<<"Before Swap The Values Are "<<endl;
   cout<<endl<<e<<" : "<<f<<endl; 
   s(e,f);
   cout<<endl<<"After Swap The Values Are "<<endl;
   cout<<endl<<e<<" : "<<f<<endl;
   cout<<endl;
   return 0;
}