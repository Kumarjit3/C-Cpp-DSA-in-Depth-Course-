#include<iostream>
#include<string.h>
using namespace std;
void com(char str[],char temp[],int l,int k,int r,int i);


void f1(char str[],int r)
{
  int i=0,k=0;
  char temp[r+1];
   int l=strlen(str);  
   com(str,temp,l,k,r,i);
}

void com(char str[],char temp[],int l,int k,int r,int i)
{
  int j;
  for(j=i+1; j<=l-r+k+1; j++)
  {
      temp[k]=str[j-1];
      if(k+1==r)
      {
        temp[k+1]='\0';
        printf("%s\n",temp);
      }
      else
      {
        com(str,temp,l,k+1,r,j);
      }
  }
}


int main()
{
    char str[]="ABCDE";
    f1(str,3);
    //stringCombination(str,3);
    cout<<endl;
    return 0;
}