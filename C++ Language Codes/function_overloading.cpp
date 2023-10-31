void volume(float,float,float);
void volume(double);
void volume(float,float);

#include<iostream>
using namespace std;

int main()
{
    //volume(2.2,3.3,5.5);
   // volume(3.3);
   volume(3.3,5.5);
    return 0;
}

void volume(float w,float h,float l)
{
     float v;
     v=(w*h*l);
     cout<<"The volume of cuboid is:- "<<v;
}

void volume(double r)
{
    double a,p,v;
    a=1.3333333333333; p=3.1428571428571;
    v=((a*p)*(r*r*r));
    cout<<"The volume of sphere is:- "<<v;
}

void volume(float r,float h)
{
    double a,p,v;
    a=h/3; p=3.1428571428571;
    v=(p*(r*r)*a);
    cout<<"The volume of cone is:- "<<v;
}