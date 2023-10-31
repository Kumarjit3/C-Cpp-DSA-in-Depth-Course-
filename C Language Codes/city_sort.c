#include<stdio.h>
#include<string.h>


void sort(char arr[10][20],int n)
{
      int i,j; char temp[20];
      for(j=0; j<n-1; j++)
      {
        for(i=0+j; i<n; i++)
        {
          if(strcmp(arr[j],arr[i]) > 0) 
          { strcpy(temp,arr[j]); strcpy(arr[j],arr[i]); strcpy(arr[i],temp); }
        }
      }
}

void output(char arr[10][20],int n)
{
    int i;
    printf("The sorted wise city's are:- \n");
    for(i=0; i<n; i++)
    {
        puts(arr[i]);
    }
}

int main()
{
    char arr[10][20]; 
    int i,n;
    printf("Enter the number of city:- ");  
    scanf("%d",&n);
    printf("Enter the %d city name:- \n",n);
    for(i=0; i<n; i++) { scanf("%s",arr[i]); }
    sort(arr,n);
    output(arr,n);
    return 0;
}