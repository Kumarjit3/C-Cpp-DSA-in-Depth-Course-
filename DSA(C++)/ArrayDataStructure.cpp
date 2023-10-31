#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int menu();

class array
{
    private:
       int *ptr;
       int capacity;
       int current;
    public:
       array() : ptr(NULL),current(-1) { } //non parameterized constructor
       array(array &);   //copy constructor
       ~array();         //destructor
       array& operator =(array&);       //assignment operator
       void createArray(int);
       bool isAlreadyCreated();
       void insert(int,int);
       void append(int);
       void ShowInformation(int);    //member functions
       int isEmpty();
       int isFull();
       void edit(int,int);
       void deletee(int index);
       void ShowCapacity();
       void ShowCurrentState(); 
       void found(int);
       void count(); 
       void showAllItems(); 
};

array::~array()
{
    delete []ptr;
}

array::array(array &a)    //copy constructor
{
    capacity=a.capacity; 
    current=a.current;                  
    ptr=new int[a.capacity];              //deep copy
    for(int i=0; i<=current; i++)
    ptr[i]=a.ptr[i];
}

array& array::operator =(array &a1)       //assignment operator
{
    capacity=a1.capacity;
    current=a1.current; 
    if(ptr!=NULL)
    delete ptr;                 
    ptr=new int[a1.capacity];            //deep copy
    for(int i=0; i<current; i++)
    ptr[i]=a1.ptr[i]; 
    return (*this);
}

void array::createArray(int size)    //membership lebel
{
    capacity=size;
    if(ptr!=NULL)
    delete []ptr;
    ptr=new int(size);
    cout<<endl<<"Array Created"<<endl;
}

bool array::isAlreadyCreated()
{
    if(ptr != NULL)
    {
       return true;
    }
    else
    {
        return false;
    }
}

void array::insert(int index,int value)
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else if(index<=current)
    {
        int i;
        for(i=current+1; i>index; i--)
        {
           ptr[i]=ptr[i-1];
        }
        ptr[index]=value;
        current++;
        cout<<endl<<"Insert Successful"<<endl;
    }
    else if(isFull())
    {
      cout<<endl<<"Overflow : Item Insert Not Possible"<<endl;
    }
    else if(index>current+1)
    {
     cout<<endl<<"Invalid Index"<<endl;
    }
    else if(index>=capacity)
    {
        cout<<endl<<"Insert Unsuccessful ! Index Out Of Bound\n";
    }
    else 
    {
    current++;
    ptr[index]=value;
    cout<<endl<<"Insert Successful"<<endl;
    }
}

void array::append(int value)
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
    else if(isFull())
    {
      cout<<endl<<"Overflow : Item Insert Not Possible"<<endl;
    }
    else if(current+1<capacity)
    {
    ptr[current+1]=value;
    current++;
    cout<<endl<<"Insert Successful"<<endl; 
    }
    else
    {
        cout<<endl<<"Append Not Possible"<<endl;
    }
}

void array::ShowInformation(int index)
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else if(isEmpty())
    cout<<endl<<"Array Is Empty"<<endl;
    else if(index>current)
    cout<<endl<<"Index Empty"<<endl;
    else
    cout<<endl<<"ptr["<<index<<"] = "<<ptr[index]<<endl;
}

int array::isEmpty()
{
    if(current==-1)
    {
    //cout<<endl<<"Yes Array Is Empty"<<endl;
    return true;
    }
    else
    {
    //cout<<endl<<"No Array Is Not Empty"<<endl;
    return false;
    }
}

int array::isFull()
{
    if(current+1==capacity)
    {
    //cout<<endl<<"Yes Array Is Full"<<endl; 
    return true;
    }
    else
    {
    //cout<<endl<<"No Array Is Not Full"<<endl;
    return false;
    }
}

void array::edit(int index,int value)
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else if(isEmpty())
    cout<<endl<<"Array Is Empty Edit Not Possible"<<endl;
    else if(index>current)
    cout<<endl<<"Invalid Index"<<endl;
    else
    {
    ptr[index]=value;
    cout<<endl<<"Edit Successful"<<endl;
    }
}

void array::deletee(int index)
{
   int i;
   if(ptr==NULL)
   cout<<endl<<"Array is Not Created! Create Array First"<<endl;
   else if(isEmpty())
   cout<<endl<<"Underflow : Delete Not Possible"<<endl;
   else if(index!=capacity-1)
   {
   for(i=index; i<capacity; i++)
   {
     ptr[i]=ptr[i+1];
   }
   current--;
   cout<<endl<<"Delete Successful"<<endl;
   }
   else if(index==capacity-1)
   {
      ptr[capacity]=ptr[index];
      current--;
      cout<<endl<<"Delete Successful"<<endl;
   }
   else if(index>current)
   cout<<endl<<"Invalid Index, Delete Not Possible"<<endl;
}

void array::ShowCapacity()
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else
    cout<<endl<<"Capacity Is : "<<capacity<<endl;
}

void array::ShowCurrentState()
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else
    cout<<"Current Sate Is : "<<current<<endl;
}

void array::count()
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
        cout<<endl<<"The Number Of Elements is : "<<current+1;
    }
}

void array::found(int value)
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
        for(int i=0; i<=current; i++)
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

void array::showAllItems()
{
    if(ptr==NULL)
    {
       cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    }
   else
   {
    cout<<endl<<"Total "<<current+1<<" Items Are : "<<endl;
    for(int i=0; i<=current; i++)
    cout<<ptr[i]<<" ";
   }
    cout<<endl;
}


int menu()
{
    int k;
    cout<<endl<<"\tARRAY DATA STRUCTURE"<<endl;
    cout<<endl<<"1. CREATE ARRAY";
    cout<<endl<<"2. INSERT ITEM";
    cout<<endl<<"3. APPEND";
    cout<<endl<<"4. SHOW ITEM";
    cout<<endl<<"5. DELETE ITEM";
    cout<<endl<<"6. EDIT ITEM";
    cout<<endl<<"7. SHOW CURRENT STATE";
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
    array a1;
    while(1)
    {
        switch(menu())
        {
            case 1:
            {
                if(a1.isAlreadyCreated() == 0)
                {
                int n;
                cout<<endl<<"Enter The Array Size : "; cin>>n;
                a1.createArray(n);
                }
                else
                {
                   cout<<endl<<"Array Is Already Created Don't Repeat It\n"; 
                }
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
                a1.ShowInformation(n);
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
                a1.ShowCurrentState();
                break;
            }
            case 8:
            {
                a1.ShowCapacity();
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

/*int main()
{
    array a1;
    a1.createArray(10);
    a1.insert(0,10);
    a1.insert(1,20);
    a1.insert(2,30);
    array a2(a1);
    a2.showAllItems();
    cout<<endl;
    return 0;
}*/