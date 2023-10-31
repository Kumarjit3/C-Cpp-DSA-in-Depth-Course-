#include<iostream>
using namespace std;

class one
{
    private:
        int x;
    public:
       one() : x(3) { }
       void showX()
       {
          cout<<endl<<"X : "<<x<<endl;
       }    
};

class two
{
    private:
        int y;
    public:
      two() : y(6) { }
      void showY()
      {
        cout<<endl<<"Y : "<<y<<endl;
      }    
      friend void one::showX();
};

void one::showX()
{
   cout<<"Classs two";
}

int main()
{
    system("cls");
    two t1;
    cout<<endl;
    t1.showY();
    cout<<endl;
    t1.showY();
    cout<<endl;
    return 0;
}