#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<endl<<"Enter An Positive Integer(Use Odd number For Good Shape): ";
    cin>>n;
    int middle=n/2;
    int last=n-1;
    bool stop=0;
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i<middle)
            {
               if(j==0)
               {
                  cout<<"*";
               }
               else if(j==last)
               {
                 cout<<"*";
                 last--;
               }
               else
               {
                 cout<<" ";
               }
            }
            else
            {
               if(j==0)
               {
                  cout<<"*";
               }
               else if(j==last&&stop!=1)
               {
                 cout<<"*";
                 last++;
                 stop=1;
               }
               else
               {
                 cout<<" ";
               }
            }
        }
        stop=0;
         cout<<endl;
    }  
    cout<<endl;
}