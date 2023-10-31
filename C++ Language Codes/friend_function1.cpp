#include<iostream>

using namespace std;

void add();
void sub();
void mul();

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
};


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


void add()
{
    complex c1,c2,c3;
    c2.setData(-1,-3);
    c3.setData(2,3);
    c1=c3+c2;
	c1.showData();
	cout<<endl;	
}


void sub()
{
    complex c1,c2,c3;
    c2.setData(-1,-3);
    c3.setData(2,3);
    c1=c3-c2;
	c1.showData();
	cout<<endl;	
}

void mul()
{
    complex c1,c2,c3;
    c2.setData(2,7);
    c3.setData(3,3);
    c1=c3*c2;
	c1.showData();
	cout<<endl;	
}

int main()
{
	//add();
    //sub();
	mul();
	cout<<endl;
	return 0;
}