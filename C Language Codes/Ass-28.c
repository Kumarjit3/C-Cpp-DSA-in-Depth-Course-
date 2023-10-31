#include<stdio.h>
void arrenge(char arr[],int);

int main()
{
    char arr[]={'A','B','C','D','E',' ',' ',' ',' ',' '};
    arrenge(arr,10);
    printf("\n");
    return 0;
}

void arrenge(char arr[],int n)
{
   int i,j,p=n-1,k=(n/2)-1; char crr[n];
   for(i=0; i<n; i=i+2)
   {
       crr[i]=arr[p];
       for(j=i+1; j<i+2; j++)
       {
       crr[j]=arr[k];
       }
       k--,p--;
   }
    printf("\n");
    printf("Before the arrengement the array looks like : \n"); 
   for(i=0; i<n; i++)
   {
    printf("%c",arr[i]);
   }
    printf("\n");
    printf("After the arrengement the array looks like : \n"); 
   for(i=0; i<n; i++)
   {
    printf("%c",crr[i]);
   }
}