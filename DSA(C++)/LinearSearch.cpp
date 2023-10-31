#include<iostream>
using namespace std;

void InsertData(int[],int);
void Display(int[],int);
void LinearSearch(int[],int,int);


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

    //LinearSearch Algorithm----->
    cout<<endl<<"\nEnter The Search Elements :- ";
    cin>>item;     
    LinearSearch(ptr,size,item);

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


void LinearSearch(int crr[],int n,int item)
{
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(crr[i] == item)
        {
            k=1;
            cout<<endl<<"\nItem "<<item<<" Is Found At "<<i<<" Index\n"<<endl;
            break;
        }
    }
    if(k==0)
    cout<<endl<<"\nItem "<<item<<" Is Not Found\n"<<endl;
}