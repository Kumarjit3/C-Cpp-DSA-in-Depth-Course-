#include<iostream>
#include<conio.h>
#include<stdio.h>
int menu();

using namespace std;   

class stack
{
     private:
        int capacity;
        int *ptr;
        int top;
    public:
        stack();
        stack(int);
        void createStack(int);
        int push(int); 
        int pop();
        void peek();
        bool isEmpty();
        bool isFull();
        void showAll();
        int showCapacity();
        int ShowTop();
        stack(stack&);
        stack& operator=(stack&);
        ~stack();
};

stack::~stack()
{
    if(ptr!=NULL)
    delete []ptr;
}

stack& stack::operator=(stack &s)
{
    if(ptr!=NULL)
    delete []ptr;
    capacity=s.capacity;
    top=s.top;
    ptr=new int [capacity];
    for(int i=0; i<=top; i++)
    ptr[i]=s.ptr[i];
    return (*this);
}

stack::stack(stack &s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0; i<=top; i++)
    ptr[i]=s.ptr[i];
}

stack::stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}

void stack::createStack(int cap)
{
    if(ptr!=NULL)
    delete []ptr;
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}

stack::stack()
{
    capacity=0;
    ptr=NULL;
    top=-1;
    ptr=new int[capacity];
}

int stack::showCapacity()
{
    return capacity;
}

int stack::ShowTop()
{
    return top;
}

void stack::showAll()
{
    if(isEmpty())
    {
        cout<<endl<<"Stack Is Empty"<<endl;
    }
    else
    {
        cout<<endl;
        int t=top;
        while(t!=-1)
        {
            if(t==top)
            cout<<"TOP --> | "<<ptr[t--]<<" |"<<endl;
            else
            cout<<"        | "<<ptr[t--]<<" |"<<endl;
        }
    }
}

bool stack::isEmpty()
{
    if(top==-1)
    return true;
    else
    return false;
}

bool stack::isFull()
{
    if(top+1==capacity)
    return true;
    else
    return false;
}

int stack::push(int data)
{
    if(isFull())
    {
        cout<<endl<<"OverFlow : Stack Is Full"<<endl;
        return 2;
    }
    else if(top+1<capacity)
    {
      top++;
      ptr[top]=data;
      return 1;
    }
    return 0;
}

int stack::pop()
{
   if(top==-1)
   {
      cout<<endl<<"Underflow : Stack Is Empty"<<endl;
      return 0;
   }
   else
   {
     ptr[top]=0;
     top--;
     return 1;
   }
   return 0;
}

void stack::peek()
{
    if(top==-1)
   {
      cout<<endl<<"Stack Is Empty"<<endl;
   }
   else
   {
      cout<<endl<<"TOP --> | "<<ptr[top]<<"| "<<endl;
   }
}


int menu()
{
    int k;
    cout<<endl<<"\t________________________"<<endl;
    cout<<endl<<"\t  STACK DATA STRUCTURE USING ARRAY\t";
    cout<<endl<<"\t________________________\n"<<endl;
    cout<<"1.CREATE STACK"<<endl;
    cout<<"2.PUSH"<<endl;
    cout<<"3.POP"<<endl;
    cout<<"4.PEEK"<<endl;
    cout<<"5.SHOW FULL STACK"<<endl;
    cout<<"6.STACK IS EMPTY OR NOT"<<endl;
    cout<<"7.STACK IS FULL OR NOT"<<endl;
    cout<<"8.SHOW STACK CAPACITY"<<endl;
    cout<<"9.SHOW TOP POSITION"<<endl;
    cout<<"10.EXIT"<<endl;
    cout<<endl<<"Enter Your Choice In Between [1/2/3/4/5/6/7/8/9/10] :- ";
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
                int cap;
                cout<<endl<<"Enter The Capacity : "; cin>>cap;
                s1.createStack(cap);
                break;
            }
            case 2:
            {
                int d,k;
                cout<<endl<<"Enter Data : "; cin>>d;
                k=s1.push(d);
                if(k==1)
                cout<<endl<<"PUSH SUCCESSFULL"<<endl;
                break;
            }
            case 3:
            {
                int k=s1.pop();
                if(k==1)
                cout<<endl<<"POP SUCCESSFULL"<<endl;
                break;
            }
            case 4:
            {
                s1.peek();
                break;
            }
            case 5:
            {
               if(!s1.isEmpty())
               {
                 cout<<endl<<"Current OverView Of The Stack_________"<<endl;
                 s1.showAll();
               } 
               else
               s1.showAll();
               break;
            }
            case 6:
            {
                int k=s1.isEmpty();
                if(k==1)
                {
                    cout<<endl<<"Yes Stack Is Empty"<<endl;   
                }
                else
                { 
                   cout<<endl<<"NO Stack Is Not Empty"<<endl;
                }
                break;
            }
            case 7:
            {
                int k=s1.isFull();
                if(k==1)
                {
                    cout<<endl<<"Yes Stack Is Full"<<endl;   
                }
                else
                { 
                   cout<<endl<<"NO Stack Is Not Full"<<endl;
                }
                break;
            }
            case 8:
            {
                int k=s1.showCapacity();
                cout<<endl<<"Stack Capacity Is : "<<k<<endl;
                break;
            }
            case 9:
            {
                int k=s1.ShowTop();
                cout<<endl<<"The Current Top Position Is : "<<k<<endl;
                break;
            }
            case 10:
            {
                cout<<endl<<"\n\nExit______________________________________\n\n"<<endl;
                exit(0);
                break;
            }
            default:
            {
                cout<<endl<<"Wrong Choice ! Choose Again"<<endl;
                break;
            }
        }
        cout<<endl<<"Enter Any Key To Continue : "; 
        getch();
        system("cls");
    }
    cout<<endl;
    return 0;
}