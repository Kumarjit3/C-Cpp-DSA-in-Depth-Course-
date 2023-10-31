#include<iostream>
#include<conio.h>
using namespace std;
int menu();

struct node
{
    int Item;
    int Priority;
    node* Next;
};

class priorityQueue
{
   private:
      node* start;
   public:
      priorityQueue();
      bool isEmpty();
      int insert(int,int);
      void ShowAll();
      int Delete();
      void showHighestPriority();
      void showLowestPriority();
      void showHighestPriorityItem();
      void showLowestPriorityItem();
      ~priorityQueue();
      priorityQueue(priorityQueue&);
      priorityQueue& operator =(priorityQueue&);
};

priorityQueue::~priorityQueue()
{
    node* t=start;
     while(t)
     Delete();
}

priorityQueue::priorityQueue()
{
    start=NULL;
}

priorityQueue& priorityQueue::operator =(priorityQueue &p)
{
   while(start)
   Delete();
   start=NULL;
   node* t=p.start;
    while(t)
    {
        insert(t->Priority,t->Item);
        t=t->Next;
    }
    return (*this);
}

priorityQueue::priorityQueue(priorityQueue &p)
{
    start=NULL;
    node* t=p.start;
    while(t)
    {
        insert(t->Priority,t->Item);
        t=t->Next;
    }
}

bool priorityQueue::isEmpty()
{
    if(start==NULL)
    return true;
    else
    return false;
}


int priorityQueue::insert(int p,int data)
{
    node* n=new node;
      if(isEmpty())
      {
        n->Priority=p;
        n->Item=data;
        n->Next=NULL;
        start=n;
        return 1;
      }
      else if(p<start->Priority)
      {
            n->Priority=p;
            n->Item=data;
            n->Next=start;
            start=n;
            return 1;
      }
      else
      {
        node* t=start;
        while(t)
        {
            if(t->Next==NULL && p>t->Priority)
            {
              n->Priority=p;
              n->Item=data;
              n->Next=NULL;
              t->Next=n;
              break;   
            }
            else if(p>t->Priority && p<=t->Next->Priority)
            {
                n->Priority=p;
                n->Item=data;
                n->Next=t->Next;
                t->Next=n;
                break;
            }
            else
            {
                t=t->Next;
            }
        }
        return 1;
            
      }
      return 0;
}

int priorityQueue::Delete()
{
    if(isEmpty())
    {
        cout<<endl<<"UNDERFLOW! The Queue Is Empty"<<endl;     
    }
    else if(start->Next==NULL)
    {
        delete start;
        start=NULL;
    }
    else
    {
        node* t=start;
        while(t->Next->Next!=NULL)
        {
            t=t->Next;
        }
        node* p=t->Next;
        delete p;
        t->Next=NULL;
        return 1;
    }
    return 0;
}

void priorityQueue::ShowAll()
{
    if(isEmpty())
    {
        cout<<endl<<"The Queue Is Empty"<<endl;     
    }
    else
    {
        node *t=start;
            cout<<endl<<"           PRIORITY |  DATA  "<<endl;
        while(t)
        {
            if(t==start)
            cout<<endl<<"START -->   |  "<<t->Priority<<"    |  "<<t->Item<<"  |  ";
            else
            cout<<endl<<"            |  "<<t->Priority<<"    |  "<<t->Item<<"  |  ";
            t=t->Next;
        }
        cout<<endl;
    }
}

void priorityQueue::showHighestPriority()
{
    if(isEmpty())
    {
        cout<<endl<<"The Queue Is Empty"<<endl;     
    }
    else
    {
        node* t=start;
        while(t->Next!=NULL)
        {
            t=t->Next;
        }
        cout<<endl<<"The Highest Priority Is : "<<t->Priority<<endl;
    }
}

void priorityQueue::showHighestPriorityItem()
{
    if(isEmpty())
    {
        cout<<endl<<"The Queue Is Empty"<<endl;     
    }
    else
    {
        node* t=start;
        while(t->Next!=NULL)
        {
            t=t->Next;
        }
        cout<<endl<<"The Highest Priority Item Is : "<<t->Item<<endl;
    }
}

void priorityQueue::showLowestPriority()
{
    if(isEmpty())
    {
        cout<<endl<<"The Queue Is Empty"<<endl;     
    }
    else
    {
        cout<<endl<<"The Highest Priority Is : "<<start->Priority<<endl;
    }
}

void priorityQueue::showLowestPriorityItem()
{
    if(isEmpty())
    {
        cout<<endl<<"The Queue Is Empty"<<endl;     
    }
    else
    {
        cout<<endl<<"The Highest Priority Item Is : "<<start->Item<<endl;
    }
}


int menu()
{
    int k;
    cout<<endl<<"PRIORITY QUEUE USING SINGLY LINKED LIST"<<endl;
    cout<<endl<<"1.INSERT ITEM";
    cout<<endl<<"2.DELETE ITEM";
    cout<<endl<<"3.SHOW FULL QUEUE";
    cout<<endl<<"4.QUEUE IS EMPTY ?";
    cout<<endl<<"5.SHOW HIGHEST PRIORITY";
    cout<<endl<<"6.SHOW LOWEST PRIORITY";
    cout<<endl<<"7.SHOW HIGHEST PRIORITY ITEM";
    cout<<endl<<"8.SHOW LOWEST PRIORITY ITEM";
    cout<<endl<<"9.EXIT";
    cout<<endl<<"Enter Your Choice In Between[1/2/3/4/5/6/7/8/9/10] :- ";
    cin>>k; return k;
}

int main()
{
    system("cls");
    priorityQueue p1;
    while(1)
    {
        switch(menu())
        {
            case 1:
            {
            int p,data;
            cout<<endl<<"Enter The Priority : "; cin>>p;
            cout<<endl<<"Enter The Data : ";   cin>>data;
            int k=p1.insert(p,data);
            if(k!=0)
            cout<<endl<<"Insert Successful"<<endl;
            else
            cout<<endl<<"Insert Not Successful"<<endl;
            break;
            }
            case 2:
            {
                int k=p1.Delete();
                if(k==1)
                cout<<endl<<"Delete Successful"<<endl;
                else
                cout<<endl<<"Delete Not Successful"<<endl;
                break;
            }
            case 3:
            {
                p1.ShowAll();
                break;
            }
            case 4:
            {
                int k=p1.isEmpty();
                if(k==1)
                cout<<endl<<"The Queue Is Empty"<<endl;
                else
                cout<<endl<<"The Queue Is Not Empty"<<endl;
                break;
            }
            case 5:
            {
                p1.showHighestPriority();
                break;
            }
            case 6:
            {
                p1.showLowestPriority();
                break;
            }
            case 7:
            {
                p1.showHighestPriorityItem();
                break;
            }
            case 8:
            {
                p1.showLowestPriorityItem();
                break;
            }
            case 9:
            {
                cout<<endl<<"Exit________________________________________\n\n"<<endl;
                exit(0);
                break;
            }
            default:
            {
                cout<<endl<<"Wrong Choice! Choose Again"<<endl;
                break;
            }
        }
        cout<<endl<<"Enter Any Key To Continue : "; getch(); system("cls");
    }
    cout<<endl;
}