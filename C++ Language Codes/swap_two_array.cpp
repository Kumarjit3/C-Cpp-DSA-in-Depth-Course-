void array_swap(int[],int,int[],int);
void output(int crr[],int);
#include<iostream>
using namespace std;

int main()
{
   int arr[20],brr[20],n1,n2,i;
   cout<<"Enter the lenght of the first aray:- ";
   cin>>n1;
   cout<<"Enter the lenght of the second aray:- ";
   cin>>n2;
   cout<<"Enter the "<<n1<<" array elements of the first array:- "<<endl;
   for(i=0; i<n1; i++) { cin>>arr[i]; }
   cout<<"Enter the "<<n2<<" array elements of the second array:- "<<endl;
   for(i=0; i<n2; i++) { cin>>brr[i]; }
   output(arr,n1);  output(brr,n2);
   array_swap(arr,n1,brr,n2);
   return 0;
}

void array_swap(int arr[],int l1,int brr[],int l2)
{
    int i,j=0,k=0,temp[20]; 
    for(i=0; i<l1; i++) {  temp[i]=arr[i]; }   
    for(i=0; i<l2; i++) {  arr[j++]=brr[i];  }  
    for(i=0; i<l1; i++) {  brr[k++]=temp[i]; }
    output(arr,l2); output(brr,l1);
}


void output(int crr[],int n)
{
    int i;
    cout<<"Now the Array looks like:- "<<endl;
    for(i=0; i<n; i++) { cout<<" "<<crr[i];  }
    cout<<endl;
}
