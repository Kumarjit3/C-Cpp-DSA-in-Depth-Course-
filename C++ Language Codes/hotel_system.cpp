#include<iostream>
#include<string.h>
using namespace std;
char arr[10][50];
int price,total_order=0;
int non_veg(char arr[][50],int,int);
int veg(char arr[][50],int,int);
void all_orders(int);
void total_bill();

int main()
{
    int ch,n,i,p=0,j;
    system("cls");
    cout<<endl<<"\t\tWELOCME TO GRAND HOTEL "<<endl;
    do
    {
    cout<<endl<<"FOR SEE ALL VEG DISHES PRESS 1_____________________";
    cout<<endl<<"FOR SEE ALL NON_VEG DISHES PRESS 2___________________";
    cout<<endl<<"FOR SEE ALL YOUR ORDERS PRESS 3_________________________";
    cout<<endl<<"FOR SEE TOTAL BILL PRESS 4_________________________________";
    cout<<endl<<"FOR EXIT PRESS 5______________________________________________"<<endl;
    cout<<endl<<"PRESS IN BETWEEN [1/2/3/4] : "; cin>>ch;
    switch(ch)
    {
        case 1:
          j=p;
          p=veg(arr,10,j);
          break;
        case 2:
          j=p;
          p=non_veg(arr,10,j);
          break;
        case 3:
         j=p;
         all_orders(j);
         break;
        case 4:
         total_bill();
         break;
        case 5:
        cout<<endl<<"\n\t\tTHANK YOU FOR COMING\n"<<endl;
        cout<<endl;
        exit(0);    
        default:
          cout<<endl<<"Wrong choice!"<<endl;
      }  
  } while(1);
    cout<<endl;
    return 0;
}

void all_orders(int p)
{
  int i;
   cout<<endl<<"YOUR TOTAL "<<total_order<<" ORDER LIST : "<<endl;
    for(i=0; i<p; i++)
    {
        cout<<endl<<arr[i]<<endl;
    }
    cout<<endl;
}

void total_bill()
{
    cout<<endl<<"NOW YOUR TOTAL BILL IS : "<<price<<"'Rs"<<endl; 
    cout<<endl;
}


int veg(char arr[][50],int n,int i)
{
    int k,c,j;
    cout<<endl<<"\t\tALL VEG DISHES LIST"<<endl;
    cout<<endl<<"1. VEG FRIED RICE 300 Gms [PRICE-165'RS] PRESS 1 FOR ODER IT ";
    cout<<endl<<"2. VEG CHHOLE 250 Gms [PRICE-115'RS] PRESS 2 FOR ODER IT ";
    cout<<endl<<"3. VEG POHA 200 Gms [PRICE-80'RS] PRESS 3 FOR ODER IT ";
    cout<<endl<<"4. VEG ROTI 5_Pcs [PRICE-50'RS] PRESS 4 FOR ODER IT "<<endl;
    do 
    { 
         cout<<endl<<"ENTER YOUR CHOICE : ";  cin>>k;
         if(k!=1&&k!=2&&k!=3&&k!=4) { cout<<endl<<"WRONG CHOICE CHOSE AGAIN PRESS IN BETWEEN [1/2/3/4] : "; cin>>k; }
         if(k==1||k==2||k==3||k==4) { cout<<endl<<++total_order<<" ORDER SUCCESSFUL"<<endl; }
         if(k==1) { strcpy(arr[i++],"VEG FRIED RICE 300 Gms [PRICE-165'RS]"); price+=165; };
         if(k==2) { strcpy(arr[i++],"VEG CHHOLE 250 Gms [PRICE-115'RS]"); price+=115; }
         if(k==3) { strcpy(arr[i++],"VEG POHA 200 Gms [PRICE-80'RS]" ); price+=80; }
         if(k==4) { strcpy(arr[i++],"VEG ROTI 5_Pcs [PRICE-50'RS]"); price+=50; }
        cout<<endl<<"PRESS 1 FOR ORDER MORE OR PRESS 0 FOR FINISH ORDER : ";  cin>>k; 
        if(k!=0 && k!=1) { c=3; }
        if(c==3) 
        { 
            cout<<endl<<"YOUR TOTAL "<<total_order<<" ORDER LIST : "<<endl;
             for(j=0; j<i; j++)
               {
                 cout<<endl<<arr[j]<<endl;
               }
            cout<<endl<<"AND YOUR TOTAL BILL IS : "<<price<<"'Rs"<<endl; 
            cout<<endl<<"\t\tTHANK YOU FOR COMING "<<endl;
            cout<<endl;
            exit(0);
        }      
     } while(k!=0 && k==1);
     cout<<endl;
     return i;
}


int non_veg(char arr[][50],int n,int i)
{
    int k,c,j;
    cout<<endl<<"\t\tALL NON_VEG DISHES LIST"<<endl;
    cout<<endl<<"1. TAVA CHICKEN (10 pcs) [PRICE-320'RS] PRESS 1 FOR ODER IT ";
    cout<<endl<<"2. MUTTON MIX MASALA (8 pcs) [PRICE-400'RS] PRESS 2 FOR ODER IT ";
    cout<<endl<<"3. FISH MASALA (4 pcs) [PRICE-250'RS] PRESS 3 FOR ODER IT ";
    cout<<endl<<"4. BUTTER CHICKEN (5 pcs) [PRICE-380'RS] PRESS 4 FOR ODER IT "<<endl;
    do 
    { 
         cout<<endl<<"ENTER YOUR CHOICE : ";  cin>>k;
         if(k!=1&&k!=2&&k!=3&&k!=4) { cout<<endl<<"WRONG CHOICE CHOSE AGAIN PRESS IN BETWEEN [1/2/3/4] : "; cin>>k; }
         if(k==1||k==2||k==3||k==4) { cout<<endl<<++total_order<<" ORDER SUCCESSFUL"<<endl; }
         if(k==1) { strcpy(arr[i++],"TAVA CHICKEN (10 pcs) [PRICE-320'RS]");   price+=320; };
         if(k==2) { strcpy(arr[i++],"MUTTON MIX MASALA (8 pcs) [PRICE-400'RS]"); price+=400; }
         if(k==3) { strcpy(arr[i++],"FISH MASALA (4 pcs) [PRICE-250'RS]" ); price+=250; }
         if(k==4) { strcpy(arr[i++],"BUTTER CHICKEN (5 pcs) [PRICE-380'RS]"); price+=380; }
        cout<<endl<<"PRESS 1 FOR ORDER MORE OR PRESS 0 FOR FINISH ORDER : ";  cin>>k;
         if(k!=0 && k!=1) { c=3; } 
         if(c==3) 
        { 
            cout<<endl<<"YOUR TOTAL "<<total_order<<" ORDER LIST : "<<endl;
             for(j=0; j<i; j++)
               {
                 cout<<endl<<arr[j]<<endl;
               }
            cout<<endl<<"AND YOUR TOTAL BILL IS : "<<price<<"'Rs"<<endl; 
            cout<<endl<<"\t\tTHANK YOU FOR COMING "<<endl;
            cout<<endl;
            exit(0);
        }      
     } while(k!=0 && k==1);
     cout<<endl;
     return i;
}