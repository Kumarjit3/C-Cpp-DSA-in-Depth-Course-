void input();
void merge(int array1[],int array2[],int);
void output(int array[],int);

#include<iostream>
using namespace std;

int main()
{
    input();
    return 0;
}

void input()
{
    int arr[20],brr[20],i,n;
    cout<<"Enter the length of the both array:- ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers of the first array :- "<<endl;
    for(i=0; i<n; i++) { cin>>arr[i]; }
    cout<<"Enter "<<n<<" numbers of the second array :- "<<endl;
    for(i=0; i<n; i++) { cin>>brr[i]; }
    cout<<"The first array looks like:- "<<endl;
    output(arr,n); 
    cout<<"The second array looks like:- "<<endl;
    output(brr,n); 
    merge(arr,brr,n); 
}

void output(int crr[],int n)
{
    int i;
    for(i=0; i<n; i++)  { cout<<" "<<crr[i]; }
    cout<<endl;
}

void merge(int a[],int b[],int l)
{
    int i,n=l,j=0;
    l+=l;
    for(i=n; i<l; i++) { a[i]=b[j++]; }
    cout<<"After merge the array looks like:- "<<endl;
    output(a,l);
}