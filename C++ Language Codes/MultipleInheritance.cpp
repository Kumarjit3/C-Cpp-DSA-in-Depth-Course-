#include<iostream>
using namespace std;

class rectangle
{
     private:
        float width;
        float length;
    public:
       rectangle() :width(10),length(20) { }
       virtual void draw()
       {
           cout<<endl;
           cout<<"\t\t1.THE RECTANGLE IS :- ";
           cout<<"\n\t\t\t ___________________________";
           cout<<"\n\t\t\t|                           |";
           cout<<"\n\t\t\t|                           |";
           cout<<"\n\t\t\t|                           |";
           cout<<"\n\t\t\t|                           |";
           cout<<"\n\t\t\t|___________________________|";
           cout<<endl<<"\n\n\t\t\tRECTANGLE IS SUCCESSFULLY DRAWN"<<endl;
       }

};

class square
{
        private:
            float side;
        public:
        square() : side(10) {}
         virtual void draw()
          {
           cout<<endl;
           cout<<"\t\t2.THE SQUARE IS :- "<<endl;
           cout<<"\n\t\t\t ______________";
           cout<<"\n\t\t\t|              |";
           cout<<"\n\t\t\t|              |";
           cout<<"\n\t\t\t|              |";
           cout<<"\n\t\t\t|              |";
           cout<<"\n\t\t\t|______________|";
           cout<<endl<<"\n\n\t\t\tSQUARE IS SUCCESSFULLY DRAWN"<<endl;
          }    
};

class circle
{
      private:
         float radius;
      public:
       circle() : radius(5.5) { }
       virtual void draw()
       {
           cout<<endl;
           cout<<"\t\t3.THE CIRCLE IS :- "<<endl;
           cout<<"\n\t\t\t  #  #  #";
           cout<<"\n\t\t\t#         #";
           cout<<"\n\t\t\t#         #";
           cout<<"\n\t\t\t#         #";
           cout<<"\n\t\t\t  #  #  #";
           cout<<endl<<"\n\t\tTHE CIRCLE IS SUCCESSFULLY CREATED"<<endl;
       }   
};

class connect:public rectangle,public square,public circle
{  
    public:
      virtual void draw()
      {
        draw();
      }
};


int main()
{
    system("cls");
    connect c1;
    rectangle r1; 
    square s1; 
    circle cc1;
    c1.draw();
    cout<<endl;
    return 0;
}