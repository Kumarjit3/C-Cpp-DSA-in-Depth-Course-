#include<iostream>
#include<conio.h>
using namespace std;
int menu();

class DynamicArray
{
      private:
        int capacity;
        int lastIndex;
        int *ptr;
      protected:
         void doubleArray();
         void halfArray();  
      public:
         DynamicArray(int capacity) { this->capacity=capacity; }
         DynamicArray() : lastIndex(-1),ptr(NULL),capacity(0) { }
         DynamicArray(DynamicArray&);
         DynamicArray& operator=(DynamicArray&);
         void createArray(int);
         bool isEmpty();
         void append(int);
         void insert(int,int);
         void edit(int,int);
         void deletee(int);
         bool isFull();
         void showItem(int);
         void count();
         ~DynamicArray();
         void found(int); 
         void showLastIndex();
         void showCapacity();
         void showAllItems();  
};


void DynamicArray::createArray(int size)    //membership lebel
{
    capacity=size;
    if(ptr!=NULL)
    delete []ptr;
    ptr=new int(size);
    cout<<endl<<"Array Created"<<endl;
}

DynamicArray::DynamicArray(DynamicArray &d1)
{
    ptr=NULL;
    ptr=new int[d1.capacity];
    capacity=d1.capacity;
    lastIndex=d1.lastIndex;
    for(int i=0; i<=d1.lastIndex; i++)
    ptr[i]=d1.ptr[i];
}

DynamicArray& DynamicArray::operator=(DynamicArray &d1)
{
     if(ptr!=NULL)
     delete ptr;
     ptr=NULL;
     ptr=new int[d1.capacity];
    capacity=d1.capacity;
    lastIndex=d1.lastIndex;
     for(int i=0; i<=d1.lastIndex; i++)
     ptr[i]=d1.ptr[i];
     return (*this);
}

void DynamicArray::doubleArray()
{
    capacity=capacity+capacity;
    int *temp=new int[capacity];
    for(int i=0; i<lastIndex; i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}

void DynamicArray::halfArray()
{
    capacity=(capacity/2);
    int *temp=new int[capacity];
    for(int i=0; i<lastIndex; i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}

bool DynamicArray::isEmpty()
{
    if(lastIndex==-1 && capacity==0)
    return true;
    else
    return false;
}

void DynamicArray::append(int value)
{
    if(ptr==NULL)
    {
      cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isFull())
    {
      doubleArray();
      lastIndex++;
      ptr[lastIndex]=value;
      cout<<endl<<"Append Successful Using Double Array"<<endl;
    }
    else
    {
        lastIndex++;
        ptr[lastIndex]=value;
        cout<<endl<<"Append Successful"<<endl;
    }
}

void DynamicArray::insert(int index,int value)
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(index>lastIndex+1)
    {
        cout<<endl<<"Invalid Index"<<endl;
    }
    else if(isFull())
    {
      doubleArray();
      lastIndex++;
      ptr[index]=value;
      cout<<endl<<"Insert Successful Using Double Array"<<endl;
    }
    else if(index<=lastIndex)
    {
        for(int i=lastIndex+1; i>index; i--)
        ptr[i]=ptr[i-1];
        ptr[index]=value;
        lastIndex++;
        if(lastIndex==capacity)
        doubleArray();
        cout<<endl<<"Insert Successful"<<endl;
    }
    else if(index==lastIndex+1 && lastIndex+1<capacity)
    {
        ptr[index]=value;
        lastIndex++;
        if(lastIndex==capacity)
        doubleArray();
        cout<<endl<<"Insert Successful"<<endl;
    }
}

void DynamicArray::edit(int index,int value)
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
        cout<<endl<<"Array is Empty Edit Not Possible"<<endl;
    }
    else if(index>lastIndex)
    {
        cout<<endl<<"Invalid Index"<<endl;
    }
    else
    {
        ptr[index]=value;
        cout<<endl<<"Edit Successful"<<endl;
    }
}

void DynamicArray::deletee(int index)
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
       cout<<endl<<"Underflow : Delete Not Possible"<<endl;
    }
    else if(index>lastIndex)
    {
       cout<<endl<<"Invalid Index"<<endl;
    }
    else if(index<=lastIndex)
    {
        if(index==lastIndex)
        {
            for(int i=index; i<=lastIndex; i++)
            {
                ptr[i]=ptr[i+1];
            }
            lastIndex--;
            if(capacity>1 && lastIndex+1==(capacity/2))
            {
              halfArray();
            }
            cout<<endl<<"Delete Successful"<<endl;
        }
        else if(index<lastIndex)
        {
            for(int i=index; i<lastIndex; i++)
            {
                ptr[i]=ptr[i+1];
            }
            lastIndex--;
            if(capacity>1 && lastIndex+1==(capacity/2))
            {
               halfArray();
            }
            cout<<endl<<"Delete Successful"<<endl;
        
        }
    }
    else
    {
        for(int i=index; i<lastIndex; i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
        if(lastIndex+1==(capacity/2))
        {
            halfArray();
        }
        cout<<endl<<"Delete Successful"<<endl;
    }
}

bool DynamicArray::isFull()
{
    if(lastIndex+1==capacity)
    return true;
    else
    return false;
}

void DynamicArray::showItem(int index)
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
      cout<<endl<<"Array Is Empty"<<endl;
    }
    else if(index>lastIndex)
    {
        cout<<endl<<"Invalid Index"<<endl;
    }
    else
    {
       cout<<endl<<"ptr["<<index<<"] = "<<ptr[index]<<endl;
    }
}

void DynamicArray::count()
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
      cout<<endl<<"Array Is Empty"<<endl;
    }
    else
    {
        cout<<endl<<"The Number Of Elements is : "<<lastIndex+1;
    }
}

DynamicArray::~DynamicArray()
{
    delete []ptr;
}

void DynamicArray::found(int value)
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
      cout<<endl<<"Array Is Empty"<<endl;
    }
    else
    {
        int k;
        for(int i=0; i<=lastIndex; i++)
        {
           if(value==ptr[i])
           {
             k=1;
             cout<<endl<<value<<" Found At "<<i<<" Index"<<endl;
           }
        }
        if(k!=1)
        {
            cout<<endl<<value<<" Not Found"<<endl;
        }
    }
}

void DynamicArray::showLastIndex()
{
    cout<<endl<<"Last Index IS : "<<lastIndex<<endl;
}

void DynamicArray::showCapacity()
{
    cout<<endl<<"Capacity is : "<<capacity<<endl;
}

void DynamicArray::showAllItems()
{
    cout<<endl<<"Total "<<lastIndex+1<<" Items Are : "<<endl;
    for(int i=0; i<=lastIndex; i++)
    cout<<ptr[i]<<" ";
    cout<<endl<<endl;
}

int menu()
{
    int k;
    cout<<endl<<"\tDYNAMIC ARRAY DATA STRUCTURE"<<endl;
    cout<<endl<<"1. CREATE ARRAY";
    cout<<endl<<"2. INSERT ITEM";
    cout<<endl<<"3. APPEND";
    cout<<endl<<"4. SHOW ITEM";
    cout<<endl<<"5. DELETE ITEM";
    cout<<endl<<"6. EDIT ITEM";
    cout<<endl<<"7. SHOW LAST INDEX";
    cout<<endl<<"8. SHOW CAPACITY";
    cout<<endl<<"9. ARRAY EMPTY OR NOT";
    cout<<endl<<"10. ARRAY FULL OR NOT";
    cout<<endl<<"11. FOUND ITEM";
    cout<<endl<<"12. TOTAL ITEM";
    cout<<endl<<"13. SHOW ALL ITEMS";
    cout<<endl<<"14. EXIT"<<endl;
    cout<<endl<<"Enter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11/12/13/14] :- ";
    cin>>k;
    return k;
}


int main()
{
    system("cls");
    DynamicArray a1;
     while(1)
    {
        switch(menu())
        {
            case 1:
            {
                int n;
                cout<<endl<<"Enter The Array Size : "; cin>>n;
                a1.createArray(n);
                break;
            }
            case 2:
            {
                int n,v;
                cout<<endl<<"Enter The Index No : "; cin>>n;
                cout<<endl<<"Enter The Value : "; cin>>v;
                a1.insert(n,v);
                break;
            }
            case 3:
            {
                int v;
                cout<<endl<<"Enter The Value : "; cin>>v;
                a1.append(v);
                break;
            }
            case 4:
            {
                int n;
                cout<<endl<<"Enter The Index No : "; cin>>n;
                a1.showItem(n);
                break;
            }
            case 5:
            {
                int n;
                cout<<endl<<"Enter The Index No : "; cin>>n;
                a1.deletee(n);
                break;
            }
            case 6:
            {
                int n,v;
                cout<<endl<<"Enter The Index No : "; cin>>n;
                cout<<endl<<"Enter The Value : "; cin>>v;
                a1.edit(n,v);
                break;
            }
            case 7:
            {
                a1.showLastIndex();
                break;
            }
            case 8:
            {
                a1.showCapacity();
                break;
            }
            case 9:
            {
                if(a1.isEmpty())
                cout<<endl<<"Yes Array Is Empty"<<endl;
                else
                cout<<endl<<"No Array Is Not Empty"<<endl;
                break;
            }
            case 10:
            {
                if(a1.isFull())
                cout<<endl<<"Yes Array Is Full"<<endl; 
                else
                cout<<endl<<"No Array Is Not Full"<<endl;
                break;
            }
            case 11:
            {
                int v;
                cout<<endl<<"Enter The Item Which You Want To Find : "; cin>>v;
                a1.found(v);
                break;
            }
            case 12:
            {
                a1.count();
                break;
            }
            case 13:
            {
                a1.showAllItems();
                break;
            }
            case 14:
            {
                cout<<endl<<"Exit________________________________\n\n"<<endl;
                exit(0);
                break;
            }
            default:
            {
                cout<<endl<<"Wrong Choice"<<endl;
                break;
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl<<"Enter Any key To Continue : ";
        getch();
        system("cls");
    }
    cout<<endl;
    return 0;
}
