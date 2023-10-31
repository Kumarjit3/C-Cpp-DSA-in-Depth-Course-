#include<iostream>

using namespace std;

void sum();
void sub();
void mul();
void equal();
void not_equal();
void gratert();
void lesst();

class complex
{
    private:
    int real,img;
    public:
    complex(): real(3),img(3)  
    { }
    void setData(int r,int i)
    {
        real=r,img=i;
    }
    void showData() {
      if(img<=0)
      { if(img==-1) cout<<real<<" - "<<"i";
      else if(img<-1) cout<<real<<img<<"i";  else cout<<real<<" + "<<"0"; }
      else { cout<<real<<" + "<<img<<"i"; } }
    complex operator -(complex);
    complex operator +(complex);
    complex operator *(complex);
    bool operator ==(complex);
    bool operator !=(complex);
    bool operator >(complex);
    bool operator <(complex);
};

complex complex::operator -(complex c)
{
   complex ct;
   ct.real=real-c.real;
   ct.img=img-c.img;
   return ct;
}

complex complex::operator +(complex c)
{
   complex ct;
   ct.real=real+c.real;
   ct.img=img+c.img;
   return ct;
}

complex complex::operator *(complex c)
{
   complex ct;
   ct.real=(real*c.real)-(img*c.img);
   ct.img=(real*c.img)+(img*c.real);
   return ct;
}

bool complex::operator ==(complex cb)
{
     if(cb.real==real && cb.img==img)
     { return  true; } else { return false; } 
}

bool complex::operator !=(complex c)
{
    if(real != c.real || img != c.img)
    return true;
    else
    return false;
}

bool complex::operator>(complex v)
{
   if(real > v.real && img > v.img)
   { return true; } else { return false; }
}

bool complex::operator<(complex v)
{
   if(real < v.real && img < v.img)
   { return true; } else { return false;  }
}

void sum()
{
    complex c2,c3,c4;
     c4.setData(3,4);
     c2.setData(5,6);
     cout<<"Addition of complex number is: "<<endl;
     c3=c4+c2;
     c3.showData();
     cout<<endl;
}


void sub()
{
    complex c2,c3,c4;
     c4.setData(3,4);
     c2.setData(5,6);
     cout<<"Subtraction of complex number is: "<<endl;
     c3=c4-c2;
     c3.showData();
     cout<<endl;
}


void mul()
{
    complex c2,c3,c4;
     c4.setData(3,4);
     c2.setData(5,6);
     cout<<"Multiplication of complex number is: "<<endl;
     c3=c4*c2;
     c3.showData();
     cout<<endl;
}


void equal()
{
  int r; complex c,c1;
  c.setData(3,3);
  c1.setData(2,3);
  r=c==c1;
  if(r==1)
  cout<<"Yes equal";
  else
  cout<<"No not equal"<<endl;
}


void not_equal()
{
  int r; complex c,c1;
  c.setData(3,3);
  c1.setData(3,3);
  r=c!=c1;
  if(r==1)
  cout<<"Yes not equal";
  else
  cout<<"No equal"<<endl;
}

void gratert()
{
   complex c1,c2,c3; int r;
   c1.setData(3,5);
   c2.setData(2,4);
   r=c1>c2;
   if(r==1)
      cout<<"Yes grater";
   else
      cout<<"No not grater"<<endl;
}


void lesst()
{
   complex c1,c2,c3; int r;
   c1.setData(1,3);
   c2.setData(2,4);
   r=c1<c2;
   if(r==1)
      cout<<"Yes less";
   else
      cout<<"No not less"<<endl;
}

int main()
{
  
     //sum();
     //sub();
     //mul();
     //equal();
     //not_equal();
     //gratert();
     //lesst();
     complex c1,c2,c3;
     c1.setData(3,4);
     c2.setData(5,6);
     c1.showData();
     c2.showData();
     c3=c1+c2;
     c3.showData();
     cout<<endl;
     return 0;
}

