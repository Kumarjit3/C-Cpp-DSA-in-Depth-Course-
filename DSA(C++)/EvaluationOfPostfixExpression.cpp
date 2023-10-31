#include<iostream>
#include<string.h>
using namespace std;

class stack
{
    private:
       int capacity;
       int *arr;
       int top;
    public:
       stack() : capacity(30),top(-1),arr(NULL) { }
       ~stack() { if(arr!=NULL) delete []arr; }
       void createStack()
       {
          arr=new int[capacity];
       }
       void push(char p)
       {
             top++;
             arr[top]=p;
       }
       int pop()
       {
            int s=arr[top];
            top--;
            return s;
       }
       void peek()
       {
          cout<<"TOP --> "<<arr[top]<<endl;
       }
       void show()
       {
         cout<<endl<<"The Result Is :- "<<arr[top]<<endl;
       }
    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
    bool isFull()
    {
        if(top+1==capacity)
        return true;
        else
        return false;
    }

    void check(char p)
    {
       if(p=='+')
        {
          int a=pop();
          int b=pop();
          int c=b+a;
          cout<<endl<<"1."<<a<<"  "<<b<<"  "<<c<<endl; 
          push(c);
        }
        else if(p=='-')
        {
          int a=pop();
          int b=pop();
          int c=b-a;
          cout<<endl<<"2."<<a<<"  "<<b<<"  "<<c<<endl;
          push(c);
        }
        else if(p=='*')
        {
          int a=pop();
          int b=pop();
          int c=b*a;
          cout<<endl<<"3."<<a<<"  "<<b<<"  "<<c<<endl;
          push(c);
        }
        else if(p=='/')
        {
          int a=pop();
          int b=pop();
          int c=b/a;
          cout<<endl<<"4."<<a<<"  "<<b<<"  "<<c<<endl;
          push(c);
        }
    }

    void evaluation(char crr[])
    {
        int l=strlen(crr); int i=0;
      while(i<l)
      {
        if(crr[i]>='0' && crr[i]<='9')
        {
            push(crr[i] - '0');
        }
        else if(crr[i]=='+' || crr[i]=='-' || crr[i]=='*' || crr[i]=='/' || crr[i]=='^')
        {
         check(crr[i]);
        }
         i++;
      }
    }
};


int main()
{
    stack s1;
    char str[]={"(231*+9-)"};
    s1.createStack();
    s1.evaluation(str);
    s1.show();
    cout<<endl;
    return 0;
}
