#include<iostream>
#include<conio.h>
using namespace std;

int menu();

struct node
{
    int item;
    node *next;
};

class stack
{
     private:
      node *top;
      node *start;
     protected:
     void showAll(node*); 
     void rev(node*);
     public:
      stack() : top(NULL),start(NULL) {}
      void multipleInsert();  
      void ShowAll();
      void push(int);
      int pop();
      node* peek();
      bool isEmpty();
      void reverseStack();
      ~stack();
      stack(stack&);
      stack& operator =(stack&);
};

stack& stack::operator=(stack &s)
{
   while(top)
    pop();
    top=start=NULL;
    node* t=s.start;
    while(t)
    {
       push(t->item);
       t=t->next;
    }
    return (*this);
}

stack::stack(stack &s)
{
     top=start=NULL;  
    node *t=s.start;
    while(t)
    {
       push(t->item);
       t=t->next;
    }
}

stack::~stack()
{
    while(top)
    pop();
}

void stack::rev(node* start)
{
   if(isEmpty())
   {
      cout<<endl<<"Stack is Empty"<<endl;
   }
  else
  {
    if(start!=top)
     {
        rev(start->next);
        cout<<" | "<<start->item;
     }
     else
     {
        cout<<"| "<<start->item;
     }
  }
}

bool stack::isEmpty()
{  
    if(top==NULL)
    return true;
    else
    return false;
}

node* stack::peek()
{
   if(isEmpty())
   {
      cout<<endl<<"Stack is Empty"<<endl;
   }
   else
   {
      return top;
   }
   return NULL;
}

int stack::pop()
{
   if(isEmpty())
   {
       cout<<endl<<"Underflow ! stack is Empty"<<endl;
   }
   else
   {
       node *t=start;
       while(t->next!=top)
       {
            t=t->next;
       }
       node *p=top;
       delete p;
       top=t;
       top->next=NULL;
       return 1;
   }
   return 0;
}

void stack::push(int data)
{
   node *n=new node;
    if(isEmpty())
    {
      n->item=data;
      n->next=NULL;
      top=n;
    }
    else
    {
      n->item=data;
      n->next=NULL;
      top->next=n;
      top=n;
    }
}

void stack::showAll(node *start)
{
     if(start!=top)
     {
        showAll(start->next);
        cout<<"\t       | "<<start->item<<" |"<<endl;
     }
     else
     {
        cout<<"\tTOP -->| "<<start->item<<" |"<<endl;
     }
}

void stack::multipleInsert()
{
    int i,data;
   do
   {
     node *n=new node;
     cout<<endl<<"Enter Data : "; cin>>data;
     if(isEmpty())
     {
        n->item=data;
        n->next=NULL;
        top=n;
        start=n;
     }
     else
     {
        n->item=data;
        n->next=NULL;
        top->next=n;
        top=n;
     }
     cout<<endl<<"Enter 1 For Continue : "; cin>>i;
   } while(i==1);
}

void stack::ShowAll()
{
    cout<<endl<<"The Current Form Of Stack Is : \n"<<endl;
    showAll(start);
    cout<<endl;
}

void stack::reverseStack()
{
    cout<<endl<<"The Reverse From Of Stack Is : \n"<<endl;
    rev(start);
    cout<<endl;
}


int menu()
{
    int k;
    cout<<endl<<"\t________________________"<<endl;
    cout<<endl<<"\t  STACK DATA STRUCTURE USING LINKED LIST \t";
    cout<<endl<<"\t________________________\n"<<endl;
    cout<<"1.MULTIPLE INSERT"<<endl;
    cout<<"2.PUSH"<<endl;
    cout<<"3.POP"<<endl;
    cout<<"4.PEEK"<<endl;
    cout<<"5.SHOW FULL STACK"<<endl;
    cout<<"6.STACK IS EMPTY OR NOT"<<endl;
    cout<<"7.REVERSE THE STACK"<<endl;
    cout<<"8.EXIT"<<endl;
    cout<<endl<<"Enter Your Choice In Between [1/2/3/4/5/6/7/8] :- ";
    cin>>k;  return k;
}


int main()
{
    system("cls");
    stack s1;
    while(1)
    {
       switch(menu())
       {
           case 1:
           {
              s1.multipleInsert();
              cout<<endl<<"Multiple Insert Is Successful"<<endl;
              break;
           }
           case 2:
           {
              int data;
              cout<<endl<<"Enter The Data : ";  cin>>data;
              s1.push(data);
              cout<<endl<<"Push Operation Is Successful"<<endl;
              break;
           }
           case 3:
           {
              int k=s1.pop();
              if(k==1)
              {
                 cout<<endl<<"Pop Operation Is Successful"<<endl;
              }
              break;
           }
           case 4:
           {
              node *k=s1.peek();
              if(!s1.isEmpty())
              {
              cout<<endl<<"The Top Of The Stack Is "<<endl;
              cout<<endl<<"TOP --> | "<<k->item<<" |"<<endl;
              }
              break;
           }
           case 5:
           {
              if(s1.isEmpty())
              {
                 cout<<endl<<"Stack Is Empty"<<endl;
              }
              else
              {
              s1.ShowAll();
              }
              break;
           }
           case 6:
           {
              if(s1.isEmpty())
              {
                cout<<endl<<"YES Stack Is Empty"<<endl;
              }
              else
              {
                cout<<endl<<"NO! Stack Is Empty"<<endl;
              }
              break;
           }
           case 7:
           {
             if(s1.isEmpty())
              {
                 cout<<endl<<"Stack Is Empty"<<endl;
              }
              else
              { 
                s1.reverseStack();
              }
                break;
           }
           case 8:
           {
              cout<<endl<<"EXIT________________________________\n\n"<<endl;
              exit(0);
           }
           default:
           {
              cout<<endl<<"Wrong Choice! Choose Again"<<endl;
              break;
           }
       }
       cout<<endl<<"Enter Any Key To Continue_________ ";
       getch();
       system("cls");
    }
    cout<<endl;
    return 0;
}