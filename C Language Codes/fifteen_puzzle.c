void input(int arr[][3],int);
void output(int arr[][3],int);
void swap(int arr[][3],int,int,int);
void left_1(int arr[][3],int,int,int);
void right_1(int arr[][3],int,int,int);
void up_1(int arr[][3],int,int,int);
void down_1(int arr[][3],int,int,int);
void check_win(int arr[][3],int);
#include<stdio.h>
#include<stdlib.h>
char name[30];
void input(int arr[][3],int n)
{
          arr[0][0]=3,arr[0][1]=5,arr[0][2]=2,arr[1][0]=4;
          arr[1][1]=0,arr[1][2]=1,arr[2][0]=7,arr[2][1]=6;
          arr[2][2]=8;
}

void output(int arr[][3],int n)
{
    int i,j,p;
    printf("\n");
    for(i=0; i<n; i++)
    {
         printf("--------------\n");
        printf("| %d | %d | %d |\n",arr[i][0],arr[i][1],arr[i][2]);
    }
    
         printf("--------------\n");

         check_win(arr,3);
}

void swap(int arr[][3],int p,int s,int l)
{
   int k;
   if(s==0 && l==0) { printf("\npress 1 for LEFT SHIFT\npress 3 for UP SHIFT\n"); }
   if(s==0 && l==1) { printf("\npress 1 for LEFT SHIFT\npress 2 for RIGHT SHIFT\npress 3 for UP SHIFT\n"); }
   if(s==0 && l==2) { printf("\npress 2 for RIGHT SHIFT\npress 3 for UP SHIFT\n"); }
   if(s==1 && l==0) { printf("\npress 1 for LEFT SHIFT\npress 3 for UP SHIFT\npress 4 for DOWN SHIFT\n"); }
   if(s==1 && l==1) { printf("\npress 1 for LEFT SHIFT\npress 2 for RIGHT SHIFT\npress 3 for UP SHIFT\npress 4 for DOWN SHIFT\n"); }
   if(s==1 && l==2) { printf("\npress 2 for RIGHT SHIFT\npress 3 for UP SHIFT\npress 4 for down SHIFT\n"); }
   if(s==2 && l==0) { printf("\npress 1 for LEFT SHIFT\npress 4 for DOWN SHIFT\n"); }
   if(s==2 && l==1) { printf("\npress 1 for LEFT SHIFT\npress 2 for RIGHT SHIFT\npress 4 for DOWN SHIFT\n"); }
   if(s==2 && l==2) { printf("\npress 2 for RIGHT SHIFT\npress 4 for DOWN SHIFT\n"); }

   if(s==0&&l==0) { printf("Chose any one option between [1/3]:- ");  scanf("%d",&k);}
   if(s==0&&l==1) { printf("Chose any one option between [1/2/3]:- ");  scanf("%d",&k);}
   if(s==0&&l==2) { printf("Chose any one option between [2/3]:- ");  scanf("%d",&k);}
   if(s==1&&l==0) { printf("Chose any one option between [1/3/4]:- ");  scanf("%d",&k);}
   if(s==1&&l==1) { printf("Chose any one option between [1/2/3/4]:- "); scanf("%d",&k); }
   if(s==1&&l==2) { printf("Chose any one option between [2/3/4]:- "); scanf("%d",&k); }
   if(s==2&&l==0) { printf("Chose any one option between [1/4]:- ");  scanf("%d",&k);}
   if(s==2&&l==1) { printf("Chose any one option between [1/2/4]:- ");  scanf("%d",&k);}
   if(s==2&&l==2) { printf("Chose any one option between [2/4]:- ");  scanf("%d",&k);}

   if(k==1) { left_1(arr,3,s,l); s=s,l=l+1;  swap(arr,3,s,l); }
   if(k==2) { right_1(arr,3,s,l); s=s,l=l-1; swap(arr,3,s,l); }
   if(k==3) { up_1(arr,3,s,l); s=s+1,l=l;    swap(arr,3,s,l); }
   if(k==4) { down_1(arr,3,s,l); s=s-1,l=l;  swap(arr,3,s,l); }
}

void left_1(int arr[][3],int p,int s,int l)
{
     arr[s][l]=arr[s][l+1];
     arr[s][l+1]=0;
     output(arr,3);
}

void right_1(int arr[][3],int p,int s,int l)
{
     arr[s][l]=arr[s][l-1];
     arr[s][l-1]=0;
     output(arr,3);
}

void up_1(int arr[][3],int p,int s,int l)
{
     arr[s][l]=arr[s+1][l];
     arr[s+1][l]=0;
     output(arr,3);
}

void down_1(int arr[][3],int p,int s,int l)
{
     arr[s][l]=arr[s-1][l];
     arr[s-1][l]=0;
     output(arr,3);
}


void check_win(int arr[][3],int n)
{
   int i,j,k=1,p=0;
     for(i=0; i<n; i++)
     {
       for(j=0; j<n; j++)
       {
         if(arr[i][j]==k++) { p++; } else { break; }
       }
       if(p==8) { printf("\n CONGRATULATION YOU WIN THE GAME----------------"); exit(0); }
     }
}

int main()
{
   printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:==:=:=:=:=:=");
   printf("\n\t\t\t\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4*\4");
   int arr[3][3];
   input(arr,3);
   output(arr,3);
   swap(arr,3,1,1);
  return 0;
}