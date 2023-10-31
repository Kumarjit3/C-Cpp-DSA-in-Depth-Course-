#include<iostream>
using namespace std;

class fact
{
     double n;
     double f1(int);
};

double f1(double a)
{
    if(a>1)
    {
        a=(a*f1(a-1));
    }
    return a;
}

int main()
{
    double n;
   n=f1(4);  
   cout<<n;
}
