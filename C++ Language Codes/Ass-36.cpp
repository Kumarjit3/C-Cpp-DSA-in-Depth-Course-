#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void q1_1();
void q1_2();
void q1_3();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q7_1();
void q8();
void q9();
void q10();

class complex
{
     private:
	    int real,img;
	 public:
	complex() :real(3),img(3)
	{ }
    ~complex() { }
	void setData(int a,int b) { real=a,img=b; }
	
	void showData() 
	{  if(img<0)   { if(img==-1) cout<<endl<<real<<" - "<<"i"<<endl; 
	                 else cout<<endl<<real<<" - "<<(img*-1)<<"i"<<endl;
				   }
	   else if(img>0) { if(img==1) cout<<endl<<real<<" + "<<"i"<<endl;
		 	            else cout<<endl<<real<<" + "<<img<<"i"<<endl;
					  }
	   else { cout<<endl<<real<<" + "<<img<<endl; }
	}
	
	friend complex operator +(complex,complex);
	friend complex operator -(complex,complex);
	friend complex operator *(complex,complex);
    friend complex operator -(complex);	
};


class timee
{
    private:
       int hh;
       int mm;
       int ss;
    public:
         timee() : hh(7),mm(30),ss(33)
         { }
         ~timee() { }
         void setTime(int a,int b,int c) { hh=a; mm=b; ss=c; }
         void showTime() { cout<<endl<<"HH : "<<hh<<" MM : "<<mm<<" SS : "<<ss<<endl; }  
         friend istream& operator >>(istream&,timee&);
         friend ostream& operator <<(ostream&,timee);
        void operator =(timee); 
};


class array
{
    private:
       int *p;
       int size;
    public:
    array()
    {
        size=3;
        p=(int*)malloc(size*sizeof(int));
    }
    ~array() { }
    void set_array(int);
    void show_array();
    void operator =(array);
    friend array operator +(array,array);       
};


class integer
{
   private:
       int a;
       int b;
   public:
   integer() : a(3),b(3)
   { }
   ~integer() { }
    void set_integer(int x,int y){ a=x,b=y; }
    void show_integer(){ cout<<endl<<"A="<<a<<" B="<<b<<endl; }
    friend integer operator !(integer);  
    friend bool operator ==(integer,integer);
};

class coordinate
{
   private:
      int x,y;
   public:
      coordinate() :x(3),y(6) { }
      ~coordinate() { }
     void set_data(int a,int b) { x=a,y=b; }
     void get_data() { cout<<endl<<"X: "<<x<<" Y: "<<y<<endl; }
     coordinate operator ,(coordinate);
     friend istream& operator >>(istream&,coordinate&);
     friend ostream& operator <<(ostream&,coordinate);
};


class student
{
    private:
       int roll_no;
       char name[30];
       float age;
    public:
       student()
        {
           roll_no=3;
           strcpy(name,"Kumarjit");
           age=20.5;
        } 
        ~student() {}
        void setStudent()
        {
            cout<<endl<<"Enter student roll: ";
            cin>>roll_no;
            cout<<endl<<"Enter student name: ";
            fflush(stdin); fgets(name,30,stdin); name[strlen(name)-1]='\0';
            cout<<endl<<"Enter student age: ";
            cin>>age;
        }
        void showStudent( )
        {
            cout<<endl<<"Student details: "<<endl<<endl;
            cout<<"Roll : "<<roll_no<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"AGE : "<<age<<endl;
        }
           bool operator ==(student);  
};


bool student::operator ==(student s)
{
     if(s.roll_no==roll_no && s.age == age)
     { if(strcmp(s.name,name)==0) {  return true; }
       return true;
     }
     else 
     return false;
}

istream& operator >>(istream& din,coordinate& c)
{
    din>>c.x>>c.y;
    return din;
}

ostream& operator <<(ostream& dout,coordinate c)
{
    dout<<"X: "<<c.x<<" "<<"Y: "<<c.y<<endl;
    return dout;
}

coordinate coordinate::operator ,(coordinate c)
{
    coordinate cc;
    cc.x=c.x;
    cc.y=c.y;
    return cc;
}

bool operator ==(integer it1,integer it2)
{
    if(it1.a==it2.a && it1.b==it2.b) { return true; } 
    else { return false; }
}

integer operator !(integer it)
{
    integer t;
    t.a=!it.a;
    t.b=!it.b;
    return t;
}

complex operator -(complex c)
{
    complex cc;
    cc.real=-(c.real);
    cc.img=-(c.img);
    return cc;
}

array operator +(array a1,array a2)
{
    array a3; int i;
    for(i=0; i<a1.size; i++)
    {
        (*(a3.p+i))=(*(a1.p+i))+(*(a2.p+i));
    }
    return a3;
}

void array::operator =(array a)
{
    array aa; int i,*q;
    size=a.size;
    q=(int *)malloc(size*sizeof(int));
    for(i=0; i<size; i++)
    {
       (*(p+i))=(*(a.p+i));
    }
}


void array::set_array(int n)
{
    size=n;
    p=(int*)malloc(n*sizeof(int));
    int i;
    cout<<endl<<"Enter "<<n<<" array elements: ";
    for(i=0; i<n; i++)
    {
        cin>>(*(p+i));
    }
}


void array::show_array()
{
    int i;
    cout<<endl<<"The "<<size<<" array elements are: ";
    for(i=0; i<size; i++)
    {
        cout<<(*(p+i))<<" ";
    }
}

void timee::operator =(timee t)
{
   hh=t.hh;
   mm=t.mm;
   ss=t.ss;   
}


complex operator +(complex c1,complex c2)
{
	complex c;
    c.real=c1.real+c2.real;
    c.img=c1.img+c2.img;
    return c;
}

complex operator -(complex c1,complex c2)
{
	complex c;
    c.real=c1.real-c2.real;
    c.img=c1.img-c2.img;
    return c;
}

complex operator *(complex c1,complex c2)
{
	complex c;
	c.real=((c1.real*c2.real)-(c1.img*c2.img));
	c.img=((c1.real*c2.img)+(c1.img*c2.real));
	return c;
}

istream& operator >>(istream &din,timee &t)
{
    din>>t.hh>>t.mm>>t.ss;
    return din;
}

ostream& operator <<(ostream &dout, timee t)
{
    dout<<t.hh<<" "<<t.mm<<" "<<t.ss;
    return dout;
}

void q1_1()
{
    complex c1,c2,c3;
    c2.setData(-1,-3);
    c3.setData(2,3);
    c1=c3+c2;
	c1.showData();
	cout<<endl;	
}


void q1_2()
{
    complex c1,c2,c3;
    c2.setData(-1,-3);
    c3.setData(2,3);
    c1=c3-c2;
	c1.showData();
	cout<<endl;	
}


void q1_3()
{
    complex c1,c2,c3;
    c2.setData(1,-3);
    c3.setData(2,3);
    c1=c3*c2;
	c1.showData();
	cout<<endl;	
}


void q2()
{

   timee e1;
   cout<<"Enter an object: ";
   cin>>e1;
   cout<<e1;
   cout<<endl;
}

void q3()
{
    timee tt,t1;
    t1.setTime(2,30,60);
    tt=t1;
    tt.showTime();
    cout<<endl;
}


void q4()
{
     array a1,a2;
     a1.set_array(5);
     a1.show_array();
     a2=a1;
     a2.show_array();
     cout<<endl;
}


void q5()
{
    array a,b,c;
    a.set_array(3);
    b.set_array(3);
    a.show_array();
    b.show_array();
    c=a+b;
    c.show_array();
    cout<<endl;
}


void q6()
{
 
   complex c1,c2;
   c1.setData(2,3);
   c2=-c1;
   c1.showData();
   c2.showData();
   cout<<endl;
}


void q7()
{
    integer a1,a2;
    a1.set_integer(0,0);
    a1.show_integer();
    a2=!a1;
    a1.show_integer();
    a2.show_integer();
    cout<<endl;
}


void q7_1()
{
     integer i1,i2; int i;
     i1.set_integer(3,3);
     i2.set_integer(3,1);
     i=i1==i2;
     i1.show_integer();
     i2.show_integer();
     if(i==1) { cout<<endl<<"Equal"<<endl; }
     else { cout<<endl<<"Not Equal"<<endl; }
     cout<<endl;
}


void q8()
{
    coordinate c1,c2,c3;
    c1.set_data(2,3);
    c2.set_data(4,6);
    c3=(c1,c2);
    cout<<endl<<"C1 data: "<<endl;
    c1.get_data();
    cout<<endl<<"C2 data: "<<endl;
    c2.get_data();
    cout<<endl<<"C3 data: "<<endl;
    c3.get_data();
    cout<<endl;
}


void q9()
{
    coordinate c1,c2,c3;
    cout<<"Enter first objects value: "<<endl;
    cin>>c1;
    cout<<"Enter second objects value: "<<endl;
    cin>>c2;
    cout<<endl<<"C1 data: "<<endl<<c1;
    cout<<endl<<"C1 data: "<<endl<<c2; 
    cout<<endl;
}


void q10()
{
   student s1,s2; int i;
   s1.setStudent();
   s2.setStudent();
   s1.showStudent();
   s2.showStudent();
   i=(s1==s2);
   if(i==1) { cout<<endl<<" Equal "<<endl; }
   else { cout<<endl<<" Not Equal "<<endl; }
   cout<<endl;
}


int main()
{
	//q1_1();
    //q1_2();
    //q1_3();
    //q2();
   // q3();
   //q4();
   //q5();
   //q6();
   //q7();
   //q7_1();
   //q8();
   //q9();
   q10();
	cout<<endl;
	return 0;
}