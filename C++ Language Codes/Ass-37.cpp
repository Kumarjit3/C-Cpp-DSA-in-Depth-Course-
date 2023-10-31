#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void q1();
void q2();
void q3();
void q4();
void q5();
void q6();
void q7();
void q8();
void q9();
void q10();
void swap(int*,int*);

class person
{
     private:
	   string name;
	   float age;
	 public:
	     person(string name,int age)
		 {
		    this->name=name;
			  this->age=age;	
		 }
		~person(){ }
		void setPerson(string name,int age)
		{
			this->name=name;
			this->age=age;
		}
		void showPerson()
		{
			cout<<"Person Details : "<<endl;
			cout<<name<<endl<<age;
		}
};

class complex
{
    private:
       int a;
       int b;
    public:
       complex()
       {
           a=3;
           b=3;
       }   
       ~complex(){}
       void setData(int a,int b)
       {
         this->a=a;
         this->b=b;
       }
       void showData()
       {
        cout<<endl<<"A : "<<a<<endl<<"B : "<<b<<endl;
       }
};


class timee
{
    private:
       int hh,mm,ss;
    public:
       timee() { hh=3,mm=30,ss=33; }
       ~timee() {}
       void setTime(int hh,int mm,int ss)
       {
         this->hh=hh;
         this->mm=mm;
         this->ss=ss;
       }
       void showTime()
       {
         cout<<endl<<hh<<" : "<<mm<<" : "<<ss<<endl;
       }
       void setHours(int hh) { this->hh=hh; }  
       void setMinutes(int mm) { this->mm=mm; }
       void setSeconds(int ss) { this->ss=ss; }
       int getHours() { return hh; }
       int getMinutes() { return mm; }
       int getSeconds() { return ss; }
       timee* array(int); 
       timee* sort_time(timee[],int);
       void display_array(timee*,int); 
       void input_array(timee*,int);
};


class strin
{
    private:
        char *s;
        int length;
    protected:
char* inputString()
{
    char *p,*q,ch;   int n=1,i;
    
	p=(char *)malloc(n);
	p[0]='\0';
	printf("Enter a string:- ");
    while(1)
    {
      ch=getchar();
      if(ch=='\n')
      break;
      q=(char *)malloc(n+1);
      for(i=0; i<n; i++)
      {
      	q[i]=p[i];
      }
      q[i-1]=ch;
      q[i]='\0';
      free(p);
	  n++;
	  p=(char *)malloc(n);	
	  strcpy(p,q);
	  free(q);
    }
    return p;
}    
    public:
    strin() : s(NULL),length(0) { }
    ~strin() { delete []s; length=0; }
    void setString()
    {
      if(s!=NULL)
      {
        delete s;
        length=0;
      }
      s=inputString();
      length=strlen(s);
    }
    void display()
    {
      int i;
      cout<<endl;
      for(i=0; i<length; i++)
      cout<<s[i];
    }
    void stringUpper()
    {
      int i;
      for(i=0; i<length; i++)
      {
        if(s[i]>='a' && s[i]<='z')
          s[i]=-32;
      }
    }
    
    void stringLower()
    {
      int i;
      for(i=0; i<length; i++)
      {
        if(s[i]>='A' && s[i]<='Z')
          s[i]=+32;
      }
    }

    int returnLength() { return length; }
    void printString() { cout<<s; }
    char* getString() { return s; }
};



void timee::input_array(timee *p,int n)
{
  int i,h,m,s;
     for(i=0; i<n; i++) 
     {
      cout<<"Enter time-"<<i<<" [hh mm ss] : ";
      cin>>h>>m>>s;
      (p+i)->setTime(h,m,s);
     }
}


void timee::display_array(timee *p,int n)
{
  int i;
     for(i=0; i<n; i++) 
     {
      (p+i)->showTime();
     }
}

timee* timee::sort_time(timee p[],int n)
{
    int i,j; 
    input_array(p,n);
    cout<<endl<<"Before sorting the times are : "<<endl;
    display_array(p,n);
    for(i=0; i<n-1; i++)
    {
      for(j=i+1; j<n; j++)
      {
           if((p+i)->hh > (p+j)->hh)
           {
             swap(&(p+i)->hh,&(p+j)->hh);
             swap(&(p+i)->mm,&(p+j)->mm);
             swap(&(p+i)->ss,&(p+j)->ss);
           }
           if((p+i)->hh == (p+j)->hh)
           {
             if((p+i)->mm > (p+j)->mm)
             {
              swap(&(p+i)->hh,&(p+j)->hh);
               swap(&(p+i)->mm,&(p+j)->mm);
               swap(&(p+i)->ss,&(p+j)->ss);
             }
             if((p+i)->mm == (p+j)->mm)
             {
                if((p+i)->ss > (p+j)->ss)
                {
                  swap(&(p+i)->hh,&(p+j)->hh);
                  swap(&(p+i)->mm,&(p+j)->mm);
                  swap(&(p+i)->ss,&(p+j)->ss);
                }
             }
           }
      }
    }
    return p;
}


void swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}

timee* timee::array(int n)
{
    return new timee[n];
}

void complex_assign()
{
    complex *p=new complex;
    p->setData(10,20);
    p->showData();
    cout<<endl;
}


void q1()
{
  person p1("kumarjit",20);
	p1.setPerson("kumar",30);
	p1.showPerson();
	cout<<endl;
}

void q2()
{
  complex c;
  c.setData(2,3);
  c.showData();
  cout<<endl;
}

void q3()
{
    complex c1;
    c1.showData();
    complex_assign();
    cout<<endl;
}


void q4()
{
   timee d1,d2;
   d1.showTime();
   d1.setHours(11);
   d1.showTime();
   cout<<endl;
}

void q5()
{
  timee d,*p;  int i;
  p=d.array(5);
  cout<<endl;
}

void q6()
{
  timee dd,*ptr,*p; int i,n;
  cout<<endl<<"Enter the number of time : "; cin>>n;
  p=dd.array(n);
  ptr=dd.sort_time(p,n);
  cout<<endl<<"After sorting the times are : "<<endl;
  dd.display_array(ptr,n);
  cout<<endl;
}


void q7()
{
  timee t1,*t; int n;
  cout<<"Enter array size : "; cin>>n;
  t=t1.array(n);
  t1.input_array(t,n);
   t1.display_array(t,n);
   cout<<endl;
}


void q8()
{
    strin s1;  char *ptr;
   s1.setString();
   s1.stringUpper();
   s1.getString();
   s1.printString();
   s1.display();
   cout<<endl;
}

void q9()
{

}

void q10()
{

}

int main()
{
    //q1();
    //q2();
    //q3();
    //q4();
    //q5();
    //q6();
    //q7();
    q8();
    //q9();
    //q10();
    cout<<endl;
	return 0;
}