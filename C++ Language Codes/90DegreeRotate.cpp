#include<iostream>
using namespace std;

int main()
{
    system("cls");
    int str[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr[3][3],m=0,n=2;
    cout<<endl<<"Before Rotation The Array Looks Like : "<<endl;
    cout<<endl;
    for(int i=0; i<3; i++)
    {
       for(int j=0; j<3; j++)
       {
          cout<<str[i][j]<<" ";
       }
        cout<<endl;
    }
      for(int i=0; i<3; i++)
    {
       for(int j=0; j<3; j++)
       {
          arr[m++][n]=str[i][j];
       }
        m=0;
        n--;
        cout<<endl;
    }

    for(int i=0; i<3; i++)
    {
       for(int j=0; j<3; j++)
       {
          cout<<arr[i][j]<<" ";
       }
        cout<<endl;
    }
  
    cout<<endl;
    return 0;
}


