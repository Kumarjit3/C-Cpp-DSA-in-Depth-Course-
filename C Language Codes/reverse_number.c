#include<stdio.h>

int  main()
{
    int n,k=0,r;
    printf("Enter a number:- ");  scanf("%d",&n);
    while (n!=0)
    {
        r=n%10;
        n=n/10;
        k=k*10+r;
    }
    printf("The current value of N is:- %d",k);
    return 0;
}