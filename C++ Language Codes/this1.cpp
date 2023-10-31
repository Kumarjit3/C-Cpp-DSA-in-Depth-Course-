#include<iostream>
using namespace std;

class item
{
    private:
       int a;
       int b;
    public:
    item() : a(3),b(3) { }
    ~item() {}
    void set_item(int a,int b)
    {
        this->a = a;
        this->b = b;
    }
    void show_item()
    {
        cout<<endl<<"a : "<<a<<endl<<"b : "<<b<<endl;
    }
    item greater(item i)
    {
        if(i.a+i.b < a+b)
             *this;
        else
            return i;
    }   
};


int main()
{
    item i1,i2,i3;
    i1.set_item(2,6);
    i2.set_item(5,7);
    i3=i1.greater(i2);
    i1.show_item();
    i2.show_item();
    i3.show_item();
    cout<<endl;
    return 0;
}