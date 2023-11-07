#include<iostream>
#include<vector>
using namespace std;


void q1()
{
    vector<int>v1={10,20,30,40,-50,60,70,80,90};
    vector<int>::iterator i1;
    vector<int>::iterator i2;
    int v=0;
    i2=v1.end();
    cout<<endl;
    for(auto X:v1)
    {
       cout<<X<<" ";
    }
    cout<<endl;
    for(i1=v1.begin(); i1!=v1.end(); i1++)
    {
       if((*i1)<0)
       {
          v1.erase(i1,(i2));
          break;
       }
    }
    cout<<endl;
    for(auto X:v1)
    {
       cout<<X<<" ";
    }
    cout<<endl;
}


void q2()
{
    vector<int>v1={10,20,30};
    cout<<endl;
    for(auto X:v1)
    {
       cout<<X<<" ";
    }
    cout<<endl;
    v1.insert(v1.end()-1,3,25);
    cout<<endl;
    for(auto X:v1)
    {
       cout<<X<<" ";
    }
    cout<<endl;

}


void q3()
{
    vector<int> given_vector ={2,4,10,5,7,6,15,20,3,9};
    vector<vector<int>>v1;
    vector<int> *ptr;
    cout<<endl;
    int s,e,n=0,c=0;
    while(n<given_vector.size()-1)
    {
      s=n;
       while(n<given_vector.size()-1 && given_vector.at(n)<given_vector.at(n+1))
       {
          n++;
       }
       e=++n;
       ptr=new vector<int>();
       ptr->insert(ptr->begin(),given_vector.begin()+s,given_vector.begin()+e);
       v1.insert(v1.begin()+c,*ptr);
       c++;
    }

    for(auto X:v1)
    {
      for(auto Y:X)
      {
           cout<<Y<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
}


bool IsPrime(int p)
{
    int prime=0;
    for(int i=1; i<=p; i++)
    {
        if(p%i==0)
        {
            prime++;
        }
    }
    if(prime==2)
    return true;
    else
    return false;
}

void q4()
{
   vector<int> given_vector ={2,4,10,5,7,6,15,20,3,9};
   vector<int>::iterator temp;
   int n=0;
   cout<<endl;
   for(auto X:given_vector)
    {
       cout<<X<<" ";
    }
    cout<<endl;
   while(n<given_vector.size())
   {
      temp=given_vector.begin()+n;
       if(IsPrime(*temp)==1)
       {
          given_vector.erase(temp);
       }
       else
       {
         n++;
       }
   }
    cout<<endl<<"After Deleting Prime Numbers : \n"<<endl;
   for(auto X:given_vector)
    {
       cout<<X<<" ";
    }
    cout<<endl;
}

void q5()
{
   vector<int> given_vector1 ={2,4,5,7,6,3};
   vector<int> given_vector2 ={10,50,20,60,30};
   vector<int> given_vector3 ={33,11,55,77,22};
   vector<int>v1;
   v1.insert(v1.begin(),given_vector1.begin(),given_vector1.begin()+3);
   v1.insert(v1.begin()+3,given_vector2.end()-2,given_vector2.end());
   v1.insert(v1.begin()+5,given_vector3.begin(),given_vector3.end());
   for(auto X:v1)
    {
       cout<<X<<" ";
    }
    cout<<endl;

}



int main()
{
   //q1();
   //q2();
   //q3();
   //q4();
   //q5();
   cout<<endl;
   return 0;
}