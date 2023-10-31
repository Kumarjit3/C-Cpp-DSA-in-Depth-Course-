#include<iostream>
#include<string>

using namespace std;
char funch(string n);

int main()
{
    funch("kumar");
    cout<<endl;
    return 0;
}


char funch(string n)
{
    string na;
    strcpy(na,n);
   cout<<endl<<n<<endl;
   return 0;
}
