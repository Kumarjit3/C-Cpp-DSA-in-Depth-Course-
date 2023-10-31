#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<fstream>
#include<time.h>

using namespace std;
int Menu();
void Front();

class Bank
{
    private:
      string FirstName,LastName,PhoneNumber,Address,AcType,AcNo,Pincode,AdharNumber;

    public:
        
        void OpenBankAC();
        void CloseBankAC();
        void UpdateBankAC();
        void BalanceCheck();
        void AllAcHoldarDetails();
        void WithdrawMoney();
        void DepositeMoney();
        bool Check(string);
        void Help();
        void Offers();
};


void Front()
{
      system("cls");
      HANDLE col;
      col=GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(col,6);
      cout<<endl<<"\n\n\t\t\t\t\t\t\t-----------------------------------------\n";
      cout<<"\t\t\t\t\t\t\t\tBANK MANAGEMENT SYSTEM\n";
      cout<<"\t\t\t\t\t\t\t-----------------------------------------\n\n\n"<<endl;
}


int Menu()
{
      HANDLE col;
      col=GetStdHandle(STD_OUTPUT_HANDLE);
      int option;
      SetConsoleTextAttribute(col,3);
      cout<<endl<<"\t\t\t\t\t1. OPEN NEW ACCOUNT\n";
      cout<<endl<<"\t\t\t\t\t2. UPDATE EXISTING ACCOUNT\n";
      cout<<endl<<"\t\t\t\t\t3. CHECK ACCOUNT BALANCE\n";
      cout<<endl<<"\t\t\t\t\t4. VIEW ALL ACCOUNT HOLDER DETAILS\n";
      cout<<endl<<"\t\t\t\t\t5. TOTAL NUMBER OF ACCOUNT HOLDER\n";
      cout<<endl<<"\t\t\t\t\t6. MONEY WITHDRAW\n";
      cout<<endl<<"\t\t\t\t\t7. MONWY DEPOSITE\n";
      cout<<endl<<"\t\t\t\t\t8. BANK SPECIAL OFFERS \n";
      cout<<endl<<"\t\t\t\t\t9. CLOSE AN ACCOUNT\n";
      cout<<endl<<"\t\t\t\t\t10. HELP & SUPPORT\n";
      cout<<endl<<"\t\t\t\t\t11. EXIT\n";
      SetConsoleTextAttribute(col,10);
      cout<<endl<<"\n\t\t\t\t\tENTER YOUR CHOICE IN BETWEEN[1/2/3/4/5/6/7/8/9/10/11] :- ";
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

bool Bank::Check(string ac)
{
    bool see=false;
    ifstream fin("Bank.txt");
    while(fin>>FirstName>>LastName>>PhoneNumber>>Address>>AdharNumber>>Pincode>>AcType>>AcNo)
    {
        if(ac==AcNo)
        {
            see=true;
            return false;
            break;
        }
    }
    if(see==false)
    return true;
    else
    return false;
}

void Bank::OpenBankAC()
{     
      system("cls");
      Front();
      HANDLE col;
      col=GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(col,7);
      ofstream fout("Bank.txt",ios::app);
      int i=1,j=1;
      cout<<endl<<"\t\t\t\t\tEnter Your First Name Here : ";
      cin>>FirstName;
      cout<<endl<<"\t\t\t\t\tEnter Your Last Name Here : ";
      cin>>LastName;
      while(j==1)
      {
        cout<<endl<<"\t\t\t\t\tEnter Your Phone No Here : ";
        cin>>PhoneNumber;
         if(Check_digit(PhoneNumber) == true)
         {
           if(Check_number(PhoneNumber) == true)
           {
              j=0;
              break;
           }
           else
           {
             cout<<endl<<"\n\t\t\t\t\tA Phone Number Must Contain Numbers Only ! Enter Again"<<endl;
             j=1;
           }
         } 
         else
         {
             cout<<endl<<"\n\t\t\t\t\tInvalid Phone Number! A Phone Number Must Contain 10 Digits ! Enter Again"<<endl;  
             j=1;
         }
      }
      cout<<endl<<"\t\t\t\t\tEnter Your Address Here - like[vill,post,dist] : ";
      cin>>Address;
      cout<<endl<<"\t\t\t\t\tEnter Your Adhar No Here : ";
      cin>>AdharNumber;
      cout<<endl<<"\t\t\t\t\tEnter Your Pin Code Here : ";
      cin>>Pincode;
      cout<<endl<<"\t\t\t\t\tEnter Account Type Here - like[Savings/FD/RD] : ";
      cin>>AcType;
      while(i==1)
      {
         srand(time(NULL));
         AcNo=rand()%118764595987;
         if(Check(AcNo)==true)
         {
           if(fout.is_open())
           {
            fout<<FirstName<<endl<<LastName<<endl<<PhoneNumber<<endl<<Address<<endl<<AdharNumber<<endl<<Pincode<<endl<<AcType<<endl<<AcNo<<endl;
            i=0;
            break;
           }
         }
         else
         {
            i=1;
         }
      }
        SetConsoleTextAttribute(col,3);
        system("cls");
        Front();
      if(i==0)
      {
        cout<<endl<<"\t\t\t\t\tYour Account Is Sucessfully Opend \4\n"<<endl;
        cout<<endl<<"\t\t\t\t\tYour Account Number Is : "<<AcNo<<endl<<"\n\n";
      }
}


int main()
{
    HANDLE col;
    col=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,13);
    system("cls");
    Bank b1;
    while(1)
    {
        Front();
        switch(Menu())
        {
            case 1:
            {

                b1.OpenBankAC();
                break;
            }
        }
        cout<<endl<<"Enter Any Key To Continue : ";
        getch();
        system("cls");
    }
    return 0;
    cout<<endl;
}