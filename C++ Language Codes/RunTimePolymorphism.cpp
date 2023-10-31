#include<iostream>
using namespace std;

int login();

class User
{
   public:  
   User&  tellUser() { return *this; }
   virtual void showDetails()
    {
         cout<<endl<<"User Login Successfull_____________________"<<endl;
    }
};

class Teacher: public User
{
    public:
      Teacher& tellUser() { return *this; } 
      void showDetails()
       {
          cout<<endl<<"Teacher Login Successfull_______________________"<<endl;
       }
};

class Admin: public User
{
    public:
     Admin& tellUser() { return *this; }
      void showDetails()
      {
        cout<<endl<<"Admin Login Successfull_______________________"<<endl;
      }
};

class Learner: public User
{
    public:
     Learner& tellUser() { return *this; }
      void showDetails()
      {
        cout<<endl<<"Learner Login Successfull_______________________"<<endl;
      }
};


int login()
{
    int A; string str,spr;
    cout<<endl<<"Welcome To Learn Code"<<endl;
    cout<<endl<<"If you are Admin then enter 1   : ";
    cout<<endl<<"If you are Learner then enter 2 : ";
    cout<<endl<<"If you are Teacher then enter 3 : "<<endl; 
    cout<<endl<<"Select Between[1/2/3]_________ : "; cin>>A;
    if(A==1)
     {
        cout<<endl<<"Admin just enter your login code : "; cin>>A;
        return 1;
     }
    else if(A==2)
    {
        cout<<endl<<"Learner Please enter your email first : "; cin>>str;
        cout<<endl<<"And now enter your pasward  : "; cin>>spr;
        return 2;
    }
    else if(A==3)
    {
        cout<<endl<<"Sir pleace enter your pasward : "; cin>>spr;
        return 3;
    }
    else return 0;
}


User& getUser(int n)
 {
    User u1,*ptr; Teacher t1; Admin a1; Learner l1; 
    if(n==1)
    {
        ptr=&(a1.tellUser());
    }
   else if(n==2)
    {
        ptr=&(l1.tellUser());
    }
    else if(n==3)
    {
        ptr=&(t1.tellUser());
    }
    else 
    {
        ptr=&(u1.tellUser());
    }
    return *ptr;
 }

int main()
{
    system("cls");
    User u1; Admin a1; Learner l1;
    int k=login();
   User *ptr=&(getUser(k));
   ptr->showDetails();
   cout<<endl;
   return 0;
}


