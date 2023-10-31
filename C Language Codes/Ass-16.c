#include<stdio.h>

void firstN(int);

int main()
{
    int n=3;
   firstN(n);
   printf("\n");
   return 0;
}

void firstN(int c)
{
    if(c>0)
    {
    firstN(c-1);
    printf("%d ",c);
    }
}