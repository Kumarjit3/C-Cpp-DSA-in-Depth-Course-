#include<string>
#include<iostream>
using namespace std;

int CountVowels(string n,int l)
{
    int i=0,v=0;
    while(i<l)
    {
        if(n[i]=='a'|| n[i]=='e'|| n[i]=='i'|| n[i]=='o'|| n[i]=='u'|| 
          n[i]=='A'|| n[i]=='E'|| n[i]=='I'|| n[i]=='O'|| n[i]=='U') { v++; } i++;
    }
    return v;
}

int CountConsonants(string n,int l)
{
    int i=0,c=0,v;
    while(i<l)
    {   
        if(n[i]=='a'|| n[i]=='e'|| n[i]=='i'|| n[i]=='o'|| n[i]=='u'|| 
          n[i]=='A'|| n[i]=='E'|| n[i]=='I'|| n[i]=='O'|| n[i]=='U') {v++;}
        else if((n[i]>='a' && n[i]<='z')||(n[i]>='A' && n[i]<='Z'))  {c++;}
        i++;
    }
    return c;
}