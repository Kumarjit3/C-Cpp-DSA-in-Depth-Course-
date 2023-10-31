#include<iostream>
#include<string.h>

using namespace std;

struct  book
{
     private:
         int book_id;
         char book_name[30];
         float book_price;
     public:
        book input();
        void output(book);
};

book book::input()
{
    book b1;
    cout<<"Enter book id: "; cin>>b1.book_id;
    cout<<endl<<"Enter book name: "; 
    fflush(stdin); fgets(b1.book_name,30,stdin); b1.book_name[strlen(b1.book_name)-1]='\0'; 
    cout<<endl<<"Enter book price: "; cin>>b1.book_price;
    cout<<endl;
    return b1;
}

void book::output(book bo)
{ 
    cout<<"The book id is: "<<bo.book_id<<endl;
    cout<<"The book name is : "<<bo.book_name<<endl;
    cout<<"The book perice is : "<<bo.book_price<<endl;
}

int main()
{
    book bb,bt;
    bt=bb.input();
    bb.output(bt);
    cout<<endl;
    return 0;
}


