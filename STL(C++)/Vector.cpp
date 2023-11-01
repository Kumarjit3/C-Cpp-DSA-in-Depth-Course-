#include<iostream>
#include<vector>
using namespace std;

int main()
{
    system("cls");

    //Ways of creating vector objects
    vector <int> v0;
    vector <int> v1 = {25,67,31,10,54,32};
    vector <string> v2={"Bhopal","patna","kanpur","Ujjain"};

    //How to access vector elements ?
    //1.By using [] (subscript operator)
    cout<<"\nV1 Vector elements(by using []) : "<<endl;
    for(int i=0; i<v1.size(); i++)
    {
      cout<<v1[i]<<" "; 
    }  
    cout<<endl;

    //2.By using [] (subscript operator)
    cout<<"\nV1 Vector elements(by using at()) : "<<endl;
    for(int i=0; i<v1.size(); i++)
    {
      cout<<v1.at(i)<<" "; 
    } 
    cout<<endl;

    //3.By using implicit iterator
    cout<<"\nV2 Vector elements(by using implicit iterator) : "<<endl;
    for(auto X:v2)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    //4.By using explicit iterator
    vector<string>::iterator it;
    cout<<"\nV2 Vector elements(by using explicit iterator) : "<<endl;
    for(it=v2.begin(); it!=v2.end(); it++)
    {
       cout<<(*it)<<" ";
    }
    cout<<endl;

    //Methods of Vector class

    //1.back()
    cout<<"\nBack function(v2) = "<<v2.back()<<endl;

    //2.front()
    cout<<"\nFront function(v2) = "<<v2.front()<<endl;

    //3.empty()
    cout<<"\nVector v1 is empty = ";
    if(v1.empty()==0){cout<<"No";}else{cout<<"Yes";};
    cout<<endl;

    //4.capacity()
    cout<<"\nThe Capacity of the vector v1 is = "<<v1.capacity()<<endl;

    vector<int> v3 = {10,40,20,50,30};
    cout<<"\nV3 Vector elements(by using at()) : "<<endl;
    for(int i=0; i<v3.size(); i++)
    {
      cout<<v3.at(i)<<" "; 
    } 
    cout<<endl;

    //5.swap()
    v1.swap(v3);
    cout<<"\nAfter swap V1 Vector elements : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;
    cout<<"\nAfter swap V3 Vector elements : "<<endl;
    for(auto X:v3)
    {
        cout<<X<<" ";
    }
    cout<<endl;
    
    //6.clear()
    v1.clear();
    cout<<"\nAfter clear(v1) The size of v1 vector is : "<<v1.size()<<endl;
    cout<<"\nThe Capacity of the vector v1 is = "<<v1.capacity()<<endl;
    cout<<endl;

    //7.
    //ways to insert data in vector 

    //7_1.push_back()
    v1.push_back(60);
    cout<<"\nV1 Vector elements(push_back function insert) : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    //7_2.insert
    v1.insert(v1.begin(),{55,77,29});
    cout<<"\nV1 Vector elements(By using insert()) : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    v1.insert(v1.begin()+1,{30,80,90});
    cout<<"\nV1 Vector elements(By using insert()) : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;
  
    //Another variation of insert()
    v1.insert(v1.begin()+1,4,12);
    cout<<"\nV1 Vector elements(By using insert() Variation) : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    //here checking array capacity double happend or not
    cout<<"\nThe size of v3 vector is : "<<v3.size()<<endl;
    cout<<"\nThe Capacity of the vector v3 is = "<<v3.capacity()<<endl;
    cout<<endl;

    v3.push_back(60);
    cout<<"\nV3 Vector elements : "<<endl;
    for(auto X:v3)
    {
        cout<<X<<" ";
    }
    cout<<"\nThe size of v3 vector is : "<<v3.size();
    cout<<"\nThe Capacity of the vector v3 is = "<<v3.capacity();
    cout<<endl;

    //7_3.emplace_back()
    v1.emplace_back(100);  
    cout<<"\nV1 Vector elements(emplace_back() function insert) : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl; 

    //7_3.emplace()
    v1.emplace(v1.begin()+2,200);
    cout<<"\nV1 Vector elements(emplace() function insert) : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl; 

    //how to update any index value
    *(v1.begin()+2)=150;
    cout<<"\nUpdating V1 Vector index value : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

   //how to shrink the array
   cout<<"\nBefore Shrink The Capacity of the vector v1 is = "<<v1.capacity();
   v1.shrink_to_fit();
   cout<<"\nAfter Shrink The Capacity of the vector v1 is = "<<v1.capacity();
    cout<<endl;

    //inserting v3 vectors elements into v1 vector
    v1.insert(v1.begin(),v3.begin()+1,v3.begin()+4);
    cout<<"\nAfter inserting v3 vectors data, V1 Vector looks like : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    //inserting v3 vectors elements into v1 vector
    v1.insert(v1.end()-1,v3.begin()+4,v3.begin()+6);
    cout<<"7nAfter inserting v3 vectors data, V1 Vector looks like : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    //How to delete elements
    //1.erase()
    v1.erase(v1.begin()+5);
    cout<<"\nAfter deletion V1 Vector looks like : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

   //1.2erase()
    v1.erase(v1.begin()+3,v1.begin()+8);
    cout<<"\nAfter deletion V1 Vector looks like : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    //1.3pop_back(delete last elements)
    v1.pop_back();
    cout<<"\nAfter deletion V1 Vector looks like : "<<endl;
    for(auto X:v1)
    {
        cout<<X<<" ";
    }
    cout<<endl;


   

     //Self practice_____________________________-
    
    /*cout<<"\nThe size of v0 vector is : "<<v0.size();
    cout<<"\nThe Capacity of the vector v0 is = "<<v0.capacity();
    v0.push_back(10);

    cout<<endl<<"V0 Vector elements : "<<endl;
    for(auto X:v0)
    {
        cout<<X<<" ";
    }
    cout<<endl;
    cout<<"\nThe size of v0 vector is : "<<v0.size();
    cout<<"\nThe Capacity of the vector v0 is = "<<v0.capacity();

    cout<<endl<<"V0 Vector elements : "<<endl;
    vector <int>::iterator it;
    it=v0.begin();
    v0.insert(it,20);
    for(auto X:v0)
    {
        cout<<X<<" ";
    }
    cout<<endl;

    v0.insert(v0.begin()+1,4,3);
    cout<<endl<<"V0 Vector elements : "<<endl;
    for(auto X:v0)
    {
        cout<<X<<" ";
    }

    v0.erase(v0.begin()+1,v0.begin()+4);

    cout<<endl<<"V0 Vector elements : "<<endl;
    for(auto X:v0)
    {
        cout<<X<<" ";
    }*/

    cout<<"\n\n\n"<<endl;
    return 0;
}