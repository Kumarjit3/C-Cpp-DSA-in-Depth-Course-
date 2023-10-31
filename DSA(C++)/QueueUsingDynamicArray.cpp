#include<iostream>
#include<conio.h>
using namespace std;

int menu();

class queue
{
     private:
        int *ptr;
        int front;
        int rear;
        int capacity;
     protected:
        void doubleArray();
        void halfArray();      
     public:
        queue();
        void createQueue(int);
        void multipleInsert();
        void showAll();
        bool isEmpty();
        bool isFull();
        int Delete();
        void showFront();
        void showRear();
        int Insert(int);
        int countItem();
        int showCapacity();
        int frontIndex();
        bool ptrNull();
        queue(queue&);
        queue& operator=(queue&);
        ~queue();
};

queue::~queue()
{
    delete []ptr;
}

queue& queue::operator=(queue &s)
{
    while(ptr!=NULL)
    delete []ptr;
    ptr=NULL;
    front=rear=-1;
    capacity=s.capacity;
    front=s.front; rear=s.rear;
    ptr=new int[s.capacity]; int i;
    for(i=s.front; i<=s.rear; i++)
    ptr[i]=s.ptr[i];
    return (*this);
}

queue::queue(queue &s)
{
    capacity=s.capacity;
    front=s.front; rear=s.rear;
    ptr=new int[s.capacity]; int i;
    for(i=s.front; i<=s.rear; i++)
    ptr[i]=s.ptr[i];
}

void queue::halfArray()
{
    capacity=capacity/2;
    int *temp=new int[capacity];
    for(int i=front; i<=rear; i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}

void queue::doubleArray() 
{
    capacity=capacity*2;
    int *temp=new int[capacity];
    for(int i=front; i<=rear; i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}

bool queue::ptrNull()
{
    if(ptr==NULL)
    return true;
    else
    return false;
}

int queue::frontIndex()
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array is Not created Create Array First"<<endl;
    }
    else
    {
        return front;
    }
    return 0;   
}

int queue::showCapacity()
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array is Not created Create Array First"<<endl;
    }
    else
    {
        return capacity;
    }
    return 0;
}

int queue::countItem()
{
  if(ptr==NULL)
    {
        cout<<endl<<"Array is Not created Create Array First"<<endl;
    }
    else if(isEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    {
        int c=0;
        for(int i=front; i<=rear; i++)
        {
            c++;
        }
        return c;
    }
    return 0;
}

int queue::Insert(int data)
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array Is Not Created ! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
        front++;
        rear++;
        ptr[rear]=data;
        return 1;
    }
    else if(isFull())
    {
        doubleArray();
        rear++;
        ptr[rear]=data;
        return 2;
    }
    else
    {
        rear++;
        ptr[rear]=data;
        return 1;
    }
    return 0;
}

void queue::showFront()
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array is Not created Create Array First"<<endl;
    }
    else if(isEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    {
        cout<<endl<<"FRONT --> | "<<ptr[front]<<" | "<<endl;
    }
}


void queue::showRear()
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array is Not created Create Array First"<<endl;
    }
    else if(isEmpty())
    {
        cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    {
        cout<<endl<<"REAR --> | "<<ptr[rear]<<" |"<<endl;
    }
}


int queue::Delete()
{
     if(ptr==NULL)
    {
       cout<<endl<<"Array Is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
       cout<<endl<<"UNDERFLOW ! Queue Is Empty"<<endl;
    }
    else if(rear==capacity/2)
    {
        halfArray();
        return 2;
    }
    else if(rear<capacity/2)
    {
        halfArray();
        for(int i=front; i<rear; i++)
        {
            ptr[i]=ptr[i+1];
        }
        return 2;
   }
    else
    {
        for(int i=front; i<rear; i++)
        {
            ptr[i]=ptr[i+1];
        }
        return 1;
    }
    return 0;
}

void queue::showAll()
{
    if(ptr==NULL)
    {
      cout<<endl<<"Array Is Not Created! Create Array First"<<endl;
    }
    else if(isEmpty())
    {
    cout<<endl<<"Queue Is Empty"<<endl;
    }
    else
    {
        int c=front;
        while(c<=rear)
        {
            if(c==front)
            cout<<endl<<"FRONT --> | "<<ptr[c++]<<" |";
            else if(c==rear)
            cout<<endl<<"REAR  --> | "<<ptr[c++]<<" |";
            else
            cout<<endl<<"          | "<<ptr[c++]<<" |";
        }
        cout<<endl;
    }
}

bool queue::isEmpty()
{
    if(front==-1 && rear==-1)
    return true;
    else
    return false;
}

bool queue::isFull()
{
    if(rear+1==capacity)
    return true;
    else
    return false;
}

void queue::multipleInsert()
{
    if(ptr==NULL)
    {
        cout<<endl<<"Array Is Not Created! Create Array First"<<endl;
    }
    else
    {
    int data,i;
    do
    {
      cout<<endl<<"Enter The Data : "; cin>>data;
     if(ptr==NULL)
     {
         cout<<endl<<"Array Is Not Created! Create Array First"<<endl;
     }
     else if(isEmpty())
     {
        front++;
        rear++;
        ptr[front]=data;
     }
     else if(isFull())
     {
         doubleArray();
         rear++;
         ptr[rear]=data;
     } 
     else
     {
       rear++;
       ptr[rear]=data;  
     }
    cout<<endl<<"Enter 1 for coninue : "; cin>>i;
   
   } while(i==1);
 }
}

void queue::createQueue(int capacity)
{
    this->capacity=capacity;
    if(ptr!=NULL)
    delete []ptr;
    ptr=new int[capacity];
    cout<<endl<<"QUEUE IS CREATED"<<endl;
}

queue::queue()
{
    ptr=NULL;
    front=-1;
    rear=-1;
    capacity=-1;
}


int menu()
{
    int k;
    cout<<endl<<"\tQUEUE DATA STRUCTURE USING DYNAMIC ARRAY"<<endl;
    cout<<endl<<"1. CREATE ARRAY";
    cout<<endl<<"2. MULTIPLE INSERT";
    cout<<endl<<"3. SINGLE INSERT";
    cout<<endl<<"4. SHOW FULL QUEUE";
    cout<<endl<<"5. SHOW FRONT";
    cout<<endl<<"6. SHOW REAR";
    cout<<endl<<"7. SHOW FRONT CURRENT INDEX";
    cout<<endl<<"8. SHOW CAPACITY";
    cout<<endl<<"9. ARRAY EMPTY OR NOT";
    cout<<endl<<"10. ARRAY FULL OR NOT";
    cout<<endl<<"11. TOTAL ITEM";
    cout<<endl<<"12. DELETE ITEM";
    cout<<endl<<"13. EXIT"<<endl;
    cout<<endl<<"Enter Your Choice In Between[1/2/3/4/5/6/7/8/9/10/11/12/13] :- ";
    cin>>k;
    return k;
}



int main()
{
    system("cls");
    queue q1;
    while(1)
    {
        switch(menu())
        {
            case 1:
            {
                int cap;
                cout<<endl<<"Enter The Queue Capacity : "; cin>>cap;
                q1.createQueue(cap);
                break;
            }
            case 2:
            {
                q1.multipleInsert();
                if(!q1.isEmpty())
                cout<<endl<<"Multiple Insert Is Successful"<<endl;
                break;
            }
            case 3:
            {
                if(q1.ptrNull())
                { 
                   cout<<endl<<"Array Is Not Created! Create Array First"<<endl;
                }
                else
                { 
                int data;
                cout<<endl<<"Enter The Data : "; cin>>data;
                int k=q1.Insert(data);
                if(k==1)
                cout<<endl<<"Single Insert is Successful"<<endl;
                if(k==2)
                cout<<endl<<"Single Insert is Successful Using Dynamic Array"<<endl;
                }
                break;
            }
            case 4:
            {
                q1.showAll();
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
                int k=q1.frontIndex();
                if(k>=0)
                cout<<endl<<"Current Front Index Value Is : "<<k<<endl;
                break;
            }
            case 8:
            {
                int k=q1.showCapacity();
                if(k!=0)
                 cout<<endl<<"The Capacity Is : "<<k<<endl;
                 break;
            }
            case 9:
            {
                if(q1.isEmpty())
                  cout<<endl<<"YES Queue Is Empty"<<endl;
                else
                  cout<<endl<<"NO! Queue Is Not Empty"<<endl;
                  break;
            }
            case 10:
            {
                if(q1.isFull())
                  cout<<endl<<"YES Queue Is Full"<<endl;
                else
                  cout<<endl<<"NO! Queue Is Not Full"<<endl;
                  break;
            }
            case 11:
            {
                int k=q1.countItem();
                if(k!=0)
                cout<<endl<<"The Total Number Of Items Is : "<<k<<endl;
                break;
            }
            case 12:
            {
                int k=q1.Delete();
                if(k==1)
                 cout<<endl<<"Deletetion Is Successful"<<endl;
                if(k==2)
                 cout<<endl<<"Deletetion Is Successful Using Dynamic Array"<<endl;
                 break;
            }
            case 13:
            {
                cout<<endl<<"EXIT____________________________________\n"<<endl;
                exit(0);
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

