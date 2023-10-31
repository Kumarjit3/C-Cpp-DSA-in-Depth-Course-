#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct person
 {
    char name[20];
    int age;
    char address[30];

    person getInformation(person p)
      {
        cout<<"Enter name : ";
        fflush(stdin); fgets(p.name,20,stdin); p.name[strlen(p.name)-1]='\0';
        cout<<"Enter age : "; cin>>p.age;
        cout<<"Enter address : "; 
        fflush(stdin); fgets(p.address,30,stdin); p.address[strlen(p.address)-1]='\0';
        return p;
      }
     void display(person p)
       {
         cout<<endl<<"PERSON DETAILS______________"<<endl;
         cout<<endl<<"NAME : "<<p.name;
         cout<<endl<<"AGE : "<<p.age;
         cout<<endl<<"ADDRESS : "<<p.address;
         cout<<endl;
       }
};
int main()
{
    person p1,p2,p3;
    p3=p1.getInformation(p2);
    p1.display(p3);
    cout<<endl;
    return 0;
}