#include<iostream>
#include<time.h>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"StringVowelConsonant.cpp"

using namespace std;

bool first_stage();
bool second_stage();

int main()
{
      int s;
      s=first_stage();
      cout<<endl;
      if(s==1)
      {
         cout<<endl<<"\n\t\t\t\t\tEnter any key to continue the Game__________  "; 
         getch();
         s=second_stage();
      }
      else
      {
         cout<<endl<<"Exit______________"<<endl;
      }
      return 0;
}


bool first_stage()
{
 time_t start,finish; int n,m,i,k,t,c=0,w=0,q=1;
   while(q<=15)
    {
      time(&start);
      srand(time(0));
      n=rand()%100;
      m=rand()%100;
      system("cls");
      cout<<"\t\t\t\t\t\t\t\t\t\t\5 TEST YOUR SPEED \5"<<endl;
      cout<<endl<<endl;
      cout<<endl<<"\t\t\t\t\t\t\t\t\t\t     STAGE - 1"<<endl;
      cout<<endl<<"\t\t\t\t\t__________SCORE 10 POINTS FROM 15 QUESTION TO REACH THE NEXT STAGE EACH QUESTION HAVE 1 POINT___________"<<endl;
      cout<<endl<<"\t\t\t\t\t________________________TO ANSWARE EACH QUESTION YOU WILL GET ONLY 7 SECOND TIME________________________"<<endl;
      cout<<endl<<"\n\n\t\t\t\t\t"<<q<<". ( "<<n<<" + "<<m<<" ) = ? : "; cin>>k;
      time(&finish); 
      t=difftime(finish,start);
      if(k==(n+m) && t<=7)
      {
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;
         cout<<endl<<"\t\t\t\t\tCORRECT ANSWARE IN TIME"<<endl; c++;
      }
      if(k==(n+m) && t>7)
      {
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;
         cout<<endl<<"\t\t\t\t\tCORRECT ANSWARE BUT OUT OF TIME"<<endl; w++;
      }
      if(k!=(n+m) && t<=7)
      { 
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;   
         cout<<endl<<"\t\t\t\t\tWRONG ANSWARE BUT IN TIME"<<endl; w++;
      }
      if(k!=(n+m) && t>7)
      { 
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;   
         cout<<endl<<"\t\t\t\t\tWRONG ANSWARE AND OUT OF TIME"<<endl; w++;
      }
         cout<<endl<<"\t\t\t\t\tCORRECT : "<<c<<" WRONG : "<<w<<endl; q++; if(c==10){ break; }
         cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE_______"<<endl; getch();
   }
      system("cls");  cout<<endl;
     if(c>=10) 
     { cout<<endl<<"\t\t\t\t\t\tCONGRATULATION YOU WIN THE FIRST STAGE AND________GOD LUCK FOR THE NEXT STAGE"<<endl; 
       return true; }
     else { cout<<endl<<"\t\t\t\t\t\t\tSORRY! YOU LOSE THE FIRST STAGE AND ALSO THE GAME"<<endl; return false; }
}

bool second_stage()
{
   int c,v,s=0,w=0,p,l,t,q=1,j=1; time_t start,finish;
   p=25*2; char n[15];
   while(q<=5)
   {
   p=25*2; char n[15];
   srand(time(0)); 
   time(&start);
   for(int i=0; i<15; i++) { n[i] = 'A' + rand()%25; }
   l=strlen(n); 
   system("cls");  cout<<" L : "<<l;
   cout<<"\t\t\t\t\t\t\t\t\t\t\5 TEST YOUR SPEED \5"<<endl;
   cout<<endl<<endl;
   cout<<endl<<"\t\t\t\t\t\t\t\t\t\t WELLCOME IN STAGE - 2"<<endl;
   cout<<endl<<"\t\t\t\t\t__________SCORE 3 POINTS FROM 5 QUESTION TO REACH THE NEXT STAGE EACH QUESTION HAVE 1 POINT___________"<<endl;
   cout<<endl<<"\t\t\t\t\t________________________TO ANSWARE EACH QUESTION YOU WILL GET ONLY 15 SECOND TIME________________________"<<endl;
   if(j==1)
   {
      cout<<endl<<"\t\t\t\t\t"<<q<<". COUNT NUMBER OF VOWELS FROM THIS WORD : "<<n<<" :  "; cin>>v; time(&finish);
      t=difftime(finish,start);  c=CountVowels(n,15); j=0;
   }
   else
   {
      cout<<endl<<"\t\t\t\t\t"<<q<<". COUNT NUMBER OF CONCONANTS FROM THIS WORD : "<<n<<" :  "; cin>>v; time(&finish);
      t=difftime(finish,start);  c=CountConsonants(n,15); j=1;
   }
   if(c==v && t<=15) 
    { 
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;
         cout<<endl<<"\t\t\t\t\tCORRECT ANSWARE IN TIME"<<endl; s++; 
    }
    if(c==v && t>15)
    {
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;
         cout<<endl<<"\t\t\t\t\tCORRECT ANSWARE BUT OUT OF TIME"<<endl; w++;
    }
    if(c!=v && t<=15)  
    {
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;   
         cout<<endl<<"\t\t\t\t\tWRONG ANSWARE IN TIME"<<endl; w++;
    }
    if(c!=v && t>15)
    {
         cout<<endl<<"\t\t\t\t\tYOUR TIME : "<<difftime(finish,start)<<" SEC"<<endl;   
         cout<<endl<<"\t\t\t\t\tWRONG ANSWARE AND OUT OF TIME"<<endl; w++;
    }
         cout<<endl<<"\t\t\t\t\tCORRECT : "<<s<<" WRONG : "<<w<<endl;
         cout<<endl<<"\t\t\t\t\tPRESS ANY KEY TO CONTINUE_______"<<endl; getch(); q++;
    }
        system("cls"); cout<<endl;
    if(s>=3) 
       { cout<<endl<<"\t\t\t\t\t\tCONGRATULATION YOU WIN THE SECOND STAGE AND________GOD LUCK FOR THE NEXT STAGE"<<endl; 
       return true; }
   else { cout<<endl<<"\t\t\t\t\t\t\tSORRY! YOU LOSE THE SECOND STAGE AND ALSO THE GAME"<<endl; return false; }
}