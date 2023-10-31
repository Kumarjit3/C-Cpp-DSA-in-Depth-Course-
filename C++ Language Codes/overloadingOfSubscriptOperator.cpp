#include<iostream>
#include<stdlib.h>

using namespace std;

class array
{
   private:
      int *p;
	  int size;
   public:
      array(int s) :size(s),p((int*)malloc(s*sizeof(int)))
	  {	}
	  ~array(){ }
	  void setArray(int n)
	  {
	  	int i;
        size=n;
	  	p=(int*)malloc(size*sizeof(int));
        cout<<"Enter "<<n<<" array elements :"<<endl;
	  	for(i=0; i<size; i++)
	  	{
	  		cin>>*(p+i);
		}
		cout<<endl;
	  }
	  void showArray()
	  {
	  	int i;
        cout<<"The "<<size<<" array elements are :"<<endl;
	  	for(i=0; i<size; i++)
	  	{
	  		cout<<(*(p+i))<<" ";
		}
		cout<<endl;
	  }
	  void operator [](int);	  	
};

void array::operator [](int a)
{
    cout<<a<<" no index value is : "<<(*(p+a))<<endl;
}

int main()
{
    array a1(5);  int n;
    a1.setArray(5);
    a1.showArray();
    cout<<"Enter the index no : "; cin>>n;
    a1[n];
    cout<<endl;
    return 0;
}



