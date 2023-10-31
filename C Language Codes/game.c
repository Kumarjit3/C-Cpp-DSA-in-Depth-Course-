#include<stdio.h>
int main()
{
    
      int a,b,c,ch;
      do
      {
      printf("Enter any two number:- ");
      scanf("%d %d",&a,&b);
      printf("press 1 for addition\npress 2 for subtraction\npress 3 for divison\n press 4 for multiplication\n");
      printf("Chose between[1/2/3/4]:- ");
      scanf("%d",&ch);
      if(ch==1)
      {
        printf("%d",a+b);
      }
      if(ch==2)
      {
        printf("%d",a-b);
      }
      if(ch==3)
      {
        printf("%d",a/b);
      }
      if(ch==4)
      {
        printf("%d",a*b);
      }
      printf("\nPress 1 for continue and press 0 for exit:- ");
      scanf("%d",&c); 

       } while(c!=0);
       return 0;
}