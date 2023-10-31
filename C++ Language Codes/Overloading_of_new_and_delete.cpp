#include<iostream>
using namespace std;

class student
{
   private:
       string name;
       int roll;
       int age;
   public:
     student(string name,int roll,int age)
     {
        this->name=name;
        this->roll=roll;
        this->age=age;
     }
     void display()
     {
        cout<<endl<<"Neme : "<<name<<endl;
        cout<<"Roll : "<<roll<<endl;
        cout<<"Age : "<<age<<endl;
     }
     void* operator new (size_t size)
     {
        cout<<endl<<"Overloaded New Operator is Called"<<endl;
          void *p=malloc(size);
          return p;
     }
     void operator delete(void* p)
     {
        cout<<endl<<"Overloaded Delete Operator is Called"<<endl;
        free(p);
     }    

};

int main()
{
    system("cls");
    student *p=new student("Yash",1,24);
    p->display();
    delete(p);
    cout<<endl;
    return 0;
}


