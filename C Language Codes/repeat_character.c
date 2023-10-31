#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

void input_string(char ssr[][30]);
void output_string(char ssr[][30],int);
void found_repeat(char ssr[][30],int);
int main()
{
    char str[10][30];
    input_string(str);
}



void input_string(char ssr[][30])
{
    int n,i;
    printf("Enter how many string you want to insert:- ");
    scanf("%d",&n);
    printf("\nEnter the %d string:- \n",n);
    for(i=1; i<=n; i++)
    {
        scanf("%s",&ssr[i]);
    }
    output_string(ssr,n);
    found_repeat(ssr,n);
}


void output_string(char ssr[][30],int n)
{
    int i;
    printf("\nThe %d strings are:- \n",n);
    for(i=1; i<=n; i++)
    {
        printf("[%d]- ",i);
        puts(ssr[i]);
    }
}


void found_repeat(char ssr[][30],int n)
{
    int i,j,k,p=1,c=0,m=1,f=0,big,w,nnr[30],o;   
    char str[30],cha[30];

 for(w=1; w<=n; w++)
 {  
    m=w;
    for(i=0; ssr[m][i]!='\0'; i++)
    {
        for(j=1; j<=n; j++)
        {
            for(k=0; ssr[j][k]!='\0'; k++)
            {
                if(ssr[m][i] == ssr[j][k]) { c++; }
            }
        }
              if(c>1) 
              { 
                if(f>0)
                {
                  for(o=0; o<f; o++)
                   {
                    if(str[o]!=ssr[m][i]) {  }
                    else { break; }
                    }
                  if(o==f) { str[f]=ssr[m][i]; nnr[f]=c; f++;}
    }
                if(f==0) { str[f]=ssr[m][i]; nnr[f]=c; f++; } c=0; 
              }
              c=0;
     }
} 
for(i=0; i<f; i++) { printf("%d %c\n",nnr[i],str[i]); }
}