#include<iostream>
using namespace std;


void stringInput()
{
  char ch,*q; int i,n=1;
  cout<<"Enter a string : ";
  do
  {
    char *p=new char;
    ch=getchar();
    *p=ch;
    *(p+1)='\0';
    for(i=0; i<=n; i++)
    {
      *(q+i)=*(p+i);
    }
    delete(p);
    n++;
    p++;
  } while (ch!='\n');

}

int main()
{
    stringInput();
    cout<<endl; 
    return 0;
}