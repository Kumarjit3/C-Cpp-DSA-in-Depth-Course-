#include<iostream>
#include<array>
using namespace std;



    //1. First Question
    
    /*
    int main()
    {
    system("cls");
    array<int,5> a1;
    array<int,5>::iterator it;
    cout<<endl<<"Enter Five Array Elements  :\n";
    for(it=a1.begin(); it!=a1.end(); it++)
    { 
       cin>>(*it);
    }

    cout<<endl;

    cout<<endl<<"The Five Array Elements  :\n";
    for(it=a1.end()-1; it!=a1.begin()-1; it--)
    {
       cout<<(*it)<<" ";
    }
    cout<<endl;
    return 0;
    }*/







  //2. Second Question

   /*int main()
    {
    system("cls");
    array<float,5> f1;
   array<float,5>::iterator it;
   cout<<endl<<"Enter Five Array Elements  :\n";
    for(it=f1.begin(); it!=f1.end(); it++)
    { 
       cin>>(*it);
    }

    cout<<endl;
    float sum=0.0,avg;
    for(auto X:f1)
    {
       sum+= X;
    }
    cout<<endl<<"Sum Of Five Elements Is : "<<sum<<endl;
    avg = sum/5;
    
    cout<<endl<<"The Average Of Five Elements Are : "<<avg<<endl;

    cout<<endl;
    return 0;
    }*/







//3. Third Question

  /*int main()
    {
    system("cls");

    array<int,10> a1;
    array<int,5>::iterator it;
    cout<<endl<<"Enter Ten Array Elements  :\n";
    for(it=a1.begin(); it!=a1.end(); it++)
    { 
       cin>>(*it);
    }

    cout<<endl;

    it=a1.begin();
    int big=(*it);
    for(it=a1.begin()+1; it!=a1.end(); it++)
    {
       if((*it)>big)
       {
         big=(*it);
       }
    }
    cout<<endl;
  
    cout<<endl<<"The Greatest Array Element Is  :"<<big<<endl;
     
     cout<<endl;
     return 0;
    }*/







//4. Fourth Question

/*    class Complex 
    {
        private:
           int real;
           int img;
        public:
           Complex() : real(0),img(0) { }
           int GetReal()
           {
              return real;
           }
            int GetImg()
           {
              return img;
           }
           void SetData(int real,int img)
           {
               this->real = real;
               this->img = img; 
           }
           void ShowData()
           {
              cout<<endl<<"Real : "<<real<<endl<<"Img : "<<img<<endl;
           } 
    };

array<Complex,5> Input()
{
    array<Complex,5> a1;
    array<Complex,5>::iterator it;   
    for(it=a1.begin(); it!=a1.end(); it++)
    {
        int real,img;
        cout<<endl<<"Enter The Real Number : ";
        cin>>real;
        cout<<endl<<"Enter The Imaginary Number : ";
        cin>>img;
        it->SetData(real,img);
    }
    return a1;
}

void Display(array<Complex,5> a1)
{
    array<Complex,5>::iterator it;   
    for(it=a1.begin(); it!=a1.end(); it++)
    {
        it->ShowData();
    }
}

void SumComplex(array<Complex,5> a1)
{
   array<Complex,5>::iterator it; 
   int real=0,img=0;  
    for(it=a1.begin(); it!=a1.end(); it++)
    {
        real+=it->GetReal();
        img+=it->GetImg();
    }
    cout<<endl<<"Sum Of All Complex Numbers Is : "<<endl<<"Real : "<<real<<endl<<"Img : "<<img<<endl;
}

int main()
{
    system("cls");

    array<Complex,5> c1;
    c1=Input();
    Display(c1);
    SumComplex(c1);

    cout<<endl;
    return 0;
} */





//5. Fifth Question

/*int main()
{
    system("cls");
    array<int,10> a1;
    array<int,5>::iterator it;
    cout<<endl<<"Enter Ten Array Elements  :\n";
    for(it=a1.begin(); it!=a1.end(); it++)
    { 
       cin>>(*it);
    }

    cout<<endl;

    cout<<endl<<"The Ten Array Elements Before Sorting :\n";
    for(it=a1.begin(); it!=a1.end(); it++)
    {
       cout<<(*it)<<" ";
    }

    array<int,5>::iterator i1;
    array<int,5>::iterator i2;
    for(i1=a1.begin(); i1!=a1.end(); i1++)
    {
        for(i2=a1.begin(); i2!=a1.end(); i2++)
        {
            if((*i1)<(*i2))
            {
                int temp=(*i1);
                (*i1)=(*i2);
                (*i2)=temp;
            }
        }
    }

    cout<<endl<<"The ten Array Elements After Sorting :\n";
    for(it=a1.begin(); it!=a1.end(); it++)
    {
       cout<<(*it)<<" ";
    }
    cout<<endl;
    return 0;
}*/