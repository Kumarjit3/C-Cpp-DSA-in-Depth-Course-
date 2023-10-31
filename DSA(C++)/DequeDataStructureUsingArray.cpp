#include<iostream>
#include<conio.h>
using namespace std;
int menu();

class deque
{
    private:
       int capacity;
       int Front;
       int Rear;
       int *ptr;
    public:
       deque();  
       void createArray(int);
       void showCapacity();
       bool IsEmpty();
       bool IsFull();
       bool ptrEmpty();
       void MultipleInsert();
       void ShowAll();
       int FrontInsert(int);
       int RearInsert(int);
       int FrontDelete();
       int RearDelete();
       void ShowFront();
       void ShowRear();
       int Search(int);
       int Count();
       ~deque();
       deque(deque&);
       deque& operator =(deque&);
};

deque::~deque()
{
    delete[]ptr;
}

deque::deque()
{
    ptr=NULL;
    capacity=0;
    Front=Rear=-1;
}

deque& deque::operator =(deque &s)
{
    while(Front!=-1&&Rear!=-1)
    {
        FrontDelete();
    }
    Front=Rear=-1;
    if(ptr!=NULL)
    ptr=NULL;
    createArray(s.capacity);
    for(int i=s.Front; i<=s.Rear; i++)
    RearInsert(s.ptr[i]);
    return (*this);
}

deque::deque(deque &s)
{
    if(Front!=-1 && Rear!=-1)
    Front=Rear=-1;
    if(ptr!=NULL)
    ptr=NULL;
    createArray(s.capacity);
    for(int i=s.Front; i<=s.Rear; i++)
    RearInsert(s.ptr[i]);
}

bool deque::IsEmpty()
{
    if(Front==-1&&Rear==-1)
    return true;
    else
    return false;
}

bool deque::ptrEmpty()
{
    if(ptr==NULL)
    return true;
    else
    return false;
}

bool deque::IsFull()
{
    if(Rear+1==capacity)
    return true;
    else
    return false;
}

void deque::createArray(int capacity)
{
    this->capacity=capacity;
    ptr=new int[capacity];
}

void deque::showCapacity()
{
    cout<<endl<<"The Capacity Of The Deque is : "<<capacity<<endl;
}

void deque::MultipleInsert()
{
    int i;
    if(IsFull())
    {
        cout<<endl<<"OVERFLOW! The Deque Is Full"<<endl;
    }
    else
    {
    do
    {
    if(!IsFull())
    {
        int data;
        cout<<endl<<"Enter The Data : "; cin>>data;
        if(IsEmpty())
        {
            Front++; Rear++;
            ptr[Rear]=data;
        }
        else
        {
            Rear++;
            ptr[Rear]=data;
        }
    }
    else
    {
        cout<<endl<<"OVERFLOW! The Deque Is Full"<<endl;
        break;
    }
     cout<<endl<<"Enter 1 For Continue : "; cin>>i;
    }while(i==1);
    }
}

void deque::ShowAll()
{
    if(IsEmpty())
    {
        cout<<endl<<"UNDERFLOW! The Deque Is Empty"<<endl;
    }
    else
    {
        for(int i=Front; i<=Rear; i++)
        {
            if(i==Front)
            cout<<endl<<"Front --> | "<<ptr[i]<<" | ";
            else if(i==Rear)
            cout<<endl<<"Rear  --> | "<<ptr[i]<<" | ";
            else
            cout<<endl<<"          | "<<ptr[i]<<" | ";
        }
        cout<<endl;
    }
}

int deque::FrontInsert(int data)
{
   if(IsFull())
   {
     cout<<endl<<"OVERFLOW! The Deque Is Full"<<endl;
   }
   else if(IsEmpty())
   {
       Front++; Rear++;
       ptr[Rear]=data;
       return 1;
   }
   else
   {
     Rear++;
     for(int i=Rear; i>=Front; i--)
     {
        ptr[i]=ptr[i-1];
     }
     ptr[Front]=data;
     return 1;
   }
    return 0;
}

int deque::RearInsert(int data)
{
   if(IsFull())
   {
     cout<<endl<<"OVERFLOW! The Deque Is Full"<<endl;
   }
   else if(IsEmpty())
   {
       Front++; Rear++;
       ptr[Rear]=data;
       return 1;
   }
   else
   {
     Rear++;
     ptr[Rear]=data;
     return 1;
   }
   return 0;
}

int deque::FrontDelete()
{
    if(IsEmpty())
    {
        cout<<endl<<"UNDERFLOW! The Deque Is Empty"<<endl;
    }
    else
    {
        if(Front==Rear)
        {
           Front--; Rear--;
           return 1;
        }
        else
        {
        for(int i=Front; i<Rear; i++)
         ptr[i]=ptr[i+1];
         Rear--;
         return 1;
        }
    }
    return 0;
}

int deque::RearDelete()
{
    if(IsEmpty())
    {
        cout<<endl<<"UNDERFLOW! The Deque Is Empty"<<endl;
    }
    else
    {
        if(Front==Rear)
        {
           Front--; Rear--;
           return 1;
        }
        else
        {
        Rear--;
        return 1;
        }
    }
    return 0;
}

void deque::ShowFront()
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        cout<<endl<<"Front --> | "<<ptr[Front]<<" | "<<endl;
    }
}


void deque::ShowRear()
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        cout<<endl<<"Rear --> | "<<ptr[Rear]<<" | "<<endl;
    }
}

int deque::Search(int data)
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        int t=Front;
        while(t<=Rear)
        {
           if(ptr[t]==data)
           return 1;
           else
           t++;
        }
    }
    return 0;
}

int deque::Count()
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        int t=Front;
        while(t<=Rear)
        {
           t++;
        }
        return t;
    }
    return 0;
}


int menu()
{
    int k;
    cout<<endl<<"\n\tDEQUE DATA STRUCTURE USING ARRAY"<<endl;
    cout<<endl<<"\t1.CREATE ARRAY";
    cout<<endl<<"\t2.MULTIPLE INSERT";
    cout<<endl<<"\t3.SHOW FULL DEQUE";
    cout<<endl<<"\t4.FRONT INSERT";
    cout<<endl<<"\t5.REAR INSERT";
    cout<<endl<<"\t6.SHOW FRONT";
    cout<<endl<<"\t7.SHOW REAR";
    cout<<endl<<"\t8.FRONT DELETE";
    cout<<endl<<"\t9.REAR DELETE";
    cout<<endl<<"\t10.SEARCH";
    cout<<endl<<"\t11.COUNT TOTAL ITEM";
    cout<<endl<<"\t12.IS EMPTY?";
    cout<<endl<<"\t13.IS FULL?";
    cout<<endl<<"\t14.SHOW CAPACITY";
    cout<<endl<<"\t15.EXIT"<<endl;
    cout<<endl<<"\tEnter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11/12/13/14/15] : "; cin>>k;
    return k;
}


int main()
{
    deque d1; 
    system("cls");
    while(1)
    {
        switch(menu())
        {
           case 1:
           {
                int size;
                cout<<endl<<"Enter The Array Capacity : "; cin>>size;
                d1.createArray(size);
                cout<<endl<<"Array Is Created\n"<<endl; 
                break; 
           }
           case 2:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                    d1.MultipleInsert();
                    cout<<endl<<"Multiple Insert Successful"<<endl;
                }
                break;
           }
           case 3:
           {
               if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                    if(d1.IsEmpty())
                    {
                        cout<<endl<<"Deque Is Empty";
                    }
                    else
                    {
                        cout<<endl<<"The Current Form Of The Deque Is : "<<endl;
                        d1.ShowAll();
                    }
                }
                break;
           }
           case 4:
           {
               if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
               else
               {
                   int data; cout<<endl<<"Enter The Data : "; cin>>data;
                  int k=d1.FrontInsert(data);
                  if(k!=0)
                  cout<<endl<<"Front Insert IS Successful"<<endl;
               }
               break;
           }
           case 5:
           {
               if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
               else
               {
                   int data; cout<<endl<<"Enter The Data : "; cin>>data;
                  int k=d1.RearInsert(data);
                  if(k!=0)
                  cout<<endl<<"Rear Insert IS Successful"<<endl;
               }
               break;
           }
           case 6:
           {
               if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                if(!d1.IsEmpty())
                cout<<endl<<"The Front Index Of The Deque Is : "<<endl;
                d1.ShowFront();
                }
                break;
           }
           case 7:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                if(!d1.IsEmpty())
                cout<<endl<<"The Rear Index Of The Deque Is : "<<endl;
                d1.ShowRear();
                }
                break;
           }
           case 8:
           {
               if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                     int k=d1.FrontDelete();
                     if(k==1)
                     cout<<endl<<"Front Delete Is Successful"<<endl;
                }
                 break;
           }
           case 9:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                     int k=d1.RearDelete();
                     if(k==1)
                     cout<<endl<<"Rear Delete Is Successful"<<endl;
                }
                 break;
           }
           case 10:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                    int data; cout<<endl<<"Enter The Item Which You Want to Search : "; cin>>data;
                    int k=d1.Search(data);
                    if(!d1.IsEmpty())
                    {
                    if(k==1)
                    cout<<endl<<"Item Is Found"<<endl;
                    else
                    cout<<endl<<"Item is Not Found"<<endl;
                    }
                }
                break;
           }
           case 11:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                    int k=d1.Count();
                    if(!d1.IsEmpty())
                    {
                       cout<<endl<<"The Total Items In The Deque Is : "<<k<<endl;
                    }
                }
                break;
           }
           case 12:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                    if(d1.IsEmpty()==1)
                      cout<<endl<<"Yes Deque Is Empty"<<endl;
                    else
                      cout<<endl<<"No! Deque Is Not Empty"<<endl;
                }
                break;    
           }
           case 13:
           {
                if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
                else
                {
                   if(d1.IsFull()==1)
                      cout<<endl<<"Yes Deque Is Full"<<endl;
                   else
                      cout<<endl<<"No! Deque Is Not Full"<<endl;   
                }
                break;
           }
           case 14:
           {
               if(d1.ptrEmpty())
                {
                    cout<<endl<<"Array Is Not Created, Create Array First"<<endl;
                }
               else
               {
                  d1.showCapacity();
               }
               break;
           }
           case 15:
           {
               cout<<endl<<"Exit______________________________________________________\n\n"<<endl;
               exit(0); break;
           }
           default:
           {
               cout<<endl<<"Wrong Choice! Choose Again_____________\n"<<endl;
               break;
           }
        }
        cout<<endl<<"Enter Any To Continue : "; getch(); system("cls");
    }
    cout<<endl;
    return 0;
}