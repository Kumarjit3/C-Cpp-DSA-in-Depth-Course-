#include<iostream>
using namespace std;

void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q8();
void q9();
void q10();

int* sortArray(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}

int greatestElement(int arr[],int n)
{
    int big=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>big)
        big=arr[i];
    }
    return big;
}

int smallestElement(int arr[],int n)
{
    int small=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]<small)
        small=arr[i];
    }
    return small;
}

int searchElement(int arr[],int n,int e)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==e)
        return i;    //returning index
    }
    return -5;
}

int sumArray(int arr[],int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int averageArray(int arr[],int n)
{
    int sum=0,avg;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    avg=(sum/n);
    return avg;
}

void showArray(int arr[],int n)
{
    cout<<endl<<n<<" Array Elements Are : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int* rotateArray(int arr[],int n)
{
    int temp=arr[n-1];
    for(int i=n-1; i>0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    return arr;
}

void deletee(int arr[],int n,int k)
{
    if(k==n-1)
    {
        arr[n]=arr[k];  //n--
        n--;
    }
    else
    {
       for(int i=k; i<n; i++)
       {
          arr[i]=arr[i+1]; //n--
       }
       n--;
    }
}

int* removeDuplicate(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        int temp=arr[i];
       for(int j=0; j<n; j++)
       {
         if(temp==arr[j] && i!=j)
         {
            deletee(arr,n,i);  
         }
       }
    }
    return arr;
}

int secondLargestElement(int arr[],int n)
{
    int big=0,sbig=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>big)
        big=arr[i];
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]>sbig && arr[i]!=big)
        {
            sbig=arr[i];
        }
    }
    return sbig;
}

int* swapIndex(int arr[],int n,int i1,int i2)
{
    int t=arr[i2],tt=arr[i1];
    for(int i=0; i<n; i++)
    {
       if(i==i2)
       {
        arr[i]=tt;
       }
       if(i==i1)
       {
        arr[i]=t;
       }
    }
    return arr;
}

void q1()
{
    int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    int *ptr=sortArray(arr,10);
    showArray(ptr,10);
    cout<<endl;
}

void q2()
{
    int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    cout<<endl<<"Greatest Element Is : "<<greatestElement(arr,10);
    cout<<endl;
}


void q3()
{
    int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    cout<<endl<<"Smallest Element Is : "<<smallestElement(arr,10);
    cout<<endl;
}

void q4()
{
    int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    int i=searchElement(arr,10,3);
    if(i==-5)
    cout<<endl<<"Item Not Found";
    else
    cout<<endl<<"Item Found At "<<i<<" Index";
    cout<<endl;
}

void q5()
{
     int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    int i=sumArray(arr,10);
    cout<<endl<<"The Sum Of All The Array Elements Is : "<<i;
    cout<<endl;
}


void q6()
{
     int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    int i=averageArray(arr,10);
    cout<<endl<<"The Average Of All The Array Elements Is : "<<i;
    cout<<endl;
}

void q7()
{
    int arr[]={7,3,6,2,1,5,9,4,10,8};
    showArray(arr,10);
    int *ptr=rotateArray(arr,10);
    showArray(ptr,10);
    cout<<endl;
}

void q8()
{
    int arr[]={7,3,6,7,1,2,6,4,2,8};
    showArray(arr,10);
    int *ptr=removeDuplicate(arr,10);
    showArray(ptr,10);
    cout<<endl;
}

void q9()
{
    int arr[]={7,3,6,9,1,2,10,4,5,8};
    showArray(arr,10);
    cout<<endl<<"The 2nd largest number is : "<<secondLargestElement(arr,10);
    cout<<endl;
}

void q10()
{
    int arr[]={7,3,6,9,1,2,10,4,5,8};
    showArray(arr,10);
    int *ptr=swapIndex(arr,10,1,9);
    showArray(ptr,10);
    cout<<endl;
}

int main()
{
    system("cls");
    q1();
    q2();
    q3();
    q4();
    q5();
    q6();
    q7();
    q8();
    q9();
    q10();
    cout<<endl;
    return 0;
}