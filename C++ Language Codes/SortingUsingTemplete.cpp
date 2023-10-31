#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
int menu();
void q1();
void q2();
void q3();
void q4();
void q5();

template<typename T>
void bubblesort(T arr[],int);
template<typename T>
void mergesort(T arr[],int,int);
template<typename T>
void merge(T arr[],int,int,int);
template<typename T>
void insertionsort(T arr[],int);
template<typename T>
void selectionsort(T arr[],int);
template<typename T>
void quicksort(T arr[100],int,int);


template<typename T>
void bubblesort(T arr[], int n)
{
    int i,j;  T temp;
    
    for(i=0; i<n; i++)
    {
    	for(j=0; j<n-1; j++)
    	{
    		if(arr[j] > arr[j+1])
    		{
    			temp = arr[j];
    			arr[j] = arr[j+1];
    			arr[j+1] = temp;
			}
		}
	}
}

template<typename T>
void insertionsort(T arr[],int n)
{
	int i,j;  T temp;
	for(i=1; i<n; i++)
	{
		temp = arr[i];
		for(j=i; j>0 && temp<arr[j-1]; j--)
		{
			arr[j] = arr[j-1];
		}
		  arr[j] = temp;
	}
}

template<typename T>
void selectionsort(T arr[],int n)
{
	int i,j,position; T temp;
	for(i=0; i<n; i++)
	{
		position = i;
		for(j=i+1; j<n; j++)
		{
			if(arr[position] > arr[j])
			{
				position = j;
			}
		}
	     	temp = arr[i];
			arr[i] = arr[position];
			arr[position] = temp;
	}
}

template<typename T>
void quicksort(T arr[100],int first, int last)
{
	int i,j,pivot;
	
    if(first<last)
    {
    pivot=first;
    i=first;
    j=last;
    
    while(i<j)
    {
    while(arr[i]<=arr[pivot])
    {
        i++;
    }
    while(arr[j]>arr[pivot])
    {
        j--;
    }
    if(i<j)
    {
    	swap(arr[i],arr[j]);
    }
    }
    swap(arr[j],arr[pivot]);
    
    quicksort(arr,first,j-1);
    quicksort(arr,j+1,last);
   }
}

template<typename T>
void swap(T &a,T &b)
{
	T t;
    t = a;
    a = b;
	b = t ;
}

template<typename T>
void mergesort(T arr[], int lb, int ub)
{
	if(lb < ub)
	{
		int m = (lb + ub) / 2;
		mergesort(arr,lb,m);
		mergesort(arr,m+1,ub);
		merge(arr,lb,m,ub);
	}
}

template<typename T>
void merge(T arr[], int lb, int m, int ub)
{
	int i,j,k;
	int n1 = m+1;
	int n2 = ub -m;
	T L[n1],R[n2];
	
	for(i=0; i<n1; i++)
	{
		L[i] = arr[lb+i];
	}
	for(j=0; j<n2; j++)
	{
		R[j] = arr[m+1+j];
	}
	i=0;
	j=0;
	k=lb;
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}	
} 


template<typename T>
void printarray(T arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
    cout<<endl;
}

void q1()
{
    int arr[100]; int n,i;	
	cout<<endl<<"Enter The Array Size:- ";
	cin>>n;
	cout<<endl<<"Enter The Array Elements:- ";
	for(i=0; i<n; i++)
	{
	  cin>>arr[i];
    }
    cout<<endl<<"Before Bubble sorting :- ";
    printarray(arr,n);
    bubblesort(arr,n);
    cout<<endl<<"After Bubble sorting :- ";
    printarray(arr,n);
}

void q2()
{
    float arr[100]; int n,i;	
	cout<<endl<<"Enter The Array Size:- ";
	cin>>n;
	cout<<endl<<"Enter The Array Elements:- ";
	for(i=0; i<n; i++)
	{
	  cin>>arr[i];
    }
    cout<<endl<<"Before Insertion sorting :- ";
    printarray(arr,n);
    insertionsort(arr,n);
    cout<<endl<<"After Insertion sorting :- ";
    printarray(arr,n);
}

void q3()
{
    double arr[100]; int n,i;	
	cout<<endl<<"Enter The Array Size:- ";
	cin>>n;
	cout<<endl<<"Enter The Array Elements:- ";
	for(i=0; i<n; i++)
	{
	  cin>>arr[i];
    }
    cout<<endl<<"Before Selection sorting :- ";
    printarray(arr,n);
    selectionsort(arr,n);
    cout<<endl<<"After Selection sorting :- ";
    printarray(arr,n);
}

void q4()
{
    char arr[100]; int n,i;	
	cout<<endl<<"Enter The Array Size:- ";
	cin>>n;
	cout<<endl<<"Enter The Array Elements:- ";
	for(i=0; i<n; i++)
	{
	  cin>>arr[i];
    }
    cout<<endl<<"Before Merge sorting :- ";
    printarray(arr,n);
    mergesort(arr,0,n-1);
    cout<<endl<<"After Merge sorting :- ";
    printarray(arr,n);
}

void q5()
{
    int arr[100]; int n,i;	
	cout<<endl<<"Enter The Array Size:- ";
	cin>>n;
	cout<<endl<<"Enter The Array Elements:- ";
	for(i=0; i<n; i++)
	{
	  cin>>arr[i];
    }
    cout<<endl<<"Before Quick sorting :- ";
    printarray(arr,n);
    quicksort(arr,0,n);
    cout<<endl<<"After Quick sorting :- ";
    printarray(arr,n);
}


int menu()
{
    int k;
    cout<<endl<<"\tSORTING USING TEMPLETE"<<endl;
    cout<<endl<<"ENTER 1 FOR BUBBLE SORT USING TEMPLETE :";
    cout<<endl<<"ENTER 2 FOR INSERTION SORT USING TEMPLETE :";
    cout<<endl<<"ENTER 3 FOR SELECTION SORT USING TEMPLETE :";
    cout<<endl<<"ENTER 4 FOR MERGE SORT USING TEMPLETE :";
    cout<<endl<<"ENTER 5 FOR QUICK SORT USING TEMPLETE :";
    cout<<endl<<"ENTER 6 FOR EXIT :";
    cout<<endl<<"\nEnter Your Choice In Between[1/2/3/4/5/6] : ";
    cin>>k;
    return k;
}

int main()
{
    system("cls");
    while(1)
    {
    switch(menu())
    {
        case 1:
        {
            q1();
            break;
        }
        case 2:
        {
            q2();
            break;
        }
        case 3:
        {
            q3();
            break;
        }
        case 4:
        {
            q4();
            break;
        }
        case 5:
        {
            q5();
            break;
        }
        case 6:
        {
            cout<<endl<<"\nExit_____________________________\n"<<endl;
            exit(0);
            break;
        }
        default:
        {
            cout<<endl<<"Wrong Choice! Retry"<<endl;
            break;
        }
    }
    cout<<endl<<"Enter Any Key To Continue : ";
    getch();
    system("cls");
  }
    cout<<endl;
	return 0;
}