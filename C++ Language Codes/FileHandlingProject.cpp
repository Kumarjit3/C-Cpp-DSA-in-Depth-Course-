#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class student
{
   private:
      char Name[50];
      int Roll;
      int Age;
   public:
       void setStudent()
       {
         int Roll,Age;
        cout<<endl<<"Enter Student Name : ";
        fflush(stdin);
        cin.getline(this->Name,50);
        cout<<endl<<"Enter Student Roll : ";
        cin>>Roll; this->Roll=Roll;
        cout<<endl<<"Enter student Age : ";
        cin>>Age; this->Age=Age;
       }
       void showStudent()
       {
         cout<<endl<<"Name : "; puts(this->Name);
         cout<<"Roll : "<<this->Roll;
         cout<<endl<<"Age : "<<this->Age<<endl;
       }
       void updateStudent()
       {

       }
       void store();
       void show();
};

int menu()
{
    int k;
    cout<<endl;
    cout<<endl<<"1.Student Information Store";
    cout<<endl<<"2.Student Information Display";
    cout<<endl<<"3.Student Information Update";
    cout<<endl<<"4.Exit"<<endl;
    cout<<endl<<"Enter your choice[1/2/3/4] : ";
    cin>>k;
    return k;
}

void student::store()
{  
    ofstream fout;
    fout.open("StudentINFO.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
}

void student::show()
{
    ifstream fin;
    fin.open("StudentINFO.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<endl<<"File Not Found";
    }
    else
    {
        fin.read((char *)this,sizeof(*this));
       while(!fin.eof())
       {
         showStudent(); 
         fin.read((char *)this,sizeof(*this));
       }
    }
    fin.close();
}

int main()
{
    student s1;
    while(true)
    {
        switch(menu())
        {
            case 1:
              s1.setStudent();
              s1.store();
              break;
            case 2:
              s1.show();
              break;
            case 3:
               s1.updateStudent();
               break;
            case 4:
              cout<<endl<<"Exit__________________"<<endl;
              exit(0); 
            default:
            cout<<endl<<"Invalid Choice"<<endl;         
        }
    }
    cout<<endl;
    return 0;
}