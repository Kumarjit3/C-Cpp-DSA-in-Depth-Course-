#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Function Decleartions
void InsertData(int[],int);
void Display(int[],int);
void BinarySearch(int[],int,int);
void AscendingOrderSort(int[],int);
void DescendingOrderSort(int[],int);
bool CheckSortedA(int[],int);
bool CheckSortedD(int[],int);


int main()
{
    //For Clear The Whole Screen During Runtime Of The Program----->
    system("cls");

    //Declear Variables
    int size,item; int *ptr=NULL;

    //Array Creation
    printf("\nEnter The Size Of The Array :- ");
    scanf("%d",&size);
    ptr = (int*) malloc (size*sizeof(int));
    printf("\n\n\tArray Successfully Created\n\n");
 
    //Array Elements Insertion
    InsertData(ptr,size);
    printf("\n\tArray Elements Successfully Inserted\n\n");    
   
    //Display Array Elements
    Display(ptr,size);

    //Calling BinarySearch Function
    printf("\n\nEnter The Search Elements :- ");
    scanf("%d",&item);    
    BinarySearch(ptr,size,item);

    //Again Calling BinarySearch Function
    printf("\n\nEnter The Search Elements :- ");
    scanf("%d",&item);    
    BinarySearch(ptr,size,item);

    printf("\n\n\n");
    return 0;
}


void InsertData(int arr[],int n)
{
    printf("\nEnter %d Array Elements : \n",n);
    for(int i=0; i<n; i++)
    {
        printf("\nArr[%d] :- ",i);
        scanf("%d",&arr[i]);
    }
     printf("\n");
}

void Display(int crr[],int p)
{
    printf("\nThe %d Array Elements Are looks Like : \n",p);
    printf("\n   -----------------");    
    printf("\n     Index | Value");
    printf("\n   -----------------");
    for(int i=0; i<p; i++)
    {
        printf("\n\t %d | %d ",i,crr[i]);
    }
    printf("\n");
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
    printf("\n\tNow The Array Is Sorted\n");
    Display(err,b);
    printf("\n");
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
    printf("\n\tNow The Array Is Sorted\n");
    Display(srr,a);
    printf("\n");
}

void BinarySearch(int arr[],int size,int key)
{
    int A=0,D=0;
    char Final='\0';

    A = CheckSortedA(arr,size);
    D = CheckSortedD(arr,size);
    
    if(A==0 && D==0)
    {
        int enter;
        printf("\n\tArray Is Not Sorted!\n");
        printf("\nEnter In What Order You Want Sort Array Elements : \n");
        printf("\n1. Ascending Order Sort______________");
        printf("\n2. Descending Order Sort_____________");
        printf("\n3. Dont Want Any Kind Of Sort________");
        printf("\n4. I Want To Exit____________________");
        printf("\n\nEnter Your Choice In Between[1/2/3/4] :- ");
        scanf("%d",&enter);
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
            printf("\nSorry! Unable To Perform Binary Search Your Array Is Not Sorted yet\n\n");
            exit(1);
        }
        else
        {            
            printf("\n\n\nExit__________________________________________________\n\n\n");
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
        int l=0,u=size-1,k=0;
        int m=(l+u)/2;
        while(u >= l)
        {
            if(arr[m] == key)
            {
                k=1;
                printf("\n\nItem %d Is Found At %d Index\n\n",key,m);
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
        if(k==0)
        {
            printf("\n\nItem %d Is Not Found\n\n",key);
        }
     }

     if(Final == 'D')
     {
        int l=0,u=size-1,k=0;
        int m=(l+u)/2;
        while(u >= l)
        {
            if(arr[m] == key)
            {
                k=1;
                printf("\nItem %d Is Found At %d Index\n\n",key,m);
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
        if(k==0)
        {
            printf("\n\nItem %d Is Not Found\n\n",key);
        }
     }
      printf("\n\n");
}