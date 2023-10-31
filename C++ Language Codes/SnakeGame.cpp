#include<iostream>
#include<fstream>
using namespace std;
int menu();
void frame();
class matrix
{
      private:
        char m[50][50]={};
        int row,column;
        int pr,pc; //for pont
        int mr,mc; //for movement
        int score;
        int khana;
        int bigKhana;
      protected:
      void setPoint();
      void setMovement(int,int);
      int check();
      void storeScore();
      public:
      matrix() : row(25),column(25),pr(15),pc(17),mr(12),mc(12),score(0),khana(1),bigKhana(0) {}
      void AccessMatrix(char);
      void setMatrix(int,int);
      void showMatrix();
      void movement();
};

void matrix::AccessMatrix(char mm)
{
        int i,j;
        for(i=0; i<row; i++)
        {
            for(j=0; j<column; j++)
            {
                if(i==pr && j==pc)
                {
                    if(bigKhana==3)
                    {
                      m[i][j]=2;  //not done properly
                    }
                    else
                    {
                     m[i][j]=4;  
                    }
                }
                else if(i==mr && j==mc)
                {
                   m[i][j]=mm;
                }
                else
                {
                 m[i][j]=' ';
                }
            }
        }
}

void matrix::setPoint()
{
     srand(time(0));
     this->pr=rand()%25;
     this->pc=rand()%25;
}

void matrix::setMovement(int r,int c)
{
     this->mr=r;
     this->mc=c;
} 

void matrix::setMatrix(int row,int column)
{
    this->row=row;
    this->column=column;
}

void matrix::showMatrix()
{
    size_t i,j;
    system("cls");
    frame();
    cout<<"\t\t\t\t\t------------------\n";
    cout<<"\t\t\t\t\t| SCORE --->  "<<score<<" |\n";
    cout<<"\t\t\t\t\t------------------\n";
    cout<<"\t\t\t\t\t------------------------------------------------------------------------------"<<endl;
    for(i=0; i<row; i++)
    {
       cout<<"\t\t\t\t\t|";
    for(j=0; j<column; j++)
    {
       cout<<" "<<m[i][j]<<" ";
    }
       cout<<" |";
       cout<<endl;
    }
        cout<<"\t\t\t\t\t------------------------------------------------------------------------------"<<endl;
}

void matrix::movement()
{
        try
        {
        int m=menu(); 
        if(m==1)  //UP Shift
        {
            if(mr==0) { throw 1; }
            setMovement(mr-1,mc);
            AccessMatrix('=');
            if(check()) 
            { 
                if(bigKhana==3) { score+=bigKhana; bigKhana=0; bigKhana++; setPoint();  AccessMatrix('='); }
                else { score+=khana; bigKhana++; setPoint();  AccessMatrix('='); } 
            }
        }
        if(m==2)  //Down Shift
        {
            if(mr+1==row) { throw 1; }
            setMovement(mr+1,mc);
            AccessMatrix('=');
            if(check()) 
            { 
                if(bigKhana==3) { score+=bigKhana; bigKhana=0; bigKhana++; setPoint();  AccessMatrix('='); }
                else { score+=khana; bigKhana++; setPoint();  AccessMatrix('='); }
            }
        }
        if(m==3)   //Left Shift
        {
            if(mc==0) { throw 1; }
            setMovement(mr,mc-1);
            AccessMatrix('=');
            if(check())
            { 
                if(bigKhana==3) { score+=bigKhana; bigKhana=0; bigKhana++; setPoint();  AccessMatrix('='); }
                else { score+=khana; bigKhana++; setPoint();  AccessMatrix('='); }
            }
        }
        if(m==4)   //Right Shift
        {
            if(mc+1==column) { throw 1; }
            setMovement(mr,mc+1);
            AccessMatrix('=');
            if(check())
            {
                if(bigKhana==3) { score+=bigKhana; bigKhana=0; bigKhana++; setPoint();  AccessMatrix('='); }
                else { score+=khana; bigKhana++; setPoint();  AccessMatrix('='); }
            }
        }
        if(m!=1&&m!=2&&m!=3&&m!=4)
        {
            throw 1;
        }
      }   
       catch(int k)
       {
           system("cls");
           cout<<endl<<"\n\t\n\t\t\t\t\t\t\t\tExit Due To Wrong Press"<<endl;
           storeScore(); 
           exit(0);
        }
}

int matrix::check()
{
    if(pr==mr && pc==mc)
    {
      AccessMatrix('=');
      return 1;
    }
    else
     return 0;
}

void matrix::storeScore()
{
        int s;
        ofstream fout;
        ifstream fin;
        fout.open("SnakeGameScore.binary");
        fin.open("SnakeGameScore.binary");
        s=fin.get();
        if(score>s)
        {
         fout<<score;
         cout<<endl<<"\n\t\t\t\t\t\t\t\tHigh Score Is : ";
         cout<<score<<endl;
        }
        else
        {
            cout<<endl<<"\n\t\t\t\t\t\t\t\tYour Score Is : "<<score<<"\n\n\n\n"<<endl<<endl;
        }
        fout.close();
        fin.close();
}

void frame()
{
        printf("\t:=:=:=:=:=:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:==:=:=:=:=:==:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:\n");
        printf("\t:=:=:=:=:=:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:==:=:=:=:=:==:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:\n");
        printf("\n\t\t\t\t\t\t\t\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4");
        printf("\n\t\t\t\t\t\t\t\t || CATCH THE STAR ||\n");
        printf("\t\t\t\t\t\t\t    || CREATED BY KUMARJIT MONGAL ||\n");
        printf("\t\t\t\t\t\t\t\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4\n");
        printf("\n\t:=:=:=:=:=:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:==:=:=:=:=:==:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:\n");
        printf("\t:=:=:=:=:=:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:==:=:=:=:=:==:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:\n");   
}

int menu()
{
    int k;
    cout<<"\t\t\t\t\tPress 1 for UP shift____________________ "<<endl;
    cout<<"\t\t\t\t\tPress 2 for DOWN shift______________________ "<<endl;
    cout<<"\t\t\t\t\tPress 3 for LEFT shift_________________________ "<<endl;
    cout<<"\t\t\t\t\tPress 4 for RIGHT shift____________________________ "<<endl;
    cout<<"\t\t\t\t\tPress In Between[1/2/3/4] : "; cin>>k;
    return k;
}

int main()
{
    matrix m1;
    m1.AccessMatrix('=');
    m1.showMatrix();
    while(1)
    {    
    m1.setMatrix(25,25);
    m1.movement();
    m1.showMatrix();
    }
    cout<<endl;
    return 0;
}

