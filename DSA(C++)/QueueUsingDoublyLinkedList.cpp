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

class Queue
{
    private:
       node* Front;
       node* Rear;
    public:
       Queue(); 
       bool IsEmpty();
       void MultipleInsert();  
       void ShowAll();
       int Insert(int);
       node* Search(int);
       void ShowParticular(node*);
       int Delete();
       void ShowRear();
       void ShowFront();
       int count();
       Queue(Queue&);
       Queue& operator =(Queue&);
       ~Queue();
};

Queue::~Queue()
{
    while(Front)
    {
        Delete();
    }
    Front=Rear=NULL;
}

Queue::Queue()
{
    Front=Rear=NULL;
}

Queue::Queue(Queue &s)
{
    Front=Rear=NULL;
    node* t=s.Front;
    while(t)
    {
        Insert(t->Item);
        t=t->Next;
    }
}

Queue& Queue::operator =(Queue &s)
{
    while(Rear!=NULL)
    {
        Delete();
    }
    Front=Rear=NULL;
    node* t=s.Front;
    while(t)
    {
        Insert(t->Item);
        t=t->Next;
    }
    return (*this);
}

bool Queue::IsEmpty()
{
    if(Front==NULL&&Rear==NULL)
    return true;
    else
    return false;
}

void Queue::MultipleInsert()
{
    int data,i;
    do
    {
       node *n=new node;
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

    } while(i==1);
}


void Queue::ShowAll()
{
    if(IsEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    {
    node *t=Rear;
    while(t)
    {
        if(t==Rear)
        cout<<endl<<"Rear  -->   | "<<t->Item<<" | ";
        else if(t==Front)
        cout<<endl<<"Front -->   | "<<t->Item<<" | ";
        else
        cout<<endl<<"            | "<<t->Item<<" | ";
        t=t->Prev;
    }
    }
}

int Queue::Insert(int data)
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

node* Queue::Search(int data)
{
    if(IsEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
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

void Queue::ShowParticular(node* t)
{
    if(t==Rear)
    cout<<endl<<"\nRear  -->   | "<<t->Item<<" | "<<endl;
    else if(t==Front)
    cout<<endl<<"\nFront -->   | "<<t->Item<<" | "<<endl;
    else
    cout<<endl<<"\n            | "<<t->Item<<" | "<<endl;
}

void Queue::ShowFront()
{
    if(IsEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    cout<<endl<<"\nFront -->   | "<<Front->Item<<" | "<<endl;
}

void Queue::ShowRear()
{
    if(IsEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    cout<<endl<<"\nRear  -->   | "<<Rear->Item<<" | "<<endl;
}

int Queue::Delete()
{
    if(IsEmpty())
    {
        cout<<endl<<"UNDERFLOW! : Queue Is Empty"<<endl;
    }
    else
    {
        node *p=Front->Next;
        delete Front;
        p->Prev=NULL;
        Front=p;
        return 1;
    }
    return 0;
}

int Queue::count()
{
    if(IsEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    {
        node* t=Front;  int c=0;
        while(t)
        {
           c++; t=t->Next;
        }
        return c;
    }
    return 0;
}

int menu()
{
    int k;
    cout<<endl<<"\n\tQUEUE DATA STRUCTURE USING DUBLY LINKED LIST\n"<<endl;
    cout<<endl<<"\t1.MULTIPLE INSERT";
    cout<<endl<<"\t2.SINGLE INSERT";
    cout<<endl<<"\t3.SHOW FULL QUEUE";
    cout<<endl<<"\t4.EMPTY OR NOT";
    cout<<endl<<"\t5.DELETE ITEM";
    cout<<endl<<"\t6.SEARCH ITEM";
    cout<<endl<<"\t7.SHOW PARTICULAR ITEM";
    cout<<endl<<"\t8.SHOW FRONT";
    cout<<endl<<"\t9.SHOW REAR";
    cout<<endl<<"\t10.COUNT TOTAL ITEM";
    cout<<endl<<"\t11.Exit";
    cout<<endl<<"\n\tEnter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11] :-  "; cin>>k;
    return k;
}


int main()
{
    system("cls");
    Queue q1;
    while(1)
    {
        switch(menu())
        {
            case 1:
            {
                q1.MultipleInsert();
                cout<<endl<<"Multiple Insert Is Successful"<<endl;
                break;
            }
            case 2:
            {
                int data; cout<<endl<<"Enter The Data : "; cin>>data;
                int k=q1.Insert(data);
                if(!q1.IsEmpty())
                {
                    if(k!=0)
                    cout<<endl<<"Insertion Is Successful"<<endl;
                    else
                     cout<<endl<<"Insertion Is Not Successful"<<endl;
                }
                break;
            }
            case 3:
            {
                q1.ShowAll();
                break;
            }
            case 4:
            {
                int k=q1.IsEmpty();
                if(k==1)
                cout<<endl<<"Yes Queue Is Empty"<<endl;
                else
                cout<<endl<<"No! Queue Is Not Empty"<<endl;
                break;
            }
            case 5:
            {
                int k=q1.Delete();
                if(!q1.IsEmpty())
                {
                if(k!=0)
                cout<<endl<<"Delete Is Successful"<<endl;
                else
                cout<<endl<<"Delete Is Not Successful"<<endl;
                }
                break;
            }
            case 6:
            {
                int data; cout<<endl<<"Enter The Item Which You Want To Search :- "; cin>>data;
                node *n=q1.Search(data);
                if(!q1.IsEmpty())
                {
                if(n!=NULL)
                    cout<<endl<<"Search Successful"<<endl;
                else
                    cout<<endl<<"Search Not Successful"<<endl;    
                }
                break;
            }
            case 7:
            {
                    int data; cout<<endl<<"Enter The Item Which You Want To Show :- "; cin>>data;
                    node* p=q1.Search(data);
                    if(!q1.IsEmpty())
                    {
                    if(p!=NULL)
                    {
                        cout<<endl<<"The Item IS :- \n"<<endl;
                        q1.ShowParticular(p);
                    }
                    else
                    {
                        cout<<endl<<"Item Is Not Found"<<endl;
                    }
                }
                break;
            }
            case 8:
            {
                if(!q1.IsEmpty())
                {
                 cout<<endl<<"The Front Index Is :- \n"<<endl;
                 q1.ShowFront();
                }
                else
                q1.ShowFront();
                break;
            }
            case 9:
            {
                if(!q1.IsEmpty())
                {
                 cout<<endl<<"The Rear Index Is :- \n"<<endl;
                 q1.ShowRear();
                }
                else
                q1.ShowRear();
                break;
            }
            case 10:
            {
                int k=q1.count();
                if(!q1.IsEmpty())
                cout<<endl<<"Total Item In The Queue Is : "<<k<<endl;
                break;
            }
            case 11:
            {
                cout<<endl<<"\nExit____________________________________\n\n\n"<<endl; 
                exit(0);
                break;
            }
            default:
            {
                cout<<endl<<"\nWrong Choice! Choose Again"<<endl;
                break;
            }
        }
        cout<<endl<<"\nEnter Any Key To Continue : "; getch(); system("cls");
    }
    cout<<endl;
    return 0;
}
