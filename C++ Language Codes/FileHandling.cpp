#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void reading()
{
    ifstream fin;
    fin.open("new1.txt",ios::in);
    if(!fin)
    {
        cout<<endl<<"File Not Found";
    }
    else
    {
        char ch=fin.get(); 
         while(!fin.eof()) 
    {
        cout<<ch<<fin.tellg()<<endl;
        ch=fin.get();
    }
}
   fin.close();
}

void writing()
{
    ofstream fout;
    fout.open("new1.txt",ios::out);
    char str[100];
    cout<<"Enter a string : ";
    fflush(stdin);
    fgets(str,100,stdin);
    str[strlen(str)-1]='\0';
    cout<<endl;
    fout<<str;
    fout.close();
}

void append()
{
    ofstream fout;
    fout.open("file1.dat",ios::app|ios::binary);
    char str[100];
    cout<<"Enter a string : ";
    cin.getline(str,100);
    fout<<str;
    fout.close();
}

int main()
{
    //writing();
    reading();
    append();
    reading();
    cout<<endl;
    return 0;
}