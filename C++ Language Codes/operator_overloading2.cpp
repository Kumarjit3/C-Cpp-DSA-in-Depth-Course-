#include<iostream>
#include<string.h>
using namespace std;

class assign
{
    private:
     int a,b;
    public:
      assign() : a(3),b(3)
      { }
      ~assign() { }
      void SetData(int a,int b)
      {
        this->a=a;
        this->b=b;
      }
      void ShowData()
      {
        cout<<endl<<"A : "<<a<<" B : "<<b<<endl;
      }
      assign(assign&);
      assign& operator =(assign&);
};


assign::assign(assign &a1)
{
   this->a=a1.a;
   this->b=a1.b;
}

assign& assign::operator =(assign &a1)
{
    this->a=a1.a;
    this->b=a1.b;
    return (*this);
}

int main()
{
    system("cls");
    assign a1;
    a1.SetData(2,3);
    cout<<endl<<"a1 Object Details : "<<endl;
    a1.ShowData();
    assign a2=a1;
    cout<<endl<<"After Assignment a1 Into a2, a2 Object Details : "<<endl;
    a2.ShowData();
    cout<<endl;
    return 0;
}