#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
     int id;
     char name[30];
     float salary;
};
struct time
{
    int hour;
    int minitue;
    int second;
};

struct employee take_input();
void display(struct employee);
void array_structure_input();
void highest_sallary();
void array_structure_display(struct employee emp[],int);
void sort_by_salary(struct employee emp[],int);
void sort_by_name(struct employee emp[],int);
void time_period_difference();
int main()
{
    struct employee e1;
    //e1=take_input();
    //display(e1);
    //array_structure_input();
    time_period_difference();
}

struct employee take_input()
{
    struct employee e2;
    printf("Enter the employee id:- ");
    scanf("%d",&e2.id);
    printf("Enter the employee name:- ");
    fflush(stdin);
    fgets(e2.name,30,stdin);
    e2.name[strlen(e2.name)-1]='\0';
    printf("Enter the employee salary:- ");
    scanf("%f",&e2.salary);
    return e2;
}

void display(struct employee e1)
{
   printf("ID = %d\n",e1.id);
   printf("NAME = %s\n",e1.name);
   printf("SALARY = %.2f\n",e1.salary);
}


void array_structure_input()
{
    struct employee emp[10]; int n,i;
    printf("Enter total numbers of employee:- ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter %d employee id ,name and salary:- \n",i);
        scanf("%d",&emp[i].id); 
        fflush(stdin); 
        fgets(emp[i].name,30,stdin); 
        emp[i].name[strlen(emp[i].name)-1]='\0'; 
        scanf("%f",&emp[i].salary);
    }
   //array_structure_display(emp,n);
   //highest_sallary(emp,n);
   //sort_by_salary(emp,n);
   sort_by_name(emp,n);
}

void array_structure_display(struct employee emp[],int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        printf("ID = %d NAME = %s SALARY = %f\n",emp[i].id,emp[i].name,emp[i].salary);
    }
}

void highest_sallary(struct employee emp[],int n)
{
   int i,j,high=emp[1].salary;
   for(i=2; i<=n; i++)
   {
       if(emp[i].salary>high) { high=emp[i].salary;j=i;}
   }
   printf("The highest salary employee details is:- \n");
   printf("%d %s %f",emp[j].id,emp[j].name,emp[j].salary);
}

void sort_by_salary(struct employee emp[],int n)
{
      int i,j; struct employee temp;
      for(i=1; i<n; i++)
      {
        for(j=i+1; j<=n; j++)
        {
            if(emp[i].salary<emp[j].salary)
            {
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
      }
      array_structure_display(emp,n);
}

void sort_by_name(struct employee emp[],int n)
{
      int i,j; struct employee temp;
      for(i=1; i<n; i++)
      {
        for(j=i+1; j<=n; j++)
        {
            if(emp[i].name<emp[j].name)
            {
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
      }
      array_structure_display(emp,n);
}

void time_period_difference()
{
     struct time t1,t2,d1;
     printf("Enter starting hour,minitue and second:- \n");
     scanf("%d %d %d",&t1.hour,&t1.minitue,&t1.second);
     printf("Enter ending hour,minitue and second:- \n");
     scanf("%d %d %d",&t2.hour,&t2.minitue,&t2.second);
     if(t1.hour>t2.hour) { d1.hour=(t1.hour)-(t2.hour); } else { d1.hour=(t2.hour)-(t1.hour); }
     if(t1.minitue>t2.minitue) { d1.minitue=(t1.minitue)-(t2.minitue); } else { d1.minitue=(t2.minitue)-(t1.minitue); }
     if(t1.second>t2.second) { d1.second=(t1.second)-(t2.second); } else { d1.second=(t2.second)-(t1.second); }
     printf("The time difference is:- \n");
     printf("%d %d %d",d1.hour,d1.minitue,d1.second);
}