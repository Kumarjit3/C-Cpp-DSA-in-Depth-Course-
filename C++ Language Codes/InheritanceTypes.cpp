#include<iostream>
#include<string>
using namespace std;

/*class Person  //Hierarchical inheritance
{
     private:
        int age;
        char name[20];
     public:
        void showName() {   cout<<endl<<name<<endl;  }  
        void showAge() {  cout<<endl<<age<<endl; } 
};

class Employee:public Person
{
     private:
        int salary;
        string department;
     public:
           void showDepartment()  {  cout<<endl<<department<<endl; }
           void showSalary() {  cout<<endl<<salary<<endl; }
};

class BusinessMan:public Person
{
      private:
        int employees;
        int NoOfCompanies;
        long long int PMI; 
      public:
         void showEmployee()  {  cout<<employees<<endl; }
         void showCompanies()  { cout<<endl<<showCompanies<<endl;  } 
};*/

/*class Vehicle
{
    public:
    int gear;
    void setGear(int a) { gear=a; }
    void showGear() { cout<<endl<<"Gear :- "<<gear<<endl; }
};

class car:public Vehicle
{
    public:
     void setGear(int a) { gear=a; }
     void showGear() { cout<<endl<<"Gear :- "<<gear<<endl; }
};

class sportsCar:public car
{
   public:
     void setGear(int a) { gear=a; }
     void showGear() { cout<<endl<<"Gear :- "<<gear<<endl; }
};*/

class A
{
     private:
       int a;
      void setaA(int a) { this->a=a; }
     protected:
      int b;
      void setaB(int b) { this->b=b; }
     public:
       int c;
       void setaC(int c) { this->c=c; } 
};


int main()
{
    system("cls");
    A a1;
    cout<<endl;
    return 0;
}