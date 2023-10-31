#include<iostream>
using namespace std;
void swap(int*,int*);

int main()
{
    int a=5,b=1;
    cout<<"A : "<<a<<" B : "<<b<<endl;
    swap(&a,&b);
    cout<<"A : "<<a<<" B : "<<b<<endl;
    cout<<endl;
    return 0;
}

void swap(int *a,int *b)
{
    int t;
     t=*a;
     *a=*b;
     *b=t;
}
     