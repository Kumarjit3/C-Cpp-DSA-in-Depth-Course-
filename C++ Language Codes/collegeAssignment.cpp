//#include<math.h>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
/*
class cylinder //question 1
{

   private:
      float radius;
      float height;
   public:
      void setRadius(float radius) { this->radius=radius; }
      void setHeight(float height) { this->height=height; }
      float getRadius() { return radius; }
      float getHeight() { return height; }
      float areaOfCylinder() { return ((2*3.15*radius*height)+(2*3.15*radius*radius)); }
      float volumeOfCylinder() { return (3.15*radius*radius*height); }
      float areaOfCylinderBase() { return (3.15*radius*radius); }
};

int main()
{
   system("cls");
   cylinder c1;
   c1.setHeight(2);
   c1.setRadius(3);
   cout<<endl<<"Area Of Cylinder Is : "<<c1.areaOfCylinder()<<endl;
   cout<<endl<<"Volume Of Cylinder Is : "<<c1.volumeOfCylinder()<<endl;
   cout<<endl<<"Area Of Cylinder Base Is : "<<c1.areaOfCylinderBase()<<endl;
   cout<<endl;
   return 0;
}

class shape  //question 2
{
    private:
        float base;
        float height;
        float rightSide;
        float leftSide;
        float side;
   public:
          void setBase(float base) { this->base=base; }
          void setHeight(float height) { this->height=height; }
          void setRightSide(float rightSide) { this->rightSide=rightSide; }
          void setLeftSide(float leftSide) { this->leftSide=leftSide; }
          void setSide(float side) { this->side=side; }
          float getBase() { return base; }
          float getHeight() { return height; }
          float getRightSide() { return rightSide; }
          float getLeftSide() { return leftSide; }
          float getSide() { return side; }
};

class square : public shape
{
    public:
     float areaOfSquare() { return (getSide()*getSide()); }
     float perimeterOfSquare() { return (4*getSide()); }
};

class triangle : public shape
{
    public:
     float areaOfTriangle() { return ((getHeight()*getBase())/2); }
     float perimeterOfTriangle() { return (getRightSide()+getLeftSide()+getBase()); }
};

int main()
{
   system("cls");
   square s2;
   s2.setBase(12);
   s2.setHeight(15);
   s2.setLeftSide(4);
   s2.setRightSide(5);
   s2.setSide(7);
   cout<<endl<<"Area Of Square Is : "<<s2.areaOfSquare()<<endl;
   cout<<endl<<"Perimeter Of Square Is : "<<s2.perimeterOfSquare()<<endl;
   triangle t1;
   t1.setBase(12);
   t1.setHeight(15);
   t1.setLeftSide(4);
   t1.setRightSide(5);
   t1.setSide(7);
   cout<<endl<<"Area Of Triangle Is : "<<t1.areaOfTriangle()<<endl;
   cout<<endl<<"Perimeter Of Triangle Is : "<<t1.perimeterOfTriangle()<<endl;
   cout<<endl;
   return 0;
}

class triangles //question 3
{
    private:
        float base;
        float side;
        float height;
    public:
          void setBase(float base) { this->base=base; }
          void setHeight(float height) { this->height=height; }
          void setSide(float side) { this->side=side; }
          float getBase() { return base; }
          float getHeight() { return height; }
          float getSide() { return side; }
};

class isosceles : public triangles
{
    public:
       float areaOfIsoscelesTriangle()
       {
          return ((getBase()*getHeight())/2);
       } 
       float peimeterOfIsoscelesTriangle()
       {
            return ((2*getSide())+getBase());
       }
};


class equilateral : public triangles
{
    public:
       float areaOfEquilateralTriangle()
       {
          return ((sqrt(3)/4)*getSide()*getSide());
       } 
       float peimeterOfEquilateralTriangle()
       {
           return (3*getSide());
       }
};

int main()
{
   system("cls");
   isosceles i1;
   i1.setBase(10);
   i1.setHeight(5);
   i1.setSide(12);
   cout<<endl<<"Area Of Isosceles Triangle Is : "<<i1.areaOfIsoscelesTriangle()<<endl;
   cout<<endl<<"Perimeter Of Isosceles Triangle Is : "<<i1.peimeterOfIsoscelesTriangle()<<endl;
   equilateral e1;
   e1.setBase(10);
   e1.setHeight(5);
   e1.setSide(12);
   cout<<endl<<"Area Of Equilateral Triangle Is : "<<e1.areaOfEquilateralTriangle()<<endl;
   cout<<endl<<"Perimeter Of Equilateral Triangle Is : "<<e1.peimeterOfEquilateralTriangle()<<endl;
   cout<<endl;
   return 0;
}


class complex //question 5
{
   private:
      int real;
      int img;
   public:
      complex() { real=3; img=5; } 
      void setReal(int real) { this->real=real; }
      void setImg(int img) { this->img=img; }
      int getReal() { return real; }
      int getImg() { return img; }
      void showData()
      {
         cout<<real<<" + "<<img<<"i";
         cout<<endl; 
      }
      complex Add(complex a)
      {
         complex v;
         v.real=a.real+real;
         v.img=a.img+img;
         return v;
      }
      complex Sub(complex a)
      {
         complex v;
         v.real=a.real-real;
         v.img=a.img-img;
         return v;
      }
      complex Mul(complex a)
      {
         complex v;
         v.real=(a.real*real)-(a.img*img);
         v.img=(a.real*img)+(a.img*real);
         return v;
      }
      complex Div(complex a)
      {
         complex v;
         v.real=((a.real*real+a.img*img)/(pow(real,2)+pow(img,2)));
         v.img=((a.img*real-a.real*img)/(pow(real,2)+pow(img,2)));
         return v;
      }
};

int main()
{
     system("cls");
     complex c1,c2,c3;
     c1.setImg(1);
     c1.setReal(2);
     c2.setImg(3);
     c2.setReal(1);
     cout<<endl<<"The Sum Of C1&C2 Is : "<<endl;
     c3=c1.Add(c2);
     c3.showData();
     c1.setImg(4);
     c1.setReal(3);
     c2.setImg(8);
     c2.setReal(9);
     cout<<endl<<"The Subtraction Of C1&C2 Is : "<<endl;
     c3=c1.Sub(c2);
     c3.showData();
     c1.setImg(6);
     c1.setReal(7);
     c2.setImg(3);
     c2.setReal(1);
     cout<<endl<<"The Multiplication Of C1&C2 Is : "<<endl;
     c3=c1.Mul(c2);
     c3.showData();
     c1.setImg(1);
     c1.setReal(2);
     c2.setImg(3);
     c2.setReal(4);
     cout<<endl<<"The Division Of C1&C2 Is : "<<endl;
     c3=c1.Div(c2);
     c3.showData();
     cout<<endl;
     return 0;
}


class timee //question 6
{
    private:
       int hh;
       int mm;
       int ss;
    public:
       timee() : hh(7),mm(12),ss(33) { }
       void setTime(int hh,int mm,int ss)
       {
          this->hh=hh;
          this->mm=mm;
          this->ss=ss;
       }
      void showTime()
      {
         cout<<endl<<" ----->  HH : "<<hh<<endl;
         cout<<endl<<" ----->  MM : "<<mm<<endl;
         cout<<endl<<" ----->  SS : "<<ss<<endl;
      }
      timee add(timee t)
      {
         timee tt,cc;
         tt.hh=hh+t.hh;
         tt.mm=mm+t.mm;
         tt.ss=ss+t.ss;
         cc=calculate(tt);
         return cc;
      }
      timee calculate(timee tt)
      {
         if(tt.ss>60)
         {
            tt.ss=(tt.ss-60);
            tt.mm=(tt.mm+1);
            if(tt.mm>60)
            {
               tt.mm=(tt.mm-60);
               tt.hh=tt.hh+1;
            }
         }
         if(tt.mm>60)
         {
            tt.mm=(tt.mm-60);
            tt.hh=(tt.hh+1);
         }
         return tt;
      }
};

int main()
{
   system("cls");
   timee t1,t2,t3;
   t1.setTime(3,13,30);
   cout<<endl<<"The Time t1 : "<<endl;
   t1.showTime();
   cout<<endl<<"The Time t2 : "<<endl;
   t2.showTime();
   cout<<endl<<"The Addition of t1 & t2 : "<<endl;
   t3=t2.add(t1);
   t3.showTime();
   cout<<endl;
   return 0;
}

class copyc
{
     private:
       int x,y;
     public:
           copyc() { x=3,y=3; }
           copyc(int x,int y) 
            {
               this->x=x;
               this->y=y;
            }
           copyc(copyc &c)
           {
             this->x=c.x;
             this->y=c.y;
           }
           void operator =(copyc &c)
           {
              x=c.x;
              y=c.y;  
           }
           void set(int x,int y)
           {
             this->x=x;
             this->y=y;
           }
           void show()
           {
              cout<<endl<<" X : "<<x;
              cout<<endl<<" Y : "<<y;
           }
};

int main()
{
    system("cls");
    copyc c1;
    c1.set(12,11);
    cout<<endl<<"C1 Object Details Are : "<<endl;
    c1.show();
    copyc c2=c1;
    cout<<endl<<"C2 Object Details Are : "<<endl;
    c2.show();
    cout<<endl;
    return 0;
}

inline void count_V_C_I(string str) //question 4
{
   int i,v=0,c=0,n=0;
   for(i=0; str[i]!='\0'; i++)
   {
      if(str[i]=='a'|| str[i]=='A') v++; else if(str[i]=='e'|| str[i]=='E') v++;
      else if(str[i]=='i' || str[i]=='I') v++; else if(str[i]=='o' || str[i]=='O') v++;
      else if(str[i]=='u'|| str[i]=='U' ) v++; else if(str[i]>='0' && str[i]<='9') { n++; }
      else if(((str[i]>='a' || str[i]>='A') && (str[i]<='z' || str[i]>='Z'))) { c++;  }     
   }
       cout<<endl<<"There are total "<<v<<" vowels in this string"<<endl;
       cout<<endl<<"There are total "<<c<<" consonants in this string"<<endl;
       cout<<endl<<"There are total "<<n<<" integers in this string"<<endl;
}

int main()
{
   system("cls");
   string str;
   cout<<endl<<"Enter a string : ";
   fflush(stdin);
   getline(cin,str);
   count_V_C_I(str);
   cout<<endl;
   return 0;
} */
