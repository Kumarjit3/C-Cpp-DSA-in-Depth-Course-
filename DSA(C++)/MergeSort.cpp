#include<iostream>
using namespace std;

class Array
{
    private:
        int *arr;
        int size;
    public:
        Array():arr(NULL),size(0) { }
        void CreateArray(int);
        void PrintArray();
        void Merge(); 
        void MergeSort();   
        ~Array();
};

Array::~Array()
{
    delete []arr;
    arr=NULL;
    cout<<endl;
}

void Array::CreateArray(int n)
{
    arr=new int[n];
    size=n;
    cout<<endl<<"Enter "<<n<<" Array Elements :-  \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}

void Array::PrintArray()
{
    cout<<endl<<"The "<<size<<" Array Elements Are:-  \n";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Array::Merge()
{
     
}


int main()
{
    system("cls");
    Array a1;
    int n;
    cout<<"Enter The Size of The Array :- ";
    cin>>n;
    a1.CreateArray(n);
    a1.PrintArray();
    cout<<endl;
    return 0;
}


