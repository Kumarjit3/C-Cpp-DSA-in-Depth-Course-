#include<iostream>
using namespace std;

class point //question 7
{
    private:
       int x;
       int y;
    public:
   void setX(int x)
   {
     this->x=x;
   }
   void setY(int y)
   {
    this->y;
   }
   int getX() { return x; }
   int getY() { return y; }
};

class linesegment: public point
{
    private:
      int x1,y1;
      int x2,y2;
     public:
     linesegment(): x1(2),y1(5),x2(3),y2(7) { }
       void setPoints()
       {
         cout<<endl<<"Enter (x1 y1) : ";
         cin>>x1>>y1;
         cout<<endl<<"Enter (x2 y2) : ";
         cin>>x2>>y2;
       }
       void showPoints()
       {
        cout<<endl<<"( "<<x1<<","<<y1<<" )"<<" "<<"( "<<x2<<","<<y2<<" )"<<endl;
       }
      void CompairLine(linesegment l)
      {
        int m1 = ((y2-y1)/(x2-x1));//slope
        int m2 = ((l.y2-l.y1)/(l.x2-l.x1));
        if(m1==m2) cout<<endl<<"Two Line Segments Are PARALLEL"<<endl;
        else if(m1*m2==-1) cout<<endl<<"Two Line Segments Are PERPENDICULAR"<<endl;
        else cout<<endl<<"Two Line Segments Are Not PARALLEL And Not PERPENDICULAR"<<endl;
      }
};

int main()
{
  system("cls");
  linesegment l1,l2;
  l1.setPoints();
  l1.showPoints();
  l2.showPoints();
  l1.CompairLine(l2);
  cout<<endl;
  return 0;
}