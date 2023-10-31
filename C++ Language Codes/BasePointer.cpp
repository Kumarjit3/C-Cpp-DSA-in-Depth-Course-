#include<iostream>
using namespace std;

class A
{
    public:
      void f1()
      {
        cout<<endl<<"F1 of A"<<endl;
      }
};


class B : public A
{
    public:
        void f2()
        {
           cout<<endl<<"F2 of B"<<endl;
        }
};


int main()
{
    system("cls");
    B *p;  //base pointer
    B b1; //object of b class
    p=&b1;
    p->f1();
    p->f2(); //Error
   cout<<endl;
   return 0;
}