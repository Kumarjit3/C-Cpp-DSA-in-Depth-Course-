#include<iostream>
#include<conio.h>
using namespace std;
int menu();

struct node
{
   int Item;
   node* Prev;
   node* Next;
};

class deque
{
     private:
        node* Front;
        node* Rear;
     public:
       deque();
       bool IsEmpty();
       void MultipleInsert();
       void ShowAll();
       int FrontInsert(int);
       int RearInsert(int);
       int FrontDelete();
       int RearDelete();
       void ShowFront();
       void ShowRear();
       node* Search(int);
       int Count();
       ~deque();
       deque(deque&); 
       deque& operator =(deque&);   
};

deque::deque()
{
    Front=Rear=NULL;
}

deque::~deque()
{
    while(Front)
    {
        FrontDelete();
    }
}

deque::deque(deque &s)
{
    if(Front!=NULL && Rear!=NULL)
    Front=Rear=NULL;
    node* t=s.Front;
    while(t)
    {
        RearInsert(t->Item);
        t=t->Next;
    }
}

deque& deque::operator=(deque &s)
{
     while(Front)
     FrontDelete();
    Front=Rear=NULL;
    node* t=s.Front;
    while(t)
    {
        RearInsert(t->Item);
        t=t->Next;
    }
    return (*this);
}

bool deque::IsEmpty()
{
    if(Front==NULL&&Rear==NULL)
    return true;
    else
    return false;
}

void deque::MultipleInsert()
{
    int data,i;
   do
    {
     node* n=new node;
     cout<<endl<<"Enter The Data : "; cin>>data;
    if(IsEmpty())
    {
       n->Item=data;
       n->Next=NULL;
       n->Prev=NULL;
       Front=Rear=n;
    }
    else
    {
       n->Item=data;
       n->Next=NULL;
       n->Prev=Rear;
       Rear->Next=n;
       Rear=n;
    }
    cout<<endl<<"Enter 1 For Continue : "; cin>>i;
    }  while(i==1);
}

void deque::ShowAll()
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        node *t=Front;
        cout<<endl<<"The Current Form Of The Deque Is : \n"<<endl;
        while(t)
        {
            if(t==Front)
            cout<<endl<<"FRONT -->  | "<<t->Item<<" | ";
            else if(t==Rear)
            cout<<endl<<"REAR  -->  | "<<t->Item<<" | ";
            else
            cout<<endl<<"           | "<<t->Item<<" | ";
            t=t->Next;
        }
        cout<<endl;
    }
}

int deque::FrontInsert(int data)
{
    node* n=new node;
    if(IsEmpty())
    {
       n->Item=data;
       n->Next=NULL;
       n->Prev=NULL;
       Front=Rear=n;
       return 1;
    }
    else
    {
        n->Item=data;
        n->Prev=NULL;
        n->Next=Front;
        Front->Prev=n;
        Front=n;
        return 1;
    }
    return 0;
}

int deque::RearInsert(int data)
{
   node* n=new node;
    if(IsEmpty())
    {
       n->Item=data;
       n->Next=NULL;
       n->Prev=NULL;
       Front=Rear=n;
       return 1;
    }
    else
    {
        n->Item=data;
        n->Next=NULL;
        n->Prev=Rear;
        Rear->Next=n;
        Rear=n;
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
    else if(Front==Rear)
    {
        delete Front;
        Front=Rear=NULL;
        return 1;
    }
    else
    {
        node* n=Front->Next;
        delete Front;
        Front=n;
        Front->Prev=NULL;
        return 1;
    }
    return 0;
}

int deque::RearDelete()
{
    if(IsEmpty())
    {
        cout<<endl<<"UNDERFLOW! The Deque Is Empty"<<endl;
    }
    else if(Front==Rear)
    {
        delete Rear;
        Front=Rear=NULL;
        return 1;
    }
    else
    {
        node* t=Front;
        while(t->Next!=Rear)
        {
            t=t->Next;
        }
        t->Next=NULL;
        delete Rear;
        Rear=t;
        return 1;
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
    cout<<endl<<"FRONT -->  | "<<Front->Item<<" | "<<endl;
}

void deque::ShowRear()
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    cout<<endl<<"Rear  -->  | "<<Rear->Item<<" | "<<endl;
}

int deque::Count()
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        node* t=Front;  int c=0;
        while(t)
        {
           c++;
           t=t->Next;
        }
        return c;
    }
    return 0;
}


node* deque::Search(int data)
{
    if(IsEmpty())
    {
        cout<<endl<<"The Deque Is Empty"<<endl;
    }
    else
    {
        node* t=Front;
        while(t)
        {
           if(t->Item==data)
           return t;
           else
           t=t->Next;
        }
    }
    return NULL;
}


int menu()
{
    int k;
    cout<<endl<<"\n\tDEQUE DATA STRUCTURE USING DUBLY LINKED LIST"<<endl;
    cout<<endl<<"\t1.MULTIPLE INSERT";
    cout<<endl<<"\t2.SHOW FULL DEQUE";
    cout<<endl<<"\t3.FRONT INSERT";
    cout<<endl<<"\t4.REAR INSERT";
    cout<<endl<<"\t5.SHOW FRONT";
    cout<<endl<<"\t6.SHOW REAR";
    cout<<endl<<"\t7.FRONT DELETE";
    cout<<endl<<"\t8.REAR DELETE";
    cout<<endl<<"\t9.SEARCH";
    cout<<endl<<"\t10.COUNT TOTAL ITEM";
    cout<<endl<<"\t11.IS EMPTY?";
    cout<<endl<<"\t12.EXIT"<<endl;
    cout<<endl<<"\tEnter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11/12] : "; cin>>k;
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
                d1.MultipleInsert();
                  cout<<endl<<"Multiple Insert Successful"<<endl;
                break;
           }
           case 2:
           {
                if(d1.IsEmpty())
                   cout<<endl<<"Deque Is Empty"<<endl;
                else
                   d1.ShowAll();
                break;
           }
           case 3:
           {
                int data; cout<<endl<<"Enter The Data : "; cin>>data;
                int k=d1.FrontInsert(data);
                if(k!=0)
                  cout<<endl<<"Front Insert IS Successful"<<endl;
                break;
           }
           case 4:
           {
                int data; cout<<endl<<"Enter The Data : "; cin>>data;
                int k=d1.RearInsert(data);
                if(k!=0)
                  cout<<endl<<"Rear Insert IS Successful"<<endl;
                break;
           }
           case 5:
           {
                if(!d1.IsEmpty())
                  cout<<endl<<"The Front Index Of The Deque Is : "<<endl;
                d1.ShowFront();
                break;
           }
           case 6:
           {
                if(!d1.IsEmpty())
                  cout<<endl<<"The Rear Index Of The Deque Is : "<<endl;
                d1.ShowRear();
                break;
           }
           case 7:
           {
                int k=d1.FrontDelete();
                if(k==1)
                  cout<<endl<<"Front Delete Is Successful"<<endl;
                break;
           }
           case 8:
           {
                int k=d1.RearDelete();
                if(k==1)
                  cout<<endl<<"Rear Delete Is Successful"<<endl;
                break;
           }
           case 9:
           {
                int data; cout<<endl<<"Enter The Item Which You Want to Search : "; cin>>data;
                node* n=d1.Search(data);
                if(!d1.IsEmpty())
                {
                if(n!=NULL)
                  cout<<endl<<"Item Is Found"<<endl;
                else
                  cout<<endl<<"Item is Not Found"<<endl;
                }
                break;
           }
           case 10:
           {
                int k=d1.Count();
                if(!d1.IsEmpty())
                {
                  cout<<endl<<"The Total Items In The Deque Is : "<<k<<endl;
                }
                break;
           }
           case 11:
           {
                if(d1.IsEmpty()==1)
                    cout<<endl<<"Yes Deque Is Empty"<<endl;
                else
                    cout<<endl<<"No! Deque Is Not Empty"<<endl;
                break;    
           }
           case 12:
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

