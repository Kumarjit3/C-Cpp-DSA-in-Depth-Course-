#include<iostream>
#include<conio.h>
using namespace std;
int menu();

struct node
{
     int item;
     node *next;
};

class SLL
{   
   private:
     node *start;
   protected:
   SLL(SLL&);
   SLL& operator =(SLL&); 
   public:
   SLL();  
   void multipleInsert();
   void insertAtStart(int);
   void insertAtLast(int); 
   node* search(int);    //search returns a node address
   void insertAfter(node*,int);  //only after search we can do insertAfter 
   int deleteFirst();
   int deleteLast();
   int deleteAfter(node*);
   void showParticular(node*);
   void showAll();
   int count();
   bool isEmpty();
   int edit(node*,int);
   ~SLL();
};

SLL::SLL()
{
   start=NULL;
}

SLL::~SLL()
{
   while(start)
   deleteFirst();
}

SLL::SLL(SLL &a)
{
   node *t=a.start;
   start=NULL;
   while(t)
   {
      insertAtLast(t->item);
      t=t->next;
   }
}

SLL& SLL::operator =(SLL &c)
{
   node *t=c.start;
   while(start)
   deleteFirst();
   while(t)
   {
      insertAtLast(t->item);
      t=t->next;
   }
   return (*this);
}

int SLL::edit(node *p,int data)
{
   if(start==NULL)
   {
      cout<<endl<<"List Is Empty"<<endl;
      return 0;
   }
   else
   {
       p->item=data;
       return 1;
   }
   return 0;
}

bool SLL::isEmpty()
{
   if(start==NULL)
   return true;
   else
   return false;
}

int SLL::count()
{
   if(start==NULL)
   {
      cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      return 1;
   }
   else
   {
      int i=0;
      node *t=start;
      while(t)
      {
         i++;
         t=t->next;
      }
      return i;
   }
   return 0;
}

void SLL::showAll()
{
   if(start==NULL)
   {
      cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      cout<<endl<<start->item<<" -> NULL "<<endl;
   }
   else
   {
      node *t=start;
      cout<<endl;
      while(t)
      {
         cout<<t->item<<" -> ";
         t=t->next;
      }
      cout<<" NULL "<<endl;
   }  
}

int SLL::deleteAfter(node *p)
{
   if(start==NULL)
   {
      cout<<endl<<"Delete Not Possible"<<endl;
   }
   else if(start->next==NULL)
   {
      cout<<endl<<"Delete Not Possible Only One Node Is There In The List"<<endl;
   }
   else
   {
      node *r=start;
      while(r!=p)
      {
         r=r->next;
      }
     node *t=p->next;
     r->next=p->next->next;
     delete t;
     return 1;
   }
   return 0;
}

int SLL::deleteLast()
{
   if(start==NULL)
   cout<<endl<<"Delete Not Possible"<<endl;
   else if(start->next==NULL)
   {
      delete start;
      start=NULL;
      return 1;
   }
   else
   {
     node *t=start; int i=1;
     while(t->next->next!=NULL)
     {
      t=t->next;  i++;
     }
     node *p=t->next;
     t->next=NULL;
     delete p;
     return 1;
   }
    return 0;
}

int SLL::deleteFirst()
{
   if(start==NULL)
   cout<<endl<<"Delete Not Possible"<<endl;
   else if(start->next==NULL)
   {
      delete start;
      start=NULL;
      return 1;
   }
   else
   {
      node *n=start;
      start=n->next;
      delete n;
      return 1;
   }
   return 0;
}

node* SLL::search(int data)
{
   if(start==NULL)
   return NULL;
   else
   {
   node *t=start;
   while(t->next!=NULL)
   {
      if(t->item==data)
      return t;
      t=t->next;
   }
   if(t->item==data)
   return t;
   }
   return NULL;
}

void SLL::insertAfter(node *p,int data)  //we insert after node p
{
   node *n=new node;
   n->item=data;
   n->next=p->next;
   p->next=n;
}

void SLL::insertAtLast(int data)
{
   node *n=new node;
   node *t=new node;
   n->item=data;
   t=start;
   while(t->next!=NULL)
   {
     t=t->next;
   }
   t->next=n;
   n->next=NULL;
}

void SLL::insertAtStart(int data)
{
   node *n=new node;
   n->item=data;
   n->next=start;
   start=n;
}

void SLL::multipleInsert()
{
   if(start==NULL)
   {
    int data,i=1;
    node *t=new node;
    while(i==1)
    {
      cout<<endl<<"Enter Data : "; cin>>data;
     if(start==NULL)
     {
      node *n=new node;
      t=n;
      n->item=data;
      start=n;
      n->next=NULL;
     }
     else
     {
         node *n=new node;
         n->item=data;
         t->next=n;
         t=n;
         n->next=NULL;
     }
      cout<<endl<<"Enter 1 for continue : "; cin>>i;
    }
   }
   else
   {
      int data,i=1;
      while(i==1)
      {
      node *n=new node;
      cout<<endl<<"Enter Data : ";  cin>>data;
      node *t=start;
      while(t->next!=NULL)
      {
        t=t->next;
      }
      n->item=data;
      t->next=n;
      n->next=NULL;
       cout<<endl<<"Enter 1 for continue : ";  cin>>i;
      }
   }
}

void SLL::showParticular(node *n)
{
   if(start==NULL)
   {
      cout<<endl<<"List Is Empty"<<endl;
   }
   else if(start->next==NULL)
   {
      cout<<endl<<start->item<<endl;
   }
   else
   {
      int i=0;
      node *t=start;
      while(t)
      {
         if(t->item==n->item && t->next==n->next)
         {
         cout<<endl<<t->item<<endl;
         i=1;
         break;
         }
         t=t->next;
      }
      if(i==0)
      {
         cout<<endl<<"Item Not Found"<<endl;
      }
   }
}


int menu()
{
    int k;
    cout<<endl<<"\tSINGLY LINKED LIST DATA STRUCTURE"<<endl;
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
   SLL d1;
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
         d1.insertAtStart(data);
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
         t=d1.search(data);
         if(t==NULL)
          cout<<endl<<"Item Not Found"<<endl;
         else
         {
            int k=d1.deleteAfter(t);
            if(k==1)
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
            int k=d1.edit(t,data);
            if(k!=0)
           cout<<endl<<"Edit Successful"<<endl;
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


