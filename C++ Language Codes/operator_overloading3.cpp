#include<iostream>
using namespace std;

class complex 
{
    private:
      int real,img;
    public:
    ~complex() {}
    void setData(int real,int img) { this->real=real;  this->img=img; }
    void showData() { cout<<endl<<real<<" "<<img<<"i"<<endl; }
    friend istream& operator >>(istream&,complex&);
    friend ostream& operator <<(ostream&,complex);
    complex operator +(complex);
    complex operator *(complex);
    complex operator ++();
    complex operator ++(int);
};

complex complex::operator ++()
{
  complex cc;
  cc.real=++real;
  cc.img=++img;
  return cc;
}

complex complex::operator ++(int)
{
  complex cc;
  cc.real=real++;
  cc.img=img++;
  return cc;
}

complex complex::operator +(complex c)
{
   complex cc;
   cc.real=real+c.real;
   cc.img=img+c.img;
   return cc; 
}


complex complex::operator *(complex c)
{
   complex ct;
   ct.real=(this->real*c.real)-(this->img*c.img);
   ct.img=(this->real*c.img)+(this->img*c.real);
   return ct;
}

istream& operator >>(istream &din,complex &c)
{
    cout<<endl<<"Enter Real : ";
     din>>c.real;
     cout<<endl<<"Enter img : ";
     din>>c.img;
     return din;
}

ostream& operator <<(ostream &dout,complex c)
{
    dout<<endl<<c.real<<" + "<<c.img<<"i"<<endl;
    return dout;
}

int main()
{
    system("cls");
    complex cc1,cc2,cc3;
    cout<<endl<<"Enter CC1 Objects Details : "<<endl;
    cin>>cc1;
    cout<<endl<<"Enter CC2 Objects Details : "<<endl;
    cin>>cc2;
    cout<<endl<<"CC1 Objects Details : "<<endl;
    cout<<cc1;
    cout<<endl<<"CC2 Objects Details : "<<endl;
    cout<<cc2;
    cc3=cc1+cc2;
    cout<<endl<<"The Addition Of CC1 And CC2 Is : "<<endl;
    cc3.showData();
    cc3=cc1*cc2;
    cout<<endl<<"The Multiplication Of CC1 And CC2 Is : "<<endl;
    cc3.showData();
    complex c1,c2,c4,c5;
    c1.setData(2,3);
    c2.setData(3,4);
    cout<<endl<<"C1 Objects Details : "<<endl;
    c1.showData();
    cout<<endl<<"C2 Objects Details : "<<endl;
    c2.showData();
    cout<<endl<<"Before Post Increment Of C1 Object : "<<endl;
    c4=c1++;
    c4.showData();
    cout<<endl<<"After Pre Increment Of C2 Object : "<<endl;
    c5=++c2;
    c5.showData();
    cout<<endl;
    return 0;
}