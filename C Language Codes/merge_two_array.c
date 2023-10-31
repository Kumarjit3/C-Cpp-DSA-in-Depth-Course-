#include<stdio.h>
#include<stdlib.h>

void f1();

int* merge(int arr[],int,int brr[],int);
int* merge1(int arr[],int,int brr[],int);

int main()
{
    f1();
    printf("\n");
    return 0;
}

void f1()
{
    int a[]={3,4,7,8,9,10};
    int b[]={1,2,5,6};
    int*ptr,i;
    ptr=merge1(a,6,b,4);
    printf("\n");
    for(i=0; i<10; i++) { printf("%d ",ptr[i]); }
}

int* merge(int arr[],int n1,int brr[],int n2)
{
    int *p,i,j,k=-1,n=n1,temp;
    p=(int*)calloc((n1+n2),sizeof(int));
    for(i=0; i<=1; i++)
    {
       for(j=0; j<n; j++)
       {
          if(i==0) 
          {
             p[++k]=arr[j];
          }
          else
          {
            p[++k]=brr[j];
          }
       }
    }
    n=n1+n2;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(p[j]<p[i])
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
    return p;
}


int* merge1(int arr[],int n1,int brr[],int n2)
{
     int *p,i,j,k,m=0;
     p=(int*)calloc((n1+n2),sizeof(int));
     for(i=0,j=0,k=0; i<n1&&j<n2; k++)
     {
       if(arr[i]<brr[j]) //3,4,7,8,9,10
       {
         p[m++]=arr[i];
         i++;            //1,2,3,4,5,6,7,8,9,10
       }
       if(arr[i]>brr[j]) //1,2,5,6
       {
         p[m++]=brr[j];
         j++;
       }
     }
     while(i<n1)
     {
        p[m++]=arr[i];
        i++;
        k++;
     }
     while(j<n2)
     {
        p[m++]=brr[j];
        j++;
        k++;
     }
    return p;
}