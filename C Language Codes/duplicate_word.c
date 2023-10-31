#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
void input_words(char ssr[][20]);
void output_words(char ssr[][20],int);
void dupli_find(char ssr[][20],int);

int main()
{

     char str[10][20];  int n;
     input_words(str);
     return 0;
}


void input_words(char spr[][20])
{
    int i,n;
    printf("Enter how many words you want to store:- ");
    scanf("%d",&n);
    printf("\nEnter the %d words:- \n",n);
    for(i=1; i<=n; i++)
    {
        scanf("%s",&spr[i]);
    }
     output_words(spr,n);
}


void output_words(char spr[][20],int n)
{
    int i;
    printf("The words are:- \n");
    for(i=1; i<=n; i++)
    {
        printf("[%d]-",i);
        puts(spr[i]);
    }
    dupli_find(spr,n);

}




void dupli_find(char ssr[][20],int n)
{
    int i,j,c=0;
    for(i=1; i<n; i++)
    {
       for(j=i+1; j<=n; j++)
       {
        printf("c = %d\n",strcmp(ssr[i],ssr[j]));
            if(strcmp(ssr[i],ssr[j])==0)
            {
                c++;
            } 
       }
   }
    if(c>0) { printf("Yes duplicate words found----"); }
    else { printf("No duplicate words not found----"); }
}