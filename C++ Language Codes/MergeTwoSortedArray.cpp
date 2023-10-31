#include<iostream>
using namespace std;

int* Merge(int *p,int n,int *q,int m)
{
    int i,j=0,k=0;  int *crr=new int[n+m];
    for(i=0; i<n+m; i++)
    {
       if(j<n)
       { 
       if(q[k]<=p[j]&&k<m)
       {
       crr[i]=q[k];
       k++;
       }
       else
       {
       crr[i]=p[j];
       j++;
       }
       }
       else
       {
          crr[i]=q[k];
          k++;
       }
    }
    cout<<endl;
    return crr; 
}

int main()
{
    system("cls");
    int arr[30],brr[30],size1,size2;
    cout<<endl<<"Enter The First Array Size : "; cin>>size1;
    cout<<endl<<"Enter The Second Array Size : "; cin>>size2;
    cout<<endl<<"Enter First Array "<<size1<<" Elements : "<<endl;
    for(int i=0; i<size1; i++)   
    {
     cout<<endl<<"Array["<<i<<"] = "; cin>>arr[i];
    }
    cout<<endl<<"Enter Second Array "<<size2<<" Elements : "<<endl;
    for(int i=0; i<size2; i++)
    {
     cout<<endl<<"Array["<<i<<"] = "; cin>>brr[i];
    }
    cout<<endl<<"Before The Merge Operstion The First Array Looks Like : "<<endl;
    for(int i=0; i<size1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Before The Merge Operstion The Second Array Looks Like : "<<endl;
    for(int i=0; i<size2; i++)
    {
        cout<<brr[i]<<" ";
    }
    int* ptr=Merge(arr,size1,brr,size2);
    cout<<endl<<"After Merge Operation The Array Looks Like : "<<endl;
    for(int i=0; i<size1+size2; i++)
    cout<<ptr[i]<<" ";
    cout<<"\n\n"<<endl;
    return 0;
}