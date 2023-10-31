#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
int menu();
using namespace std;

class employe
{
  private:
        int empId;
        char empName[30];
        long int salary;
     public:
     employe()
     {
         empId=0;
         strcpy(empName,"Empty");
         salary=0;
     }
        void setEmploye ()
        {
            cout<<endl<<"Enter Employe Id :"; cin>>empId;
            cout<<"Enter Employe Name :"; fflush(stdin); fgets(empName,30,stdin);
            empName[strlen(empName)-1]='\0';
            cout<<"Enter Employe Salary :"; cin>>salary;
        }
        void showEmploye()
        {
            cout<<endl<<"ID : "<<empId;
            cout<<endl<<"Name : "<<empName<<endl;
            cout<<"Salary : "<<salary<<endl;
        }
        void writing();
        void reading();
        void copyFile();
        void deleteF();
        void renameF();
        void deleteEmpDetails();
        void modifyEmpDetails();
};

void employe::writing()
{
    ofstream fout;
    fout.open("EmployeDetails.dat",ios::app);
    this->setEmploye();
    fout.write((char*)this,sizeof(*this));
    fout.close();
}

void employe::reading()
{
    ifstream fin;
    fin.open("EmployeDetails.dat",ios::in);
    if(!fin) 
    { 
       cout<<endl<<"File Not Found"<<endl;
    }
    else
    {
        if(fin.eof())
        {
          cout<<endl<<"No Data Found"<<endl;
        }
       fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
       {
         showEmploye();
         fin.read((char*)this,sizeof(*this));
       }
    }
    fin.close();
}
void employe::copyFile()
{
    ofstream fout;
    ifstream fin;
    char str[30];
    cout<<endl<<"Enter New File Name For Copy Records : "; 
    cin>>str;
    fout.open(str,ios::out|ios::app);
    fin.open("EmployeDetails.dat",ios::in);
    if(!fin)
    {
        cout<<endl<<"File Not Found"<<endl;
    }
    else
    {
       while(!fin.eof())
       {
         fin.read((char*)this,sizeof(*this));
         fout.write((char*)this,sizeof(*this));
       }
    }
    fin.close();
    fout.close();
}

void employe::deleteF()
{
    char str[30];
    cout<<endl<<"Enter File Name For Delete : "; cin>>str;
    int k=remove(str);
    if(k==0)
    {
        cout<<endl<<"File Successfully Deleted"<<endl;
    }
    else
    {
        cout<<endl<<"Invalid File"<<endl;
    }
}

void employe::renameF()
{
    char str[30],spr[30];
    cout<<endl<<"Enter Current File Name : "; cin>>str;
    cout<<endl<<"Enter New File Name : "; cin>>spr;
    int k=rename(str,spr);
    if(k==0)
    {
        cout<<endl<<"Rename Successfull"<<endl;
    }
    else
    {
        cout<<endl<<"Invalid File"<<endl;
    }
}

void employe::deleteEmpDetails()
{
    int id,flag=0;
    ofstream fout;
    ifstream fin;
    fout.open("temp.dat",ios::out|ios::app);
    fin.open("EmployeDetails.dat",ios::in);
    cout<<endl<<"Enter Emp Id For Delete Record: "; cin>>id;
    if(!fin) 
    {
      cout<<endl<<"File Not Found"<<endl;
    }
    else
    {
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
      if(this->empId==id)
       {
        flag=1;
       }
      else
       {
       fout.write((char*)this,sizeof(*this));
       }
       fin.read((char*)this,sizeof(*this));
      }
    }
    fout.close();
    fin.close();
    remove("EmployeDetails.dat");
    rename("temp.dat","EmployeDetails.dat");
    if(flag==1)
    {
        cout<<endl<<"Employe Details Successfully Deleted"<<endl;
    }
    else
    {
        cout<<endl<<"Unable To Delete Employe Details"<<endl;
    }
}

void employe::modifyEmpDetails()
{
    int id,flag=0,n,n1;
    fstream f;
    f.open("EmployeDetails.dat",ios::in|ios::out);
    cout<<endl<<"Enter Employe Id For Modification : "; cin>>id;
    f.seekg(0);
    if(!f)
    {
        cout<<endl<<"File Not Found"<<endl;
    }
    else
    {
        f.read((char*)this,sizeof(*this));
        while(!f.eof())
        {
            if(empId==id)
            {
                setEmploye();
                n=(sizeof(*this));
                n1=(f.tellp());
                f.seekp((n1)-(n));
                f.write((char*)this,sizeof(*this));
                flag=1;
            }
            f.read((char*)this,sizeof(*this));
        }
    }
    if(flag==1)
    {
        cout<<endl<<"Employe Details Successfully Modified"<<endl;
    }
    else
    {
        cout<<endl<<"Unable To Modify Employe Details"<<endl;
    }
    f.close();
}

int menu()
{
    int k;
    cout<<"\n_______________________________________________________";
    cout<<endl<<"_____________| EMPLOYE MANAGEMENT SYSTEM |_____________";
    cout<<endl<<"--------------------------------------------------------\n";
    cout<<endl<<"1. Enter 1 For See Employe Records      :";
    cout<<endl<<"2. Enter 2 For Insert Employe Record    :";
    cout<<endl<<"3. Enter 3 For Update Employe Record    :";
    cout<<endl<<"4. Enter 4 For Delete Employe Record    :";
    cout<<endl<<"5. Enter 5 For Delete A Whole File      :";
    cout<<endl<<"6. Enter 6 For Rename  A File Name      :";
    cout<<endl<<"7. Enter 7 For Copy One File To Another :";
    cout<<endl<<"8. Enter 8 For Exit                      :"<<endl;
    cout<<endl<<"Enter Your Choice In Between[1/2/3/4/5/6/7/8]:-  "; cin>>k;
    return k;
}

int main()
{
     employe e2;
     while(1)
     {
     system("cls");
     switch(menu())
     {
       case 1:
       {
         cout<<endl<<"Current All Employe Record_______________________"<<endl;
         e2.reading();
         break;
       }
       case 2:
       {
         cout<<endl<<"Enter New Employe Record______________________________"<<endl;
         e2.writing();
         break;
       }
       case 3:
       {
        cout<<endl<<"Update Employe Record__________________________________"<<endl;
        e2.modifyEmpDetails();
        break;
       }
       case 4:
       {
         cout<<endl<<"Delete Employe Record__________________________________"<<endl;
         e2.deleteEmpDetails();
         break;
       }
       case 5:
       {
         cout<<endl<<"Delete A Whole Employe File__________________________________"<<endl;
         e2.deleteF();
         break;
       }
       case 6:
       {
        cout<<endl<<"Rename A Employe File__________________________________"<<endl;
        e2.renameF();
        break;
       }
       case 7:
       {
         cout<<endl<<"Copay A File InTo A New File______________________________"<<endl;
         e2.copyFile();
         break;
       }
       case 8:
        {
            cout<<endl<<"Exit_____________________\n"<<endl;
            exit(0);
        }
        default:
        {
            cout<<endl<<"Invalid Choice"<<endl;

        }
     }
     cout<<endl<<"Press Any Key To Continue : ";
     getch();
    }
     cout<<endl;
     return 0;   
}