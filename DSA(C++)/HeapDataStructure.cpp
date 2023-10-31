#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void swap(int&,int&);
void Front();
int Menu();

class Heap
{
    private:
        int *ptr;
        int capacity;
        int lastIndex;
    public:
       Heap() : ptr(NULL),capacity(0),lastIndex(-1) { }
       Heap(int);
       int Insert();
       int Delete();
       void Display();
       int SearchItem(int);
       void ShowParent();
       void ShowLeftChild();
       void ShowRightChild();
       void ShowLastIndexValue();
       void CountTotalItem();
       ~Heap();
};

Heap::~Heap()
{
    delete []ptr;
    ptr=NULL;
}

Heap::Heap(int capacity)
{
    this->capacity=capacity;
    lastIndex=-1;
    ptr = new int[capacity];
}

int Heap::Insert()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,10);
    if(ptr!=NULL)
    {
       int item;
       cout<<endl<<"\t\t\t\t\t\tEnter The Item For Insert : ";
       cin>>item;
       ptr[++lastIndex]=item;
       if(lastIndex>0)
       {
           int last = lastIndex;
           int p = ((lastIndex-1)/2);
           while(1)
           {
             if(ptr[p]<ptr[last])
             {
               swap(ptr[p],ptr[last]);
             }
             else
             {
                break;
             }
             last = p;
             p = ((p-1)/2);
             if(p<0)
             {
                break;
             }
           }
       }
    }
    else
    {
        cout<<endl<<"\n\t\t\t\t\t\tError! Array Is Not Created\n"<<endl;
        return 0;
    }
    return 1;
}


int Heap::Delete()
{
    if(lastIndex<=0)
    {
        return 1;
    }
    else
    {
    int i=0;
    int t=ptr[lastIndex];
    lastIndex-=1;
    ptr[i]=t;
    while (1)
    {
       int l=2*i+1;
       int r=2*i+2;
       if(ptr[i]<ptr[l] || ptr[i]<ptr[r])
       {
         if(ptr[r]>ptr[l])
         {
           if(l>lastIndex||r>lastIndex)
           {
              break;
           } 
           int temp = ptr[r];
           ptr[r] = ptr[i];
           ptr[i] = temp;
           i=r;
         }
         else if(ptr[l]>ptr[r])
         {
            if(l>lastIndex||r>lastIndex)
            {
               break;
            }
           int temp = ptr[l];
           ptr[l] = ptr[i];
           ptr[i] = temp;
           i=l;
         }
         else
         {
           break;
         }
       }
       else
       {
           break;
       }
    }
    return 0;
  }
}

void Heap::ShowParent()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,11);
     int item;
     cout<<endl<<"\t\t\t\t\t\tEnter The Child Node For Display Its Parent Node : ";
     cin>>item;
     int j=SearchItem(item);
     if(j!=-1)
     {
       if(item==ptr[0])
       {
          cout<<endl<<"\t\t\t\t\t\tRoot Have No Parent\n";
       }
       else
       {
         int i=SearchItem(item);
         int parent = ((i-1)/2);
         if(i!=-1 && (parent<lastIndex&&parent>=0))
         {
            cout<<endl<<"\t\t\t\t\t\tParent Node Is :- \n";
            cout<<endl<<"\t\t\t\t\t\t"<<parent<<" --> "<<" | "<<ptr[parent]<<" | \n";
         }
         else
         {
            cout<<endl<<"\t\t\t\t\t\tParent Not Found\n";
         }
       }
     }
      else
      {
         cout<<endl<<"\t\t\t\t\t\tInvalid Item\n";
      }
}

void Heap::ShowLeftChild()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,5);
     int item;
     cout<<endl<<"\t\t\t\t\t\tEnter The Node For Display Its Left Child : ";
     cin>>item;
     int i=SearchItem(item);
     if(i!=-1)
     {
         int l=2*i+1;
         if(l<=lastIndex)
         {
             cout<<endl<<"\t\t\t\t\t\t\tLeft Child Is :- \n";
             cout<<"\t\t\t\t\t\t\t 0"<<l<<" --> ";
             cout<<" | "<<ptr[l]<<" | \n";
         }
         else
         {
            cout<<endl<<"\t\t\t\t\t\tThis Node Have Not Contain Any Left Child\n";
         }
     }
     else
     {
         cout<<endl<<"\t\t\t\t\t\t\tInvalid Item\n";
     }
}

void Heap::ShowRightChild()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,4);
      int item;
     cout<<endl<<"\t\t\t\t\t\tEnter The Node For Display Its Right Child : ";
     cin>>item;
     int i=SearchItem(item);
     if(i!=-1)
     {
         int r=2*i+2;
         if(r<=lastIndex)
         {
             cout<<endl<<"\t\t\t\t\t\t\tRight Child Is :- \n";
             cout<<"\t\t\t\t\t\t\t 0"<<r<<" --> ";
             cout<<" | "<<ptr[r]<<" | \n";
         }
         else
         {
            cout<<endl<<"\t\t\t\t\t\tThis Node Have Not Contain Any Right Child\n";
         }
     }
     else
     {
         cout<<endl<<"\t\t\t\t\t\t\tInvalid Item\n";
     }
}

int Heap::SearchItem(int item)
{
      for(int i=0; i<=lastIndex; i++)
      {
         if(ptr[i]==item)
         {
            return i;
         }
      }
      return -1;
}

void Heap::Display()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,3);
  if(lastIndex==-1)
  {
      cout<<endl<<"\t\t\t\t\t\tArray Is Empty\n"<<endl;
  }
  else
  {
    cout<<endl<<"\n\t\t\t\t\t\tCurrent Heap Is Looks Like : \n\n"<<endl;
    for(int i=0; i<=lastIndex; i++)
    {
        if(i<10)
        {
           cout<<"\t\t\t\t\t\t\t 0"<<i<<" --> ";
           cout<<" | "<<ptr[i]<<" | \n";
        }
        else
        {
            cout<<"\t\t\t\t\t\t\t "<<i<<" --> ";
            cout<<" | "<<ptr[i]<<" | \n";
        }
    }
  }
    cout<<endl;
}

void Heap::ShowLastIndexValue()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,2);
    cout<<endl<<"\n\t\t\t\t\t\tThe Last Index Value Is : "<<ptr[lastIndex]<<"\n";
}

void Heap::CountTotalItem()
{
    cout<<endl<<"\t\t\t\t\t\tThe Total Number Of Node Of The Heap Is = "<<lastIndex+1<<endl;
}

void swap(int &a,int &b)
{
    int t = a;
    a=b;
    b=t;
}

void Front()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,14);
    cout<<endl<<"\t\t\t\t\t\t\t\t_____________________________________________________"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t  |\4\4\4|  HEAP DATA STRUCTURE  |\4\4\4|";
    cout<<endl<<"\t\t\t\t\t\t\t\t_____________________________________________________\n\n\n"<<endl;
}

int Menu()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,9);
    int choose;
    cout<<endl<<"\t\t\t\t\t1. Insert Item_______________";
    cout<<endl<<"\t\t\t\t\t2. Display All Item__________";
    cout<<endl<<"\t\t\t\t\t3. Delete Item_______________";
    cout<<endl<<"\t\t\t\t\t4. Search Item_______________";
    cout<<endl<<"\t\t\t\t\t5. Show Parent_______________";
    cout<<endl<<"\t\t\t\t\t6. Show Left Child__________";
    cout<<endl<<"\t\t\t\t\t7. Show Right Child___________";
    cout<<endl<<"\t\t\t\t\t8. Total Node Count__________";
    cout<<endl<<"\t\t\t\t\t9. Show Last Node___________";
    cout<<endl<<"\t\t\t\t\t10. Exit____________________";
    cout<<endl<<"\n\t\t\t\t\tEnter Your Choice In Between[1/2/3/4/5/6/7/8/9/10] :- ";
    cin>>choose;
    return choose;
}

int main()
{
    system("cls");
    Front();
    int n;
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,13);
    cout<<endl<<"\t\t\t\t\t\tEnter The Array Size : ";
    cin>>n;
    Heap h1(n);
    system("cls");
    while(1)
    {
        Front();
        switch (Menu())
        {
          case 1:
          {
             system("cls");
             Front();
             int k=h1.Insert();
             if(k==1)
             {
                cout<<endl<<"\t\t\t\t\t\tInsert Successful\n"<<endl;
             }
             else
             {
                cout<<endl<<"\t\t\t\t\t\tInsert Unsuccessful\n"<<endl;
             }
             break;
          }
          case 2:
          {
              system("cls");
              Front();
              h1.Display();
              break;
          }
          case 3:
          {
              system("cls");
              Front();
              int k=h1.Delete();
              if(k==1)
              {
                cout<<endl<<"\t\t\t\t\t\tDelete Unsuccessful\n"<<endl;
              }
              else
              {
                cout<<endl<<"\t\t\t\t\t\tDelete Successful\n"<<endl;
              }
               break;
          }
          case 4:
          {
              system("cls");
              Front();
              HANDLE col;
              col=GetStdHandle(STD_OUTPUT_HANDLE);
              SetConsoleTextAttribute(col,3);
              int item;
              cout<<endl<<"\t\t\t\t\t\tEnter The Item For Search : ";
              cin>>item;
              int k=h1.SearchItem(item);
              if(k!=-1)
              {
                   cout<<endl<<"\t\t\t\t\t\tItem Found At "<<k<<" Index\n";
              }
              else
              {
                   cout<<endl<<"\t\t\t\t\t\tInvalid Item\n";
              }
               break;
          }
          case 5:
          {
              system("cls");
              Front();
              h1.ShowParent();
              break;
          }
          case 6:
          {
              system("cls");
              Front();
              h1.ShowLeftChild();
              break;
          }
          case 7:
          {
              system("cls");
              Front();
              h1.ShowRightChild();
              break;
          }
          case 8:
          {
             system("cls");
             Front();
             h1.CountTotalItem();
             break;
          }
          case 9:
          {
             system("cls");
             Front();
             h1.ShowLastIndexValue();
             break;
          }
          case 10:
          {
              system("cls");
              Front();
              HANDLE col;
              col=GetStdHandle(STD_OUTPUT_HANDLE);
              SetConsoleTextAttribute(col,16);
              cout<<endl<<"\t\t\t\t\t\tThank you For Using Heap Data Structure\n";
              cout<<endl<<"\n\t\t\t\t\t\tExit___________________________\n\n\n"<<endl;
              exit(1);
              break;
          }
          default:
          {
              system("cls");
              Front();
              cout<<endl<<"\t\t\t\t\t\tWrong Choice! Please Choose Again Carefully\n"<<endl;
              break;
          }
        }
        cout<<endl<<"\t\t\t\t\t\tEnter Any Key For Continue : ";
        getch();
        system("cls");
    }
    cout<<endl;
    return 0;
}