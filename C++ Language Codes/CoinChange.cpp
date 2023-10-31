#include<iostream>
#include<fstream>
using namespace std;

/*class coin
{
     private:
         int *ptr;
         int Coin;
     public:
        void setCoinArray()
        {
            int n,i;
            cout<<"Enter the size of the coin array : ";
            cin>>n;
            cout<<endl<<"Enter "<<n<<" Coins : ";
            for(i=0; i<n; i++)
            cin>>*(ptr+i);
        }
        void setCoin(int coin)
        {
            this->Coin=coin;
        }
        void checkCoin(int i)
        {
            //if(i<)
        }     
};*/

int main()
{
    int ch;
    ofstream fout;
    ifstream fin;
    fout.open("number.txt");
    cout<<endl<<"Enter number : "; cin>>ch;
    fout<<ch;
    fout.close();
    fin.open("number.txt");
    fin>>ch;
    fin.close();
    cout<<endl<<"The number is : ";
    cout<<ch;
    cout<<endl;
    return 0;
}

