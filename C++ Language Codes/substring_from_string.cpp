void sub_string(char ssr[],int,int='\0');

#include<iostream>
using namespace std;

int main()
{
    char str[30]; int i;
    cout<<"Enter a string:- ";
    fgets(str,30,stdin);
    sub_string(str,3);
    return 0;
}

void sub_string(char str[],int f,int l)
{
    int i;
    if(l!='\0'){ l=l+1; } else { l=l-1; }
    for(i=f; str[i]!=str[l]; i++)
    {
        cout<<str[i];
    }
}