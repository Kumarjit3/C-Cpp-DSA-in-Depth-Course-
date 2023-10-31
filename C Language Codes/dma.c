#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void f1();

int main()
{
     f1();
     printf("\n");
     return 0;
}


void f1()
{
    int *p,size=1,i,k,m=0;
    p=(int*)malloc(size);
    p[0]='\0'; 
     printf("Enter numbers:- \n");
     while(1)
     {
        k=getchar();
        printf("k= %d ",k);
      if(k=='\n'); { break; }
    p=(int*)malloc(size);
    for(i=m; i<size; i++)
    {
        p[i]='k';
    }
    m=size;
    size++;
     }

     for(i=0; i<6; i++) { printf("\n%d ",p[i]); }
}