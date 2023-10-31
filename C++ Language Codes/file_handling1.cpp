#include<iostream>
#include<fstream>
using namespace std;

void writing_text();


void writing_text()
{
    char str[50];
   ofstream fout;
   fout.open("file.txt",ios::out);
   cout<<"Enter a string: ";
   fflush(stdin); fgets(str,50,stdin);
   fout<<str;
   fout.close();
}

int main()
{
    writing_text();
    cout<<endl;
    return 0;
}
