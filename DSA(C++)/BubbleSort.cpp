#include<iostream>
using namespace std;

class Bsort
{
    private:
            int *arr;
            int size;
    protected:
            void swap(int&,int&);        
    public: 
            Bsort() : arr(NULL),size(0) { }
            Bsort(int);
            void printArray();
            void TakeArray(int);
            void BubbleSort();
            ~Bsort();

};

Bsort::Bsort(int n)
{
    size=n;
    arr=new int[n];
}

Bsort::~Bsort()
{
    if(arr!=NULL)
    delete []arr;
}

void Bsort::swap(int &A,int &B)
{
    int c=A;
    A=B;
    B=c;
}

void Bsort::TakeArray(int n)
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

void Bsort::printArray()
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

void Bsort::BubbleSort()
{
    for(int i=0; i<this->size-1; i++)
    {
        for(int j=i+1; j<this->size; j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}


int main()
{
    system("cls");
    Bsort b1;
    b1.TakeArray(7);
    b1.printArray();
    b1.BubbleSort();
    b1.printArray();
    cout<<endl;
    return 0;
}

