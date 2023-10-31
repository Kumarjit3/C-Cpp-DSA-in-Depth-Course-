#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class employe
{
     private:
        int empId;
        char empName[30];
        long int salary;
     public:
        void setEmploye ()
        {
            cout<<endl<<"Enter Employe Id :"; cin>>empId;
            cout<<"Enter Employe Name :"; fflush(stdin); fgets(empName,30,stdin);
            empName[strlen(empName)-1]='\0';
            cout<<"Enter Employe Salary :"; cin>>salary;
        }
        void showEmploye()
        {
            cout<<endl<<"EMPLOYE DETAILS_______________"<<endl;
            cout<<endl<<"ID : "<<empId;
            cout<<endl<<"Name : "<<empName<<endl;
            cout<<"Salary : "<<salary<<endl;
        }
        void storeEmployRecord()
        {
            ofstream fout;
            fout.open("EmployeDetails.dat",ios::binary|ios::app);
            this->setEmploye();
            fout.write((char*)this,sizeof(*this));
            fout.close();
        }
        void showEmployRecord()
        {
            ifstream fin;
            fin.open("EmployeDetails.dat",ios::binary|ios::in);
            if(!fin)
            {
                cout<<endl<<"File Not Found"<<endl;
            }
            else
            {
               fin.read((char*)this,sizeof(*this));   
               while(!fin.eof())
               {
                showEmploye();
                fin.read((char*)this,sizeof(*this));
               }
               cout<<endl;
            }
            fin.close();
        }
        void searchEmploye()
        {
            ifstream fin; int id,k=1;
            cout<<endl<<"Enter Employe Id For Searching : "; cin>>id;
            fin.open("EmployeDetails.dat",ios::binary|ios::in);
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
                    showEmploye(); k++;
                }
                fin.read((char*)this,sizeof(*this));
               }
            }
            if(k==1) cout<<endl<<"Invalid Employe Id"<<endl;
            fin.close();
        }
        void editEmploy()
        {
           int id,k=1;
           ofstream fout;
           ifstream fin;
           fin.open("EmployeDetails.dat",ios::binary|ios::in);
           fout.open("Employe.dat",ios::binary|ios::out);
           cout<<"Enter Employe Id For Details Modifiaction : "; cin>>id;
           if(!fin)
            {
                cout<<endl<<"File Not Found"<<endl;
            }
            else
            {
               while(fin.read((char*)this,sizeof(*this)))
               {
                if(this->empId==id)
                {
                    cout<<"EmpId = "<<this->empId;
                    this->storeEmployRecord(); k++;
                }
                fout.write((char*)this,sizeof(*this));
               }
            }
            if(k==1) cout<<endl<<"Invalid Employe Id"<<endl;
            remove("EmployeDetails.dat");
            rename("Employe.dat","EmployeDetails.dat");
            fout.close();
            fin.close();
        } 
};

void writing()
{
    ofstream fout;
    fout.open("NewFile.txt",ios::app);
    char str[100];
    fflush(stdin);
    cout<<endl<<"Enter a string : ";
    cin.getline(str,100);
    str[strlen(str)]='\0';
    fout<<str;
    fout.close();
}

void reading()
{
    ifstream fin;
    fin.open("NewFile.txt",ios::in);
    if(!fin)
    {
        cout<<endl<<"File Not Found"<<endl;
    }
    else
    {
        fin.seekg(0);
        char ch=fin.get();
        cout<<endl;
        while(!fin.eof())
        {
            cout<<ch;
            ch=fin.get();
        }
        cout<<endl;
    }
    fin.close();
}

void copyFile()
{
    ofstream fout;
    ifstream fin;
    fout.open("NewFile1.txt",ios::app);
    fin.open("NewFile.txt",ios::in);
    if(!fin)
    {
        cout<<endl<<"File Not Found"<<endl;
    }
    else
    {
        char ch=fin.get();
        cout<<endl;
        while(!fin.eof())
        {
            fout<<ch;
            ch=fin.get();
        }
        cout<<endl;
    }
    cout<<endl<<"Process Is Done"<<endl;
    fin.close();
}

void serachWord()
{
    ifstream fin; int i=1,j=-1;  char ch,k[30],str[30];
    fin.open("NewFile.txt",ios::in);
    if(!fin)
    {
        cout<<endl<<"File Not Found";
    }
    else
    {
        ch=fin.get();
        cout<<endl<<"Enter the word : "; cin>>str;
        while(!fin.eof())
        {
           if(ch!=' ')
           {
             k[++j]=ch;
           }
           else
           {
             i=strcmp(k,str);
             if(i==0)
             {
             cout<<endl<<"Word Is Successfully Found"<<endl;
             break;
             }
             memset(k, '\0',sizeof(k));
             j=-1;
           }
          ch=fin.get();
        }
    }
    if(i==1)
    cout<<endl<<"Word Is Not Found"<<endl;
    fin.close();
}

void deleteFile()
{
     char str[100]; int k;
     cout<<endl<<"Enter The File Name : ";
     cin>>str;
     k=remove(str);
     if(k==0)
     {
        cout<<endl<<"File Deleted Successfully"<<endl;
     }
     else
     {
        cout<<endl<<"Error occurs"<<endl;
     }
}

int main()
{
    employe e2;
    //e2.storeEmployRecord();
   // e2.storeEmployRecord();
    e2.showEmployRecord();
    e2.editEmploy();
    e2.showEmployRecord();
   // deleteFile();
    cout<<endl;
    return 0;
}