#include<iostream>
#include<string.h>
using namespace std;


class stack
{
    private:
       int capacity;
       char *ptr;
       int top;
       char *p;
       int i;
    public:
       stack() : capacity(30),ptr(NULL),top(-1),p(NULL),i(0) { }
       ~stack() { if(ptr!=NULL) delete[]ptr; if(p!=NULL) delete []p; }
       void createStack()
       {
          ptr=new char[capacity];
          p=new char[capacity];
       }
       void push(char p)
       {
             top++;
             ptr[top]=p;
       }
       void pop()
       {
            top--;
       }
     
       void peek()
       {
          cout<<"TOP --> "<<ptr[top]<<endl;
       }

       void show()
       {
           if(top==-1)
          { 
             cout<<endl<<"Stack Is Empty";
          }
          else
         {
            cout<<endl;
            int t=top;
            while(t!=-1)
            {
              if(t==top)
                cout<<"TOP --> | "<<ptr[t--]<<" |"<<endl;
              else
                cout<<"        | "<<ptr[t--]<<" |"<<endl;
            }
            cout<<"\t-----"<<endl;
         }
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

   void get(char c)
   {
      p[i]=c;
      i++;
   }

   void showGet()
   {
      cout<<endl<<"THE POSTFIX EXPRESSION IS :-  ";
      for(int j=0; j<i; j++)
      {
         cout<<p[j];
      }
      cout<<endl;
   }

    int priority(char p)
    {
        if(p=='(')
        return 1;
        else if(p==')')
        return 1;
        else if(p=='+')
        return 2;
        else if(p=='-')
        return 2;
        else if(p=='*')
        return 3;
        else if(p=='/')
        return 3;
        else if(p=='^')
        return 4;
        else
        return 0;
    }

    void check(char p)
    {
        if(p=='(')
        {
           if(top==-1)
           push(p);
           else if(priority(ptr[top])>=priority(p))
            push(p);
        }
        else if(ptr[top]=='(' && p==')')
        {
            pop();
        }
        else if((priority(p)) > (priority(ptr[top])))
        {
            push(p);
        }
        else
        {
            if(!(ptr[top]=='(' || ptr[top]==')'))
            {
             get(ptr[top]);
            }
            pop();
            if((priority(p)) <= (priority(ptr[top])))
            {
               check(p);
            }
            if((priority(p)) > (priority(ptr[top])))
            {
               push(p);
            }
        }
    }

  void inToFix(char crr[])
  {
     int l=strlen(crr); int i=0;
     while(i<l)
     {
       if(crr[i]>=65 && crr[i]<=90 || crr[i]>=97 && crr[i]<= 122)
       {
         get(crr[i]);
       }
       else
       {
         check(crr[i]);
       }
        i++;
     }
  }
};


int main()
{
    char infix[]={"(K+L-M*N+(O^P)*W/U/V*T+Q)"};
    stack s1;
    s1.createStack();
    s1.inToFix(infix);
    s1.showGet();
    cout<<endl;
    return 0;
}

