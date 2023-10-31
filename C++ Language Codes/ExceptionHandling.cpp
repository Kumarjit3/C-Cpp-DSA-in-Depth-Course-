#include<iostream>
#include<string.h>
using namespace std;

class VMS
{
   private:
     int age;
     int vote;
     int start;
     char nation[30];
   public:
      VMS()//Non Parameterized Constructor
        {  
         age=0;
         vote=0;
         start=0;
         nation[30]='\0';
        } 
     void f1();   
};

void VMS::f1()
{
 try //Try Block
 {
     cout<<endl<<"\n\t\tVote Management System\n"<<endl;
     cout<<endl<<"\nEnter 1 For Continue : "; cin>>start;
     if(start!=1)
     throw &start;//Throw Address Of Integer Variable
     cout<<endl<<"Enter your age : "; cin>>age;
     if(age<18)
     throw 1;//Throw Integer
     cout<<endl<<"Enter your Nationality : "; cin.ignore();
     cin.getline(nation,30);
     if(strcmp((strupr(nation)),"INDIAN"))
      throw nation;//Throw String
      cout<<endl<<"Vote for your favourite actor : "<<endl;
      cout<<endl<<"1. Naga Chaitaneya";
      cout<<endl<<"2. Allu Arjun";
      cout<<endl<<"3. Thalapati Vijay";
      cout<<endl<<"4. Mahesh Babu";
      cout<<endl<<"5. Ram pothineni";
      cout<<endl<<"6. Irfan Khan";
      cout<<endl<<"\nPress Between[1/2/3/4/5/6]__________ ";
      cin>>vote;
      if(vote<1 || vote>6)
      throw 3.0;//Throw Float
      cout<<endl<<"Thanks for your vote"<<endl;
 }
 catch(int *p)//single Catch
 {
    cout<<endl<<"You Are Unable To Give Your Vote Because You Are Not Typed 1"<<endl;
 }
 catch(int k)//single Catch
 {
    cout<<endl<<"You are not eligible to cast your vote"<<endl;
 }
 catch(char *n)//single Catch
 {
    cout<<endl<<"You have to be indian to cast vote Your age Is less then 18"<<endl;
 }
 catch(float n)//single Catch
 {
    cout<<endl<<"Invalid Vote! Out Of Range 1 to 6"<<endl;
 }
 catch(...)//Multiple Catch
 {
    cout<<endl<<"Inavlid vote"<<endl;
 }

}

int main()
{
    VMS v1;
    system("cls");
    v1.f1();
    cout<<endl;
    return 0;
}
