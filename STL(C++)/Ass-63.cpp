#include<iostream>
#include<vector>
using namespace std;

void q1()
{
    vector<int>v1={3,6,9,12,15};
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}

void q2()
{
    vector<float>v2={1.3,1.6,1.9,1.12,1.15};
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<v2.at(i)<<" ";
    }
    cout<<endl;
}


void q3()
{
    vector<string>v3={"Kumarjit","Neil","Niloy","Anirban","Nabeel"};
    cout<<endl;
    for(auto X:v3)
    {
       cout<<X<<" ";
    }
    cout<<endl;
}

void q4()
{
    vector<int>v4={11,22,33,44,55};
    cout<<endl;
    vector<int>::iterator it;
    for(it=v4.begin(); it!=v4.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}

vector<int> q5_1(vector<int> v1)
{
    vector<int>::iterator i1;
    vector<int>v2;
    for(i1=v1.begin()+1; i1!=v1.end()-1; i1++)
    {
        if( ((*i1) < *(i1-1)) && ((*i1) < *(i1+1)) )
        {
            v2.push_back(*i1);
        }
    }
    return v2;
}

void q5()
{
    vector<int>v1={20,3,22,30,6,44,9,55};
    vector<int>v2;
    v2=q5_1(v1);
    cout<<endl;
    cout<<"The Smallest Elements Inbetween Two Elements Of The Array Are : "<<endl;
    for(auto X:v2)
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