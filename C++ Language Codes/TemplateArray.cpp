#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>
using namespace std;
int menu();

template<typename T>
class array
{
    private:
       T *ptr;
       int capacity;
       int current;
    public:
       array() : ptr(NULL),current(-1) { } //non parameterized constructor
       array(array<T> &);   //copy constructor
       ~array();         //destructor
       array<T>& operator =(array<T>&);       //assignment operator
       void createArray(int);
       bool isAlreadyCreated();
       void insert();
       void append();
       void ShowInformation(int);    //member functions
       bool isEmpty();
       bool isFull();
       void edit();
       void deletee(int index);
       void ShowCapacity();
       void ShowCurrentState(); 
       void found();
       void count(); 
       void showAllItems(); 
};

template<typename T>
array<T>::~array()
{
    delete []ptr;
}

template<typename T>
array<T>::array(array<T> &a)    //copy constructor
{
    capacity=a.capacity; 
    current=a.current;                  
    ptr=new T[a.capacity];              //deep copy
    for(int i=0; i<=current; i++)
    ptr[i]=a.ptr[i];
}

template<typename T>
array<T>& array<T>::operator =(array<T> &a1)       //assignment operator
{
    capacity=a1.capacity;
    current=a1.current; 
    if(ptr!=NULL)
    delete ptr;                 
    ptr=new T[a1.capacity];            //deep copy
    for(int i=0; i<current; i++)
    ptr[i]=a1.ptr[i]; 
    return (*this);
}

template<typename T>
void array<T>::createArray(int size)    //membership lebel
{
    capacity=size;
    if(ptr!=NULL)
    delete []ptr;
    ptr=new T [size];
    cout<<endl<<"Array Created"<<endl;
}

template<typename T>
bool array<T>::isAlreadyCreated()
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

template<typename T>
void array<T>::insert()
{
    int index; T value;
    cout<<endl<<"Enter The Index No : "; cin>>index;
    cout<<endl<<"Enter The Value : "; cin>>value;
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

template<typename T>
void array<T>::append()
{
    T value;
    cout<<endl<<"Enter The Value : "; cin>>value;     
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

template<typename T>
void array<T>::ShowInformation(int index)
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

template<typename T>
bool array<T>::isEmpty()
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

template<typename T>
bool array<T>::isFull()
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

template<typename T>
void array<T>::edit()
{
    int index; T value;
    cout<<endl<<"Enter The Index No : "; cin>>index;
    cout<<endl<<"Enter The Value : "; cin>>value;
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

template<typename T>
void array<T>::deletee(int index)
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

template<typename T>
void array<T>::ShowCapacity()
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else
    cout<<endl<<"Capacity Is : "<<capacity<<endl;
}

template<typename T>
void array<T>::ShowCurrentState()
{
    if(ptr==NULL)
    cout<<endl<<"Array is Not Created! Create Array First"<<endl;
    else
    cout<<"Current Sate Is : "<<current<<endl;
}

template<typename T>
void array<T>::count()
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

template<typename T>
void array<T>::found()
{
    T value;
    cout<<endl<<"Enter The Item Which You Want To Find : "; cin>>value;
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

template<typename T>
void array<T>::showAllItems()
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
    array<float> a1;
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
                a1.insert();
                break;
            }
            case 3:
            {
                a1.append();
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
                a1.edit();
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
                a1.found();
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