#include<iostream>
#include<conio.h>
using namespace std;

int menu();

struct node
{
    int item;
    node *next;
};

class queue
{
     private:
       node *front;
       node *rear;
     protected:
        void showAll(node*);
        void insert(int);  
     public:
       queue();
       bool isEmpty();
       void multipleInsert();
       void ShowAll();
       int Insert(int);
       int Delete();
       node* search(int);
       void showParticular(node *p);
       void showRear();
       void showFront();
       int countItems();
       ~queue();
       queue(queue&);
       queue& operator =(queue&);
};


queue& queue::operator =(queue &a)
{
    while(rear)
      Delete();
     while(a.rear!=NULL)
    {
        insert(a.rear->item);
        a.rear=a.rear->next;
    } 
    return (*this);
}


queue::queue(queue &a)
{
    front=rear=NULL;
    while(a.rear!=NULL)
    {
        insert(a.rear->item);
        a.rear=a.rear->next;
    }
}

queue::~queue()
{
    while(front)
    {
        Delete();
    }
}

queue::queue()
{
    front=NULL;
    rear=NULL;
}

void queue::insert(int data)
{
    node *n=new node;
   if(isEmpty())
   {
       n->item=data;
       n->next=NULL;
       rear=n;
       front=n;
   }
   else
   {
     n->item=data;
     n->next=NULL;
     front->next=n;
     front=n;
   }
}

int queue::countItems()
{
    int c=0;
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        node* t=rear;
        while(t!=front)
        {
            c++;  
            t=t->next;
        }
        c++;
    }
    return c;
}

void queue::showFront()
{
    if(isEmpty())
   {
     cout<<endl<<"Queue is Empty"<<endl;
   }
   else
   {
     cout<<endl<<"FRONT --> | "<<front->item<<" | "<<endl;
   } 
}

void queue::showRear()
{
   if(isEmpty())
   {
     cout<<endl<<"Queue is Empty"<<endl;
   }
   else
   {
     cout<<endl<<"REAR --> | "<<rear->item<<" | "<<endl;
   } 
}

void queue::showParticular(node *p)
{
    if(isEmpty())
    {
        cout<<endl<<"Queue is Empty"<<endl;
    }
    else
    {
        if(p==rear)
        cout<<endl<<"REAR --> | "<<p->item<<" | "<<endl;
        else if(p==front)
        cout<<endl<<"FRONT --> | "<<p->item<<" | "<<endl;
        else
        cout<<endl<<" | "<<p->item<<" | "<<endl;
    }
}

node* queue::search(int data)
{
    if(isEmpty())
    {
        cout<<endl<<"Queue is Empty"<<endl;
    }
    else
    {
        node* t=rear;
        while(t)
        {
            if(t->item==data)
            return t;
            else
            t=t->next;
        }
    }
    return NULL;
}

int queue::Delete()
{
    if(isEmpty())
    {
      cout<<endl<<"UNDERFLOW : The Stack Is Empty"<<endl;
    }
    else
    {
        node *t=rear;
        while(t->next!=front)
        t=t->next;
        if(t->next==front)
        {
        delete front;
        t->next=NULL;
        front=t;
        return 1;
        }
    }
    return 0;
}

int queue::Insert(int data)
{
    node *n=new node;
    if(isEmpty())
    {
        n->item=data;
        n->next=NULL;
        front=n;
        rear=n;
        return 1;
    }
    else
    {
        n->item=data;
        n->next=rear;
        rear=n;
        return 1;
    }
    return 0;
}

void queue::showAll(node *t)
{
    if(isEmpty())
    {
        cout<<"Queue Is Empty"<<endl;
    }
    else
    {
        if(t!=front)
        {
            showAll(t->next);
            if(t==rear)
            cout<<"REAR  -->  | "<<t->item<<" | "<<endl;
            else
             cout<<"           | "<<t->item<<" | "<<endl;
        }
        else
        {
            cout<<"FRONT -->  | "<<t->item<<" | "<<endl;
        }
    }
}

void queue::ShowAll()
{
    if(!isEmpty())
    cout<<endl<<"The Current Form Of The Queue Is - "<<endl;
    cout<<endl<<endl;
    showAll(rear);
    cout<<endl;
}

void queue::multipleInsert()
{
    int data,i;
    do
    {
    node *n=new node;
    cout<<endl<<"Enter The Data : "; cin>>data;
    if(isEmpty())
    {
        n->item=data;
        n->next=NULL;
        front=n;
        rear=n;
    }
    else
    {
        n->item=data;
        n->next=NULL;
        front->next=n;
        front=n;
    }
    cout<<endl<<"Enter 1 for Continue : "; cin>>i;

   } while(i==1);
}

bool queue::isEmpty()
{
    if(front==NULL && rear==NULL)
    return true;
    else
    return false;
}


int menu()
{
    int k;
    cout<<endl<<"\tQUEUE DATA STRUCTURE USING LINKED LIST"<<endl;
    cout<<endl<<"1. MULTIPLE INSERT";
    cout<<endl<<"2. SINGLE INSERT";
    cout<<endl<<"3. SHOW FULL QUEUE";
    cout<<endl<<"4. SHOW PARTICULAR NODE";
    cout<<endl<<"5. SHOW FRONT";
    cout<<endl<<"6. SHOW REAR";
    cout<<endl<<"7. SEARCH ITEM";
    cout<<endl<<"8. QUEUE EMPTY OR NOT";
    cout<<endl<<"9. COUNT TOTAL ITEM";
    cout<<endl<<"10. DELETE ITEM";
    cout<<endl<<"11. EXIT"<<endl;
    cout<<endl<<"Enter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11] :- ";
    cin>>k;
    return k;
}



int main()
{
    queue q1; 
    system("cls");
    while(1)
    {
        switch(menu())
        {
            case 1:
            {
                q1.multipleInsert();
                cout<<endl<<"Multipleinsert Is Successful"<<endl;
                break;
            }
            case 2:
            {
                int data,k;
                cout<<endl<<"Enter The Data : "; cin>>data;
                 k=q1.Insert(data);
                 if(k!=0)
                 cout<<endl<<"Insertion Is Successful"<<endl;
                 else
                 cout<<endl<<"Insertion Is Not Successful"<<endl;
                 break;
            }
            case 3:
            {
                q1.ShowAll();
                break;
            }
            case 4:
            {
                int data;
                cout<<endl<<"Enter the Item Which You Want To search : "; cin>>data;
                node *n=q1.search(data);
                if(n!=NULL)
                q1.showParticular(n);
                break;
            }
            case 5:
            {
                q1.showFront();
                break;
            }
            case 6:
            {
                q1.showRear();
                break;
            }
            case 7:
            {
               int data;
               cout<<endl<<"Enter the Item Which You Want To search : "; cin>>data;
               node *n=q1.search(data);
               if(!q1.isEmpty())
               {
               if(n!=NULL)
                  cout<<endl<<"Item Is Found"<<endl;
               else
                  cout<<endl<<"Item Not Found"<<endl;
               }
                  break;
            }
            case 8:
            {
                int k=q1.isEmpty();
                if(k==1)
                  cout<<endl<<"Queue Is Empty"<<endl;
                else
                  cout<<endl<<"Queue Is Not Empty"<<endl;
                  break;  
            }
            case 9:
            {
                int k=q1.countItems();
                cout<<endl<<"Total Items In The Queue Is :- "<<k<<endl;
                break;
            }
            case 10:
            {
                int k=q1.Delete();
                if(!q1.isEmpty())
                {
                if(k==1)
                   cout<<endl<<"Deletion Is Successful"<<endl;
                else
                   cout<<endl<<"Deletion Is Not Successful"<<endl;
                }
                   break;
            }
            case 11:
            {
               cout<<endl<<"Exit____________________________________\n\n"<<endl; 
               exit(0);
               break;  
            }
            default:
            {
                cout<<endl<<"Wrong Choice! Choose Again\n"<<endl;
                break;
            }
        }
        cout<<endl<<"Enter Any Key For Continue : ";
        getch(); system("cls");
    }
    cout<<endl;
    return 0;
}

   