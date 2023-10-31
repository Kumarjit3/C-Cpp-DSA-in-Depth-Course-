#include<iostream>
using namespace std;

class A
{
    private:
     int a;
     public:
      A(int a) { this->a=a;   cout<<endl<<"Constructor of class A"<<endl;  }
      ~A() { cout<<endl<<"Destructor of class A"; }
      void show_A() { cout<<endl<<"A : "<<a<<endl; }
};

class B
{
    private:
      int b;
    public:
     B(int b)
      { this->b=b;  cout<<endl<<"Constructor of class B"<<endl; }
     ~B() { cout<<endl<<"Destructor of class B"; } 
     void show_B() { cout<<endl<<"B : "<<b<<endl; }  
};


class C : public B,public A
{
    private:
     int c;
    public:
    C(int c) : B(c),A(c)
    { this->c=c;  cout<<endl<<"Constructor of class C"<<endl;  }
    ~C() { cout<<endl<<"Destructor of class C"<<endl; }
    void show_C() { cout<<endl<<"C : "<<c<<endl;  }
};


class D: public C
{
     private:
     int d;
     public:
     D(int d) : C(d)
     { this->d=d; cout<<endl<<"Constructor of class D"<<endl; }
     ~D() { cout<<endl<<"Destructor of class D"<<endl; }
     void show_D() { cout<<endl<<"D : "<<d<<endl; }
};


class E: public C
{
     private:
     int e;
     public:
     E(int e) : C(e)
     { this->e=e; cout<<endl<<"Constructor of class E"<<endl; }
     ~E() { cout<<endl<<"Destructor of class E"<<endl; }
     void show_E() { cout<<endl<<"E : "<<e<<endl; }
};


int main()
{
     A a1(1); B b1(12); C c1(123); D d1(4); E e1(5);
     a1.show_A();
     b1.show_B();
     c1.show_A();
     c1.show_B();
     c1.show_C();
     d1.show_A();
     d1.show_B();
     d1.show_C();
     d1.show_D();
     e1.show_A();
     e1.show_B();
     e1.show_C();
     e1.show_E();
    cout<<endl;
    return 0;
}
