#include<iostream>
using namespace std;

class complex
{
    private:
      int real;
      int img;
   public:
      void setData(int real,int img) 
      {
          this->real=real;
          this->img=img;      
      }  
      void showData()
      {
         cout<<real<<" "<<img<<"i";
      }

      friend istream& operator>>(istream&,complex&);
      friend ostream& operator<<(ostream&,complex);
};


istream& operator>>(istream &din,complex &c)
{
   cout<<endl<<"Enter real and img values : ";
     din>>c.real>>c.img;
     return din;
}

ostream& operator<<(ostream &dout,complex c)
{
   dout<<c.real<<c.img;
   return dout;
}

int main()
{
   complex c1,c2;
   c1.setData(2,3);
   cin>>c2;
   cout<<c2;
   cout<<c1;
   cout<<endl;
   return 0;
}