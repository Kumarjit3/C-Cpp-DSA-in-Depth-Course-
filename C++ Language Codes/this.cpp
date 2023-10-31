#include<iostream>

using namespace std;

class item
{
    private:
       int a;  
       int b;
    public:
       item() 
       {
          a=3;
          b=5;
       }
       item& setData(int a,int b)
       {
           this->a=a;
           this->b=b;
           return (*this);
       }  
       void showData()
       {
          cout<<endl<<"A : "<<a;
          cout<<endl<<"B : "<<b<<endl;
       } 
};



int main()
{
    item i1,i2; 
    i2=i1.setData(12,13);
    i2.showData();
    cout<<endl;
    return 0;
}