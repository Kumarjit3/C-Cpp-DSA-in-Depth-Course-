#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void scan_f(char str[],char*,char*);

int main()
{
    char a,b;
    printf("Enter a number:- ");
    scan_f("%c%c",&a,&b);
    printf("A = %c B = %c",a,b);
    printf("\n");
    return 0;
}

void scan_f(char str[30],char *p,char *q)
{
     if(str[0]=='%')
      { 
         if(str[1]=='c')
         {
            *p=getchar();
         }
         if(str[2]=='%' && str[3]=='c')
          {
             *q=getchar();
          }
      }
}
