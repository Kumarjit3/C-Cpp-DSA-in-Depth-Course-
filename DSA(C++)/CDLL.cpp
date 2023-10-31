#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class CDLL
{
    private:
       node *start;
    public:
       CDLL();
       void multipleInsert();
       void showAll();
       int insertAtFirst(int);
       int insertAtLast(int);
       node* search(int);
       int insertAfter(node*,int);
       int deleteFirst();
       int deleteLast();
       int deleteAfter(node*);
       int count();
       void showParticular(int);
       int edit(node *,int data);
       bool isEmpty();
       ~CDLL();
       CDLL(CDLL&);
       CDLL& operator =(CDLL&);
};

CDLL::CDLL()
{
    start=NULL;
}

CDLL::~CDLL()
{
    while(start)
    {
        deleteLast();
    }
}

CDLL::CDLL(CDLL &s)
{
    if(start!=NULL)
    start=NULL;
    node* t=s.start;
    while(t!=s.start->next)
    {
        insertAtFirst(t->item);
        t=t->prev;
    }
    insertAtFirst(s.start->next->item);
}

CDLL& CDLL::operator=(CDLL &s)
{
    while(start)
    deleteLast();
    start=NULL;
    node* t=s.start;
    while(t!=s.start->next)
    {
        insertAtFirst(t->item);
        t=t->prev;
    }
    insertAtFirst(s.start->next->item);
    return (*this);
}

bool CDLL::isEmpty()
{
    if(start==NULL)
    return true;
    else
    return false;
}

int CDLL::edit(node *p,int data)
{
    p->item=data;
    return 1;
}

void CDLL::showParticular(int data)
{
    node *t=start->next; int i=0;
    while(t!=start)
    {
        if(t->item==data)
        {
            cout<<endl<<" <-- "<<t->item<<" --> "<<endl; i=1;
            break;
        }
        t=t->next;
    }
    if(i==0)
    {
        if(t->item==data)
        {
            cout<<endl<<" <-- "<<t->item<<" --> "<<endl;
        }
        else
        {
            cout<<endl<<"Item Not Found "<<endl;
        }
    }
}

int CDLL::count()
{
    if(start==NULL)
    return 0;
    else if(start->next==start)
    return 1;
    else
    {
        node *t=start->next;
        int i=1;
        while(t!=start)
        {
            t=t->next; i++;
        }
        return i;
    }
    return 0;
}

int CDLL::deleteAfter(node *p)
{
     if(p->next==p)
     {
        deleteFirst();
        return 1;
     }
     else if(p->next==start)
     {
        deleteLast();
        return 1;
     }
     else if(p==start)
     {
         deleteFirst();
         return 1;
     }
     else
     {
        node *t=p->next;
        p->next=p->next->next;
        p->next->next->prev=p;
        delete t;
        return 1;
     }
     return 0;
}

int CDLL::deleteLast()
{
    if(start==NULL)
    {
        cout<<endl<<"UNDERFLOW : List Is Empty"<<endl;
        return 0;
    }
    else if(start->next==start)
    {
        delete start;
        start=NULL;
        return 1; 
    }
    else
    {
        node *t=start;
        start->prev->next=start->next;
        start->next->prev=start->prev;
        start=t->prev;
        delete t;
        return 1;
    }
    return 0;
}

int CDLL::deleteFirst()
{
    if(start==NULL)
    {
        cout<<endl<<"UNDERFLOW : List Is Empty"<<endl;
        return 0;
    }
    else if(start->next==start)
    {
        delete start;
        start=NULL;
        return 1;
    }
    else
    {
        node *t=start->next;
        start->next=start->next->next;
        start->next->next->prev=start;
        delete t;
        return 1;
    }
    return 0;
}

int CDLL::insertAfter(node *p,int data)
{
    node *n=new node;
    if(p->next==p)
    {
        insertAtLast(data);
        return 1;
    }
    else if(p==start)
    {
      insertAtLast(data);
      return 1;
    }
    else
    {
       n->prev=p;
       n->item=data;
       n->next=p->next;
       p->next=n;
       p->next->prev=n;
       return 1;
    }
    return 0;
}

node* CDLL::search(int data)
{
    int i=0;
    node *t=start->next;
     while(t!=start)
     {
        if(t->item==data)
         {
           return t;
           i=1;
         }
        else
           t=t->next;
     }
        if(i==0)
        {
            if(t->item==data)
            return t;
            else
            return NULL;
        }
     return NULL;
}

int CDLL::insertAtLast(int data)
{
    node *n=new node;
    if(start==NULL)
    {
        insertAtFirst(data);
        return 1;
    }
    else
    {
        n->prev=start;
        n->item=data;
        n->next=start->next;
        start->next=n;
        start=n;
        return 1;
    }
    return 0;
}

int CDLL::insertAtFirst(int data)
{
    node *n=new node;
    if(start==NULL)
    {
       n->prev=n;
       n->item=data;
       n->next=n;
       start=n;
       return 1;
    }
    else
    {
        n->prev=start;
        n->item=data;
        n->next=start->next;
        start->next->prev=n;
        start->next=n;
        return 1;
    }
    return 0;
}

void CDLL::showAll()
{
    if(start==NULL)
    {
       cout<<endl<<"List Is Empty"<<endl;
    }
    else
    {
        node *t=start->next;
        cout<<endl;
        while(t!=start)
        {
            cout<<" <-- "<<t->item<<" --> ";
            t=t->next;
        }
        cout<<" <-- "<<t->item<<" -->"<<endl;
    }
}

void CDLL::multipleInsert()
{
    int data,i=1;
    while(i==1)
    {
    node *n=new node;
    cout<<endl<<"Enter Data : "; cin>>data;
    if(start==NULL)
    {
       n->prev=n;
       n->item=data;
       n->next=n;
       start=n;
    }
    else if(start->next==start)
    {
       n->prev=start;
       n->item=data;
       n->next=start;
       start->next=n;
       start->prev=n;
       start=n;
    }
    else
    {
       n->prev=start;
       n->item=data;
       n->next=start->next;
       node *p=start->next;
       start->next=n;
       p->prev=n;
       start=n;
    }
    cout<<endl<<"Enter 1 For Continue : "; cin>>i;
    }
}



int menu()
{
    int k;
    cout<<endl<<"\tCIRCULR DUBLY LINKED LIST DATA STRUCTURE"<<endl;
    cout<<endl<<"1. INSERT MANY NODE AT A TIME :";
    cout<<endl<<"2. INSERT AT FIRST POSITION  :";
    cout<<endl<<"3. INSERT AT LAST POSITION  :";
    cout<<endl<<"4. INSERT AFTER GIVEN NODE  :";
    cout<<endl<<"5. SHOW ALL NODE  :";
    cout<<endl<<"6. SHOW PARTICULAR NODE  :";
    cout<<endl<<"7. SEARCH NODE  :";
    cout<<endl<<"8. DELETE AT FIRST POSITION  :";
    cout<<endl<<"9. DELETE AT LAST POSITION  :";
    cout<<endl<<"10. DELETE AFTER A GIVEN NODE  :";
    cout<<endl<<"11. EDIT A GIVEN NODE";
    cout<<endl<<"12. COUNT NODE  :";
    cout<<endl<<"13. LIST EMPTY OR NOTE";
    cout<<endl<<"14. EXIT"<<endl;
    cout<<endl<<"Enter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11/12/13/14] :- ";
    cin>>k;
    return k;
}


int main()
{
   CDLL d1;
   system("cls");
   while(1)
   {
   switch(menu())
   {
      case 1:
      {
         d1.multipleInsert();
         break;
      }
      case 2:
      {
         int data;
         cout<<endl<<"Enter Data : "; cin>>data;
         d1.insertAtFirst(data);
         cout<<endl<<"Insert Successful"<<endl;
         break;
      }
      case 3:
      {
         int data;
         cout<<endl<<"Enter Data : "; cin>>data;
         d1.insertAtLast(data);
         cout<<endl<<"Insert Successful"<<endl;
         break;     
      }
      case 4:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item After Which You Want To Insert A New Node : "; cin>>data;
         if(d1.isEmpty())
          {
           cout<<endl<<"List Is Empty"<<endl;
          }
          else {
         t=d1.search(data);
         if(t==NULL)
         cout<<endl<<"Item Not Found"<<endl;
         else
         {
         cout<<endl<<"Enter Data : "; cin>>data;
         d1.insertAfter(t,data);
         cout<<endl<<"Insert Successful"<<endl;
         }
          }
         break;
      }
      case 5:
      {
         d1.showAll();
         break;
      }
      case 6:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which You Want To Show : "; cin>>data;
         if(d1.isEmpty())
          {
           cout<<endl<<"List Is Empty"<<endl;
          }
          else {
         t=d1.search(data);
         if(t==NULL)
         cout<<endl<<"Item Not Found"<<endl;
         else
         {
            d1.showParticular(data);
         }
          }
         break;
      }
      case 7:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which You Want To Search : "; cin>>data;
         if(d1.isEmpty())
          {
           cout<<endl<<"List Is Empty"<<endl;
          }
          else {
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
          cout<<endl<<"Item Found"<<endl;
          }
         break;
      }
      case 8:
      {
         int k=d1.deleteFirst();
         if(k==1)
         cout<<endl<<"Delete Successful"<<endl;
         break;
      }
      case 9:
      {
         int k=d1.deleteLast();
         if(k==1)
         cout<<endl<<"Delete Successful"<<endl;
         break;
      }
      case 10:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which After You Want To delete A Node : "; cin>>data;
         if(d1.isEmpty())
          {
           cout<<endl<<"List Is Empty"<<endl;
          }
          else {
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
         {
            int k=d1.deleteAfter(t);
            if(k==1)
            cout<<endl<<"Delete Successful"<<endl;
         }
          }
         break;
      }
      case 11:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which You Want To Modify : "; cin>>data;
         if(d1.isEmpty())
          {
           cout<<endl<<"List Is Empty"<<endl;
          }
          else {
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
         {
            cout<<endl<<"Enter New Data : "; cin>>data;
            int k=d1.edit(t,data);
            if(k!=0)
           cout<<endl<<"Edit Successful"<<endl;
         }
          }
         break;  
      }
      case 12:
      {
         int c=d1.count();
         cout<<endl<<"Total Number Of Nodes In The List Is : "<<c<<endl;
         break;
      }
      case 13:
      {
         int k=d1.isEmpty();
         if(k==0)
         cout<<endl<<"No List Is Not Empty"<<endl;
         else
         cout<<endl<<"Yes List Is Empty"<<endl;
         break;
      }
      case 14:
      {
         cout<<endl<<"\n\nExit____________________________________________\n\n"<<endl;
         exit(0);
         break;
      }
      default:
      {
         cout<<endl<<"Wrong Choice ! ,Choose Again"<<endl;
         break;
      }    
   }
      cout<<endl<<"Enter Any key To Continue________ : ";
      getch();
      system("cls");
   }
   cout<<endl;
   return 0;
}


