#include<iostream>
#include<conio.h>
using namespace std;
int menu();

struct node
{
    int Item;
    node *Next;
};


class CLL
{
     private:
          node *start;
          node *end;
     public:
          CLL();
          void insertMany();
          void showAll();
          void showParticular(node*);
          node* search(int);
          int insertAtFirst(int);
          int insertAtLast(int);
          int insertAfter(node*,int);
          int deleteAtFirst();
          int deleteAtLast();
          int deleteAfter(node*);
          int count();
          bool isEmpty();
          int edit(node*,int);
          CLL(CLL&);
          CLL& operator =(CLL&);
          ~CLL();
};

CLL::CLL()
{
    start=NULL;
    end=NULL;
}

CLL::~CLL()
{
    while(start)
    deleteAtFirst();
    while(end)
    deleteAtFirst();
}

CLL& CLL::operator =(CLL &c)
{
    while(start)
    deleteAtFirst();
    while(end)
    deleteAtFirst();
    if(c.start==NULL && c.end==NULL)
    {
    start=end=NULL;
    }
    else
    {
        start=end=NULL;
    node *t=c.start;
    while(t->Next!=c.end->Next)
    {
        insertAtLast(t->Item);
        t=t->Next;
    }
    insertAtLast(c.end->Item);
    }
    return (*this);
}

CLL::CLL(CLL &c)
{
    if(c.start==NULL && c.end==NULL)
    {
      start=end=NULL;
    }
    else
    {
      start=end=NULL;   
    node *t=c.start;
    while(t->Next!=c.end->Next)
    {
        insertAtLast(t->Item);
        t=t->Next;
    }
    insertAtLast(c.end->Item);
    }
}

int CLL::edit(node *p,int data)
{
    if(start==NULL && end==NULL)
    {
    cout<<endl<<"List Is Empty"<<endl;
    return 0;
    }
    else
    {
        p->Item=data;
        return 1;
    }
    return 0;
}

bool CLL::isEmpty()
{
    if(start==NULL && end==NULL)
    return true;
    else
    return false;
}

int CLL::count()
{
    if(start==NULL)
    return 0;
    else if(start==end)
    return 1;
    else
    {
        int i=1;
        node *t=start;
        while(t->Next!=end->Next)
        {
            t=t->Next;
            i++;
        }
        return i;
    }
    return 0;
}

int CLL::deleteAfter(node *p)
{
    if(start==NULL && end==NULL)
    cout<<endl<<"List Is Empty"<<endl;
    else if(start==end)
    {
        cout<<endl<<"Nde Not Found"<<endl;
        return 0;
    }
    else
    {
       if(p==end)
       {
         node *t=start;
         start=start->Next;
         end->Next=start;
         delete t;
         return 1;
       }
       else if(p->Next==end)
       {
          deleteAtLast();
          return 1;
       }
       else
       {
          node *t=p->Next;
          p->Next=t->Next;
          delete t;
          return 1;
       }
    }
    return 0;
}

int CLL::deleteAtLast()
{
    if(start==NULL && end==NULL)
    cout<<endl<<"List Is Empty"<<endl;
    else if(start==end)
    {
        deleteAtFirst();
        return 1;
    }
    else
    {   
         node *t=start;
         while(t->Next!=end)
        {
          t=t->Next;
        }
       node *p=t->Next;
       t->Next=start;
       delete p;
       end=t;
       return 1;
    }
    return 0;
}

int CLL::deleteAtFirst()
{
    if(start==NULL && end==NULL)
    cout<<endl<<"List Is Empty"<<endl;
    else
    {
        if(start==end)
        {
           delete start;
           delete end;
           start=NULL;
           end=NULL;
           return 1;
        }
        else
        {
            node *p=start;
            start=p->Next;
            end->Next=start;
            delete p;
            return 1;
        }
    }
    return 0;
}

void CLL::showParticular(node *p)
{
    if(start==NULL && end==NULL)
    cout<<endl<<"List Is Empty"<<endl;
    else
    {
        if(p->Next==start)
            cout<<endl<<" | "<<p->Item<<" | --> NULL "<<endl;
        else
            cout<<endl<<" | "<<p->Item<<" | "<<endl;
    }
}

int CLL::insertAfter(node *p,int data)
{
    if(start==NULL && end==NULL)
    cout<<endl<<"List Is Empty"<<endl;
    else
    {
       node *n=new node;
       if(p->Next==start)
       {
           n->Item=data;
           n->Next=start;
           end->Next=n;
           end=n;
           return 1;
       }
       else
       {
        n->Item=data;
        n->Next=p->Next;
        p->Next=n;
        return 1;
       }
    }
    return 0;
}

node* CLL::search(int data)
{
    if(start==NULL && end==NULL)
    cout<<endl<<"List Is Empty"<<endl;
    else
    {
        node *t=start;
        while(t!=end)
        {
            if(t->Item==data)
            return t;
            else
            t=t->Next;
        }
        if(t->Item==data)
        {
            return t;
        }
        else
        return NULL;
    }
    return NULL;
}

int CLL::insertAtLast(int data)
{
    node *n=new node;
    if(start==NULL && end==NULL)
    {
        insertAtFirst(data);
        return 1;
    }
    else
    {
        n->Item=data;
        n->Next=start;
        end->Next=n;
        end=n;
        return 1;
    }
    return 0;
}

int CLL::insertAtFirst(int data)
{
    node *n=new node;
    if(start==NULL)
    {
       n->Item=data; 
       n->Next=n;
       start=n;
       end=n;
       return 1;
    }
    else
    {
      n->Item=data;
      n->Next=start;
      start=n;
      end->Next=start;
      return 1;
    }
    return 0;
}

void CLL::insertMany()
{
    int data,i=1;
    while(i==1)
    {
    node *n=new node;
    node *p;
    cout<<endl<<"Enter The Data : "; cin>>data;
    if(start==NULL)
    {
       n->Item=data;
       n->Next=n;
       start=n;
       end=n;
    }
    else
    {
      n->Item=data;
      n->Next=start;
      end->Next=n;
      end=n;
    }
    cout<<endl<<"Enter 1 For Continue : "; cin>>i;
    }
}

void CLL::showAll()
{
    if(start==NULL)
    {
        cout<<endl<<"List Is Empty"<<endl;
    }
    else
    {
    cout<<endl;
    node *t=start;
    while(t->Next!=end->Next)
    {
        cout<<"|"<<t->Item<<"|-->";
        t=t->Next;
    }
    cout<<"|"<<t->Item<<"|--> "<<endl;
    }
}


int menu()
{
    int k;
    cout<<endl<<"\t CIRCULAR LINKED LIST DATA STRUCTURE"<<endl;
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
   CLL d1;
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
         int k=d1.deleteAtFirst();
         if(k==1)
         cout<<endl<<"Delete Successful"<<endl;
         break;
      }
      case 9:
      {
         int k=d1.deleteAtLast();
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
