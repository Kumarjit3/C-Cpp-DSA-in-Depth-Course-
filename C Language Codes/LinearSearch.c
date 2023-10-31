#include<stdio.h>
#include<stdlib.h>

//Function Decleartions
void InsertData(int[],int);
void Display(int[],int);
void LinearSearch(int[],int,int);


int main()
{
    //For Clear The Whole Screen During Runtime Of The Program----->
    system("cls");

    //Declear Variables
    int size,item,*ptr=NULL;

    //Array Creation
    printf("\nEnter The Size Of The Array :- ");
    scanf("%d",&size);
    ptr = (int*) malloc (size*sizeof(int));
    printf("\n\tArray Successfully Created\n\n");
 
    //Array Elements Insertion
    InsertData(ptr,size);
    printf("\n\tArray Elements Successfully Inserted\n\n");    
   
    //Display Array Elements
    Display(ptr,size);

    //Calling LinearSearch Function
    printf("\nEnter The Search Elements :- ");
    scanf("%d",&item);    
    LinearSearch(ptr,size,item);

    //Again Calling LinearSearch Function
    printf("\nEnter The Search Elements :- ");
    scanf("%d",&item);    
    LinearSearch(ptr,size,item);
    
    printf("\n\n\n");
    return 0;

}


//Array Element Insertion Function
void InsertData(int arr[],int n)
{
    printf("\nEnter %d Array Elements : \n",n);
    for(int i=0; i<n; i++)
    {
        printf("\nArray[%d] :- ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");
}

//Array Element Display Function
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

//Linear Search Function
void LinearSearch(int crr[],int n,int item)
{
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(crr[i] == item)
        {
            k=1;
            printf("\n\nSearch Item %d Is Found At %d Index\n\n",item,i);
            break;
        }
    }
    if(k==0)
    printf("\n\nSearch Item %d Is Not Found\n\n",item);
}