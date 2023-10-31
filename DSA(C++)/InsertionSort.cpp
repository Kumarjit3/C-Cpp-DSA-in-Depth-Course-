#include<iostream>
using namespace std;

class Isort
{
    private:
            int *arr;
            int size;    
    public: 
            Isort() : arr(NULL),size(0) { }
            Isort(int);
            void printArray();
            void TakeArray(int);
            void InsertionSort();
            ~Isort();

};

Isort::Isort(int n)
{
    size=n;
    arr=new int[n];
}

Isort::~Isort()
{
    if(arr!=NULL)
    delete []arr;
}

void Isort::TakeArray(int n)
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

void Isort::printArray()
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

void Isort::InsertionSort()
{
    int temp,j=0;
    for(int i=0; i<size-1; i++)
    {
        temp=arr[i+1];
            for(int k=i; k>=0; --k)
            {
                if(arr[k]>temp)
                {
                    arr[k+1]=arr[k];
                }
                else
                {
                    ++j;
                    arr[k+j]=temp;
                }
            }
            if(j==0)
            {
               arr[0]=temp;
            }
            j=0;
    }
}


int main()
{
    system("cls");
    Isort b1;
    b1.TakeArray(7);
    b1.printArray();
    b1.InsertionSort();
    b1.printArray();
    cout<<endl;
    return 0;
}