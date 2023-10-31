#include<iostream>
using namespace std;

void HeapSort(int[],int);
void Display(int[],int);
void HeapInsert(int[],int);
void Delete(int[],int);

int main()
{
    system("cls");
    int n,*arr=NULL;
    cout<<endl<<"Enter The Array Size : ";
    cin>>n;
    arr = new int[n];
    cout<<endl<<"Enter "<<n<<" Array Elements :- \n";
    HeapInsert(arr,n);
    Display(arr,n);
    HeapSort(arr,n);
    Display(arr,n);
    return 0;
}


void HeapSort(int ptr[],int n)
{
    Delete(ptr,n); 
}

void HeapInsert(int ptr[],int n)
{
    int lastIndex = -1;
    for(int c=0; c<n; c++)
    {
    if(ptr!=NULL)
    {
       int item;
       cout<<endl<<"Enter The Item For Insert : ";
       cin>>item;
       ptr[++lastIndex]=item;
       if(lastIndex>0)
       {
           int last = lastIndex;
           int p = ((lastIndex-1)/2);
           while(1)
           {
             if(ptr[p]<ptr[last])
             {
               swap(ptr[p],ptr[last]);
             }
             else
             {
                break;
             }
             last = p;
             p = ((p-1)/2);
             if(p<0)
             {
                break;
             }
           }
       }
    }
    }
}


void Delete(int ptr[],int n)
{
    int lastIndex=n-1;
    for(int c=0; c<n; c++)
    {
    
    int i=0,t;
    if(lastIndex==0)
    {
         ptr[lastIndex]=ptr[i]; 
         break;
    }
    int parent=((lastIndex-1)/2);
    int lc=2*parent+1;
    int rc=2*parent+2;
    if(lc && rc <= lastIndex)
    {
        if(ptr[lc]>ptr[rc])
        {
            t=ptr[lc];
            ptr[lc]=ptr[rc];
        }
        else
        {
             t=ptr[rc];
             ptr[rc]=ptr[lc];
        }
    }
    else
    {
        t=ptr[lc];
    }
    ptr[lastIndex]=ptr[i];
    lastIndex-=1;
    ptr[i]=t;
    while (1)
    {
       int l=2*i+1;
       int r=2*i+2;
       if(l>lastIndex)
       {
          l=r;
       }
       if(r>lastIndex)
       {
          r=l;
       }
       if((l>lastIndex&&r>lastIndex))
       {
          break;
       }
       else if(ptr[i]<ptr[l] || ptr[i]<ptr[r])
       {
         if(ptr[r]>ptr[l])
         {
           if(l>lastIndex||r>lastIndex)
           {
              break;
           } 
           int temp = ptr[r];
           ptr[r] = ptr[i];
           ptr[i] = temp;
           i=r;
         }
         else if(ptr[l]>ptr[r])
         {
            if(l>lastIndex||r>lastIndex)
            {
               break;
            }
           int temp = ptr[l];
           ptr[l] = ptr[i];
           ptr[i] = temp;
           i=l;
         }
         else
         {
           break;
         }
       }
       else
       {
           break;
       }
    }
  }
}

void Display(int ptr[],int n)
{
    cout<<endl<<"\nThe "<<n<<" Array Elements Are :- \n\n";
     for(int i=0; i<n; i++)
     {
        if(i<10)
        {
           cout<<"\t 0"<<i<<" --> ";
           cout<<" | "<<ptr[i]<<" | \n";
        }
        else
        {
            cout<<"\t "<<i<<" --> ";
            cout<<" | "<<ptr[i]<<" | \n";
        }
    }
    cout<<"\n\n"<<endl;
}