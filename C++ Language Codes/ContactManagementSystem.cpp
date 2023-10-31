#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<string.h>
#include<conio.h>
using namespace std;

//Declaration's of functions

void AddContact();
void SearchContact();
void DeleteContact();
void CountTotalContact();
void Front();
int Menu();
void DisplayAllContact();
bool Check_digit(string);
bool Check_number(string);
void Help();

//Global Variable's

string FirstName,LastName,Phone_number;


//Defination's of functions

void Front()
{
    
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,6);
    cout<<endl<<"\n\n\t\t\t\t\t\t\t-----------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t\tCONTACT MANAGEMENT SYSTEM\n";
    cout<<"\t\t\t\t\t\t\t-----------------------------------------\n\n\n"<<endl;
}

int Menu()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    int option;
    SetConsoleTextAttribute(col,3);
    cout<<endl<<"\t\t\t\t\t1. ADD NEW CONTACT\n";
    cout<<endl<<"\t\t\t\t\t2. DELETE CONTACT\n";
    cout<<endl<<"\t\t\t\t\t3. SEARCH CONTACT\n";
    cout<<endl<<"\t\t\t\t\t4. VIEW ALL CONTACT\n";
    cout<<endl<<"\t\t\t\t\t5. TOTAL NUMBER OF CONTACT\n";
    cout<<endl<<"\t\t\t\t\t6. HELP\n";
    cout<<endl<<"\t\t\t\t\t7. EXIT\n";
    SetConsoleTextAttribute(col,10);
    cout<<endl<<"\n\t\t\t\t\tENTER YOUR CHOICE IN BETWEEN[1/2/3/4/5/6/7] :- ";
    cin>>option;
    return option;
}


bool Check_digit(string number)
{
     if(number.length() == 10)
     return true;
     else
     return false;
}


bool Check_number(string num)
{
    bool check = true;
    for(int i=0; i<num.length(); i++)
    {
        if(!(int(num[i]) >=48 && int(num[i])<=57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    else
    return false;
}

void AddContact()
{
    system("cls");
    Front();
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,13);
    ofstream phone("ContactManagementSystem.txt",ios::app);
    string FirstName,LastName,Phone_number;
    cout<<endl<<"\t\t\t\t\tADDING A NEW CONTACT\n"<<endl;
    cout<<endl<<"\t\t\t\t\tEnter First Name :- ";
    cin>>FirstName;
    cout<<endl<<"\t\t\t\t\tEnter Last Name :- ";
    cin>>LastName;
    cout<<endl<<"\t\t\t\t\tEnter 10 Digit Number :- ";
    cin>>Phone_number;

    //Now We Check The Number Is Valid Or Not

    if(Check_digit(Phone_number) == true)
    {
        if(Check_number(Phone_number) == true)
        {
           if(phone.is_open())
           {
               phone<<FirstName<<endl<<LastName<<endl<<Phone_number<<endl;
               cout<<endl<<"\n\t\t\t\t\tContact Saved Successfully \3\n"<<endl;
           }
           else
           {
              cout<<endl<<"\n\t\t\t\t\tError Opening File"<<endl;
           }
        }
        else
        {
            cout<<endl<<"\n\t\t\t\t\tA Phone Number Must Contain Numbers Only !"<<endl;
        }
    }
    else
    {
        cout<<endl<<"\n\t\t\t\t\tInvalid Phone Number! A Phone Number Must Contain 10 Digits"<<endl;
    }
    phone.close();
}


void SearchContact()
{
    system("cls");
    Front();
    bool Found=false;
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,7);
    ifstream fin("ContactManagementSystem.txt");
    string Fname,Lname;
    cout<<endl<<"\n\t\t\t\t\tEnter First Name For Search :- ";
    cin>>Fname;
    cout<<endl<<"\n\t\t\t\t\tEnter Last Name For Search :- ";
    cin>>Lname;
    while(fin >> FirstName >> LastName >> Phone_number)
    {
        if(Fname == FirstName && Lname == LastName)
        {
            system("cls");
            Front();
            SetConsoleTextAttribute(col,13);
            cout<<endl<<"\n\n\t\t\t\t\tContact Details_____________________\n\n"<<endl;
            cout<<endl<<"\t\t\t\t\tFirst Name :  "<<FirstName<<endl;
            cout<<endl<<"\t\t\t\t\tLast Name :  "<<LastName<<endl;
            cout<<endl<<"\t\t\t\t\tPhone Number :  "<<Phone_number<<endl<<"\n\n\n";
            Found=true;
            break;
        }
    }

    if(Found==false)
    {
        system("cls");
        Front();
        cout<<endl<<"\n\n\t\t\t\t\tNo Search Contact Details Found\n\n"<<endl;
    }
}

void DisplayAllContact()
{
    system("cls");
    Front();
    int k=1;
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
     ifstream fin("ContactManagementSystem.txt");
    SetConsoleTextAttribute(col,13);
    cout<<endl<<"\n\n\t\t\t\t\tAll Contact Details Are_____________________\n"<<endl;
    while(fin >> FirstName >> LastName >> Phone_number)
    {
        cout<<endl<<"\t\t\t\t\t"<<k++<<". Contact Details : "<<endl;
        cout<<endl<<"\t\t\t\t\tFirst Name :  "<<FirstName<<endl;
        cout<<endl<<"\t\t\t\t\tLast Name :  "<<LastName<<endl;
        cout<<endl<<"\t\t\t\t\tPhone Number :  "<<Phone_number<<endl<<"\n\n\n";
    }
 
}


void CountTotalContact()
{
    system("cls");
    Front();
    int k=0;
    ifstream fin("ContactManagementSystem.txt");
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,9);
    while(fin >> FirstName >> LastName >> Phone_number)
    {
        k++;
    }
    cout<<endl<<"\n\t\t\t\t\tThe Total Number Of Contacts Is : "<<k<<endl;
}


void DeleteContact()
{
    system("cls");
    Front();
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,3);
    int Ok=0;
    string fname,lname;
    cout<<endl<<"\n\t\t\t\t\tEnter The First Name Of The Contact Which One You Want To Delete :- ";
    cin>>fname;
    cout<<endl<<"\t\t\t\t\tEnter The Last Name Of The Contact Which One You Want To Delete :- ";
    cin>>lname;
     ifstream fin("ContactManagementSystem.txt");
     ofstream fout("temp.txt",ios::app);
    
       while(fin >> FirstName >> LastName >> Phone_number)
       {
          if((FirstName.compare(fname)) == 0 && (LastName.compare(lname)) == 0)
          {
                Ok++;
          }
          else
          {
            if(fout.is_open())
            {
                fout<<FirstName<<endl<<LastName<<endl<<Phone_number<<endl;
            }
            else
            {
                cout<<endl<<"\t\t\t\t\tError File is Not Open\n"<<endl;
            }
          }
       }
            fout.close();
            fin.close();
            remove("ContactManagementSystem.txt");
            rename("temp.txt","ContactManagementSystem.txt");

    if(Ok>0)
    {
        cout<<endl<<"\n\n\t\t\t\t\tContact Delete Successful\n"<<endl;
    }
    else
    {
        cout<<endl<<"\n\n\t\t\t\t\tContact Delete Unsuccessful Some Problem Arise\n"<<endl;
    }
}


void Help()
{
      system("cls");
       HANDLE col;
       col=GetStdHandle(STD_OUTPUT_HANDLE);
      Front();
      SetConsoleTextAttribute(col,13);
      char problem[500];
      fflush(stdin);
      cout<<endl<<"\n\n\t\t\t\t\tEnter Your Problem Here :  ";
      cin.getline(problem,500);
      cout<<endl<<"\n";
      system("cls");
      Front();
      SetConsoleTextAttribute(col,13);
      cout<<endl<<"\t\t\t\t\tYour Given Problem Is Successfully Submited \2 "<<endl;
      cout<<endl<<"\n\t\t\t\t\tFor More Query Contact Us _____________ \4 "<<endl;
      cout<<endl<<"\t\t\t\t\tPH No :- 9749277744"<<endl;
      cout<<endl<<"\t\t\t\t\tEmail :- teamcoder@gmail.com"<<endl;
      cout<<endl<<"\n\n\t\t\t\t\tThank You \5\5\5 \n\n"<<endl;
      cout<<endl;
}


//Main Function

int main()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    while(1)
    {
         Front();
        switch(Menu())
        {
            case 1:
            {
                AddContact();
                break;
            }
            case 2:
            {
                DeleteContact();
                break;
            }
            case 3:
            {
                SearchContact();
                break;
            }
            case 4:
            {
                DisplayAllContact();
                break;
            }
            case 5:
            {
                CountTotalContact();
                break;
            }
            case 6:
            {
                Help();
                break;
            }
            case 7:
            {
                system("cls");
                Front();
                SetConsoleTextAttribute(col,11);
                cout<<endl<<"\n\t\t\t\t\tThank You For Using Our Application"<<endl;
                SetConsoleTextAttribute(col,5);
                cout<<endl<<"\n\t\t\t\t\tExit__________________________________\n"<<endl;
                exit(1);
                break;
            }
            default:
            {
                system("cls");
                Front();
                SetConsoleTextAttribute(col,9);
                cout<<endl<<"\n\t\t\t\t\tWrong Choice ! _____You Entered A Wrong Digit."<<endl;
                SetConsoleTextAttribute(col,5);
                cout<<endl<<"\n\t\t\t\t\tPlease Enter A Right Digit"<<endl;
                cout<<endl;
            }
        }
        SetConsoleTextAttribute(col,15);
        cout<<endl<<"\n\t\t\t\t\tEnter Any Key To Continue_______________ ";
        getch();
        system("cls");
    }
    system("cls");
    SetConsoleTextAttribute(col,12);
    cout<<endl<<"\n\n";
    return 0;
}
