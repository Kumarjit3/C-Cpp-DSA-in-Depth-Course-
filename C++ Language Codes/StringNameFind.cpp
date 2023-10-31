#include<iostream>
#include<string.h>
using namespace std;


void name(int n)
{
     int i=0,k=0;
     char names[n][30];
    while(i<n)
    {
      cout<<endl<<"Enter The Name : ";
       fflush(stdin);
      cin.getline(names[k++],30); i++;
    } 
    
    for(int i=0; i<n; i++)
    {
        if(names[i][0]=='A' || names[i][0]=='B')
        cout<<endl<<names[i];
    }

}


int main()
{
   system("cls");
   int n;
   cout<<endl<<"Enter How Many you want to store : ";  cin>>n;
   name(n);
    cout<<endl;
    return 0;
}