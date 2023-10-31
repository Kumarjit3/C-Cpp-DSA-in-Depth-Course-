#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class person
{
    protected:
      string name;
      int age;
    public:
      /*person(string name,int age)
      {
        this->name=name;
        this->age=age;
      }  */
      ~person() {}
    void setPerson(string name,int age)
    {
        this->name=name;
        this->age=age;
    }  
    void showPerson() 
    {
        cout<<endl<<"Name : "<<name<<endl<<"Age : "<<age<<endl;
    }
};


void setData(string n,int a)
{
    person *p = new person;
    p->setPerson(n,a);
    p->showPerson();
    cout<<endl;
}

int main()
{
    //person pp("kumarjit",20);
    person pp;
    //pp.setPerson("kumarjit",21);
    //pp.showPerson();
    setData("Kumarjit",33);
    cout<<endl;
    return 0;
}
