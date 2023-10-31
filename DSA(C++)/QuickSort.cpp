#include<iostream>
using namespace std;

void PrintArray(int[],int);
int Quick(int[],int,int);
void QuickSort(int[],int,int);
void swap(int&,int&);


void swap(int &A,int &B)
{
    int C=A;
    A=B;
    B=C;
}

void PrintArray(int ptr[],int size)
{
    cout<<endl<<"The Current Array Looks Like :- \n"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"Ptr["<<i<<"]:- "<<ptr[i]<<endl;
    }
}


void QuickSort(int ptr[],int left,int right)
{
    
    if(left<right)
    {
        int loc=Quick(ptr,left,right);
        QuickSort(ptr,0,loc-1);
        QuickSort(ptr,loc+1,right);
    }    
}


int Quick(int ptr[],int left,int right)
{
    int n=right;
    int loc=left;

   while(left!=right)
   {
      if(left==loc)
      {
          if(ptr[left]<ptr[right])
          {
            right--;
          }
          else
          {
            swap(ptr[left],ptr[right]);
            loc=right;
          }
      }
      else
      {
          if(ptr[left]<ptr[right])
          {
            left++;
          }
          else
          {
            swap(ptr[left],ptr[right]);
            loc=left;
          }
      }
   }
   return loc;
}


int main()
{
    system("cls");
    int size; int *ptr;
    cout<<endl<<"Enter The Size Of The Array : "; cin>>size;
    ptr=new int[size];

    cout<<endl<<"Enter Total "<<size<<" Integers :- "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<endl<<"Ptr["<<i<<"]:- "; cin>>ptr[i];
    }
    cout<<endl;

    PrintArray(ptr,size);
    QuickSort(ptr,0,size-1);
    PrintArray(ptr,size);

    cout<<endl;
    return 0;
}