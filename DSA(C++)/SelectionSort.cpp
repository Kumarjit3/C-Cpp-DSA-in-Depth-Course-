#include<iostream>
using namespace std;

class Ssort
{
    private:
            int *arr;
            int size;
    protected:
            void swap(int&,int&);
            int min(int);        
    public: 
            Ssort() : arr(NULL),size(0) { }
            Ssort(int);
            void printArray();
            void TakeArray(int);
            void SelectionSortType1();
            void SelectionSortType2();
            ~Ssort();

};

Ssort::Ssort(int n)
{
    size=n;
    arr=new int[n];
}

Ssort::~Ssort()
{
    if(arr!=NULL)
    delete []arr;
}

void Ssort::swap(int &A,int &B)
{
    int c=A;
    A=B;
    B=c;
}

int Ssort::min(int j)
{
    int m=arr[j],k=j;
   for(int i=j+1; i<size; i++)
   {
     if(arr[i]<m)
     {
       m=arr[i];
       k=i;
     }
   }
   return k;
}

void Ssort::TakeArray(int n)
{
    size=n;
    arr=new int[n];
    cout<<endl<<"Enter Total "<<size<<" Array Elements : "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<endl<<"Arr["<<i<<"]:- "; cin>>arr[i];
    }
    cout<<endl;
}

void Ssort::printArray()
{
    if(arr==NULL)
       cout<<"Take Array First Array Is Empty"<<endl;
    else
    {
        cout<<endl<<"The Current Array Looks Like : "<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<endl<<"Arr["<<i<<"]:- "<<arr[i];
        }
    }
    cout<<endl;
}


void Ssort::SelectionSortType1()
{
    int temp,k;
    for(int i=0; i<size; i++)
    {
       temp=arr[i];
       k=min(i);
       cout<<"Min "<<k<<endl;
       arr[i]=arr[k];
       arr[k]=temp;
    }
}

void Ssort::SelectionSortType2()
{
    int k=0;
    for(int i=0; i<size-1; i++)
    {
        int temp=i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j]<arr[temp])
            {
                k=1;
                temp=j;
            }
        }
        if(k==1)
        {
            swap(arr[i],arr[temp]);
        }
        k=0;
    }
}


int main()
{
    system("cls");
    Ssort b1;
    b1.TakeArray(7);
    b1.printArray();
    b1.SelectionSortType2();
    b1.printArray();
    cout<<endl;
    return 0;
}