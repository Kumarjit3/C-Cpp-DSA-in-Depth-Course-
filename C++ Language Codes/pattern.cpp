#include<iostream>
using namespace std;


class pattern
{
    private:
         int n;
    public:
         pattern() : n(0) { }
         void setN(int); 
         void showN(); 
         void p1();
         void p2();   
};

void pattern::setN(int n)
{
    this->n=n;
}

void pattern::showN()
{
    cout<<endl<<"N : "<<n<<endl;
}

void pattern::p1()
{
    for(int i=0; i<n; i++)
    {
        cout<<"\t";
        for(int j=0; j<n; j++)
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
}

void pattern::p2()
{
    int m=n/2;
    int p=m;
    for(int i=0; i<n; i++)
    {
        cout<<"\t";
        for(int j=0; j<n; j++)
        {
            if(j>=m&&j<=p)
            cout<<n<<" ";
            else
            cout<<" ";
        }
        if(i>=n/2+1)
        {
            m=m+1;
            p=p-1;
        }
        else
        {
        m=m-1;
        p=p+1;
        }
        cout<<endl;
    }
}

int main()
{
    system("cls");
    pattern p1;
    p1.setN(5);
    p1.p2();
    cout<<endl;
    return 0;
}