#include<iostream>
#include<conio.h>
using namespace std;
int menu();

struct node
{
     node *prev;
     int item;
     node *next;
};

class DLL
{
    private:
       node *start;    
    public:
       DLL();
       void insertMany();
       void showAll();
       void insertAtFirst(int);
       void insertAtLast(int);
       node* search(int);
       void insertAfter(node*,int);
       void deleteFirst();
       void deleteLast();
       void deleteAfter(node*);
       void edit(node*,int);
       bool isEmpty();
       void showParticular(node*);
       int count(); 
       DLL(DLL&);  
       DLL& operator=(DLL&);
       ~DLL();
}; 

DLL::DLL()
{
   start=NULL;
}

DLL::~DLL()
{
   while(start)
   deleteFirst();
}

bool DLL::isEmpty()
{
   if(start==NULL)
   return true;
   else
   return false;
}

DLL& DLL::operator=(DLL &list)
{
    node *t=list.start;
     while(start)
     {
      deleteFirst();
     }
     while(t)
     {
       insertAtLast(t->item);
       t=t->next;
     }
     return (*this);
}

DLL::DLL(DLL &list)
{
    if(start!=NULL)
     start=NULL;
     node *t=list.start;
     while(t)
     {
       insertAtLast(t->item);
       t=t->next;
     }
}

int DLL::count()
{
   node *t=start; int i=0;
   if(start==NULL)
   return 0;
   else if(start->next==NULL)
   return 1;
   else
   while(t)
   {
      i++;
      t=t->next;
   }
   return i;
}


void DLL::showParticular(node *p)
{
   if(start==NULL)
   {
   cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
     if(start->next==p->next && start==p && start->item==p->item)
     {
      cout<<endl<<"NULL <-- "<<p->item<<" --> NULL"<<endl;
     }
     else
     {
      cout<<endl<<"Node Not Found"<<endl;
     }
   }
   else
   {
      node *t=start;  int i=0;
      while(t)
      {
         if(t->next==p->next && t==p && t->item==p->item)
         {
         cout<<endl<<"NULL <-- "<<p->item<<" --> NULL"<<endl; i++;
         break;
         }
         else
         {
            t=t->next;
         }
      }
      if(i==0)
      {  
        cout<<endl<<"Node Not Found"<<endl;
      }
   }
}

void DLL::edit(node *p,int data)
{
   int i=0;
   if(start==NULL)
   {
   cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      if(start->item==p->item)
      {
         start->item=data;
      }
      else
      {
         cout<<endl<<"Node Not Foun"<<endl;
      }
   }
   else
   {
      node *t=start;
      while(t->next!=NULL)
      {
         if(t->next==p->next)
         {
            t->item=data;
            i=1;
         }
         t=t->next;
      }
      if(i==0)
      cout<<endl<<"Node Not Found"<<endl;
   }
}

void DLL::deleteAfter(node *p)
{
   if(start==NULL)
   {
   cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      deleteFirst();
   }
   else
   {
      node *t=p->next;
      if(t->next==NULL)
      {
         deleteLast();
      }
      else
      {
      p->next=t->next;
      t->next->prev=p;
      delete t;
      }
   }
}

void DLL::deleteLast()
{
   if(start==NULL)
   {
   cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      delete start;
      start=NULL;
   }
   else
   {
      node *t=start;
      while(t->next!=NULL)
      {
         t=t->next;
      }
      node *p=t->prev;
      p->next=NULL;
      t->prev=NULL;
      delete t;
   }
}

void DLL::deleteFirst()
{
   if(start==NULL)
   {
   cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      delete start;
      start=NULL;
   }
   else
   {
      node *p=start->next;
      start->next=NULL;
      p->prev=NULL;
      delete start;
      start=p;
   }
}

void DLL::insertAfter(node *p,int data)
{
   node *n=new node;
   n->item=data;
   n->prev=p;
   n->next=p->next;
   p->next=n;
   p->next->prev=n;
}

node* DLL::search(int data)
{
   node *t=start;
   if(start==NULL)
   {
   cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      if(start->item==data)
      return start;
      else
      return NULL;
   }
   else
   {
      while(t->next!=NULL)
      {
         if(t->item==data)
         return t;
         t=t->next;
      }
   }
   return NULL;
}

void DLL::insertAtLast(int data)
{
   node *n=new node;
   node *t=start;
   if(start==NULL)
   {
      insertAtFirst(data);
   }
   else if(start->next==NULL)
   {
      n->item=data;
      n->next=NULL;
      n->prev=start;
      start->next=n;
   }
   else
   {
      while(t->next!=NULL)
      {
         t=t->next;
      }
      n->item=data;
      n->prev=t;
      n->next=NULL;
      t->next=n;
   }
}

void DLL::insertAtFirst(int data)
{
    node *n=new node;
    if(start==NULL)
    {
      n->item=data;
      n->prev=NULL;
      n->next=NULL;
      start=n;
    }
    else
    {
      n->item=data;
      n->prev=NULL;
      n->next=start;
      start=n;
    }
}

void DLL::insertMany()
{
   int data,i=1;
   while(i==1)
   {
    cout<<endl<<"Enter Data : "; cin>>data;  
    node *n=new node;
    if(start==NULL)
    {
      n->item=data;
      n->prev=NULL;
      n->next=NULL;
      start=n;
    }
    else if(start->next==NULL)
    {
      n->item=data;
      n->prev=start;
      n->next=NULL;
      start->next=n;
    }
    else
    {
      node *t=start;
      while(t->next!=NULL)
      {
         t=t->next;
      }
      n->item=data;
      n->prev=t;
      n->next=NULL;
      t->next=n;
    }
    cout<<endl<<"Enter 1 for Continue : "; cin>>i;
   }
}

void DLL::showAll()
{
   node *t=start;
   if(start==NULL)
   cout<<endl<<"List Is Empty"<<endl;
   else
   {
   cout<<endl<<"The Whole List Looks Like :- "<<endl;
   cout<<endl<<"NULL <-- ";
   while(t)
   {
      cout<<t->item<<" --> ";
      t=t->next;
   }
   cout<<"NULL "<<endl;
   }
}


int menu()
{
    int k;
    cout<<endl<<"\tDUBLY LINKED LIST DATA STRUCTURE"<<endl;
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
   DLL d1;
   system("cls");
   while(1)
   {
   switch(menu())
   {
      case 1:
      {
         d1.insertMany();
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
         t=d1.search(data);
         if(t==NULL)
         cout<<endl<<"Item Not Found"<<endl;
         else
         {
         cout<<endl<<"Enter Data : "; cin>>data;
         d1.insertAfter(t,data);
         cout<<endl<<"Insert Successful"<<endl;
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
         t=d1.search(data);
         if(t==NULL)
         cout<<endl<<"Item Not Found"<<endl;
         else
         {
            d1.showParticular(t);
         }
         break;
      }
      case 7:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which You Want To Search : "; cin>>data;
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
          cout<<endl<<"Item Found"<<endl;
         break;
      }
      case 8:
      {
         d1.deleteFirst();
         cout<<endl<<"Delete Successful"<<endl;
         break;
      }
      case 9:
      {
         d1.deleteLast();
         cout<<endl<<"Delete Successful"<<endl;
         break;
      }
      case 10:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which After You Want To delete A Node : "; cin>>data;
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
         {
            d1.deleteAfter(t);
            cout<<endl<<"Delete Successful"<<endl;
         }
         break;
      }
      case 11:
      {
         node *t; int data;
         cout<<endl<<"Enter The Item Which You Want To Modify : "; cin>>data;
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
         {
            cout<<endl<<"Enter New Data : "; cin>>data;
            d1.edit(t,data);
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