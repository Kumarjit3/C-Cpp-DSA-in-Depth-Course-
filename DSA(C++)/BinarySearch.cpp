#include<iostream>
using namespace std;

void InsertData(int[],int);
void Display(int[],int);
void BinarySearch(int[],int,int);
void AscendingOrderSort(int[],int);
void DescendingOrderSort(int[],int);
bool CheckSortedA(int[],int);
bool CheckSortedD(int[],int);

int main()
{
    //For Clear The Whole During Run Time Of The Program----->
    system("cls");

    //Declear Variables----->
    int size,item; int *ptr=NULL;

    //Array Creation Content----->
    cout<<endl<<"Enter The Size Of The Array :- ";
    cin>>size;
    ptr = new int[size];
    cout<<endl<<"\n\tArray Successfully Created\n\n";
 
    //Array Data Insertion Content----->
    InsertData(ptr,size);
    cout<<endl<<"\n\tArray Elements Successfully Inserted\n\n";    
   
    //Display Array Elements----->
    Display(ptr,size);

    //BinarySearch Algorithm----->
    cout<<endl<<"\nEnter The Search Elements :- ";
    cin>>item;     
    BinarySearch(ptr,size,item);

    cout<<endl;
    return 0;
}


void InsertData(int arr[],int n)
{
    cout<<endl<<"Enter "<<n<<" Array Elements : \n";
    for(int i=0; i<n; i++)
    {
        cout<<endl<<"Arr["<<i<<"] :- ";
        cin>>arr[i];
    }
    cout<<endl;
}

void Display(int crr[],int p)
{
    cout<<endl<<"The "<<p<<" Array Elements Are looks Like : \n";
    cout<<endl<<"   -----------------";    
    cout<<endl<<"     Index | Value";
    cout<<endl<<"   -----------------";
    for(int i=0; i<p; i++)
    {
        cout<<endl<<"\t "<<i<<" | "<<crr[i]<<" ";
    }
    cout<<endl;
}

bool CheckSortedA(int trr[],int u)
{
    for(int i=0; i<u-1; i++)
    {
        if(trr[i]>trr[i+1])
        return false;
    }
    return true;
}

bool CheckSortedD(int trr[],int u)
{
    for(int i=0; i<u-1; i++)
    {
        if(trr[i]<trr[i+1])
        return false;
    }
    return true;
}


void AscendingOrderSort(int err[],int b)
{
    for(int i=0; i<b-1; i++)
    {
        for(int j=i+1; j<b; j++)
        {
            if(err[i]>err[j])
            {
                int temp=err[i];
                err[i] = err[j];
                err[j] = temp; 
            }
        }
    }
    cout<<endl;
    Display(err,b);
    cout<<endl;
}


void DescendingOrderSort(int srr[],int a)
{
    for(int i=0; i<a-1; i++)
    {
        for(int j=i+1; j<a; j++)
        {
            if(srr[i]<srr[j])
            {
                int temp=srr[i];
                srr[i] = srr[j];
                srr[j] = temp; 
            }
        }
    }
    cout<<endl;
    Display(srr,a);
    cout<<endl;
}

void BinarySearch(int arr[],int size,int key)
{
    int A=0,D=0;
    char Final;

    A = CheckSortedA(arr,size);
    D = CheckSortedD(arr,size);
    
    if(A==0 && D==0)
    {
        int enter;
        cout<<endl<<"\tArray Is Not Sorted!\n";
        cout<<endl<<"Enter In What Order You Want Sort Array Elements : \n";
        cout<<endl<<"1. Ascending Order Sort______________";
        cout<<endl<<"2. Descending Order Sort_____________";
        cout<<endl<<"3. Dont Want Any Kind Of Sort________";
        cout<<endl<<"4. I Want To Exit____________________";
        cout<<endl<<"\nEnter Your Choice In Between[1/2/3/4] :- ";
        cin>>enter;
        if(enter == 1)
        {
            AscendingOrderSort(arr,size);
            A=1;
        }
        else if(enter == 2)
        {
            DescendingOrderSort(arr,size);
            D=1;
        }
        else if(enter == 3)
        {
            cout<<endl<<"Sorry! Unable To Perform Binary Search Your Array Is Not Sorted yet\n\n"<<endl;
            exit(1);
        }
        else
        {
            cout<<endl<<"\n\n\nExit__________________________________________________\n\n\n"<<endl;
            exit(1);
        }
    }

    if(A==1)
    {
        Final='A';
    }
    else
    {
        Final='D';
    }


     if(Final == 'A')
     {
        int l=0,u=size-1;
        int m=(l+u)/2;
        while(1)
        {
            if(arr[m] == key)
            {
                cout<<endl<<"\nItem "<<key<<" Is Found At "<<m<<" Index\n"<<endl;
                break;
            }
            else if(key < arr[m])
            {
                u=m-1;
            }
            else
            {
                l=m+1;
            }
            m=(l+u)/2;
        }
     }


     if(Final == 'D')
     {
        int l=0,u=size-1;
        int m=(l+u)/2;
        while(1)
        {
            if(arr[m] == key)
            {
                cout<<endl<<"\nItem "<<key<<" Is Found At "<<m<<" Index\n"<<endl;
                break;
            }
            else if(key > arr[m])
            {
                u=m-1;
            }
            else
            {
                l=m+1;
            }
            m=(l+u)/2;
        }
     }
    cout<<endl;
}
