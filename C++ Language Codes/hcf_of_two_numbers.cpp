void hcf(int,int);

#include<iostream>
using namespace std;

/*int main()
{
    int a,b;
    cout<<"Enter two numbers:- ";
    cin>>a>>b;
    hcf(a,b);
    return 0;
}

void hcf(int a,int b)
{
    int i=2,hcf=1,p,k=0,m=0,big;
    if(a>b) { big=a;} else {big=b;}
        while(i<=big)
        {
            if(a%i==0 && b%i==0) 
            {
                a=a/i; b=b/i;
                hcf=hcf*i;
            }
            else
            {
                i++;
            }
        }
        cout<<endl<<"HCF = "<<hcf<<endl;
}*/

int main()
{
    float c; int a=40,b=30;
    c=a/b;
    cout<<c;
}
