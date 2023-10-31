#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
    int Roll;
    char Name[30];
    float Avg;
    float Chemistry;
    float Physics;
    float Mathematics;
    float Computer;
    float English;
    float Biology;
    float Bengali;
};

struct student set_student()
{
     struct student s;
     printf("\nEnter Student Name : ");
     fflush(stdin); fgets(s.Name,30,stdin); s.Name[(strlen(s.Name)-1)]='\0';
     printf("\nEnter Student Roll : "); scanf("%d",&s.Roll);
     printf("\nEnter Mathematics Marks : ");  scanf("%f",&s.Mathematics); 
     printf("\nEnter Bengali Marks : ");  scanf("%f",&s.Bengali);
     printf("\nEnter English Marks : ");  scanf("%f",&s.English); 
     printf("\nEnter Computer Marks : ");  scanf("%f",&s.Computer); 
     printf("\nEnter Chemistry Marks : ");  scanf("%f",&s.Chemistry); 
     printf("\nEnter Physics Marks : ");  scanf("%f",&s.Physics);
     printf("\n");
     return s;  
}


void show_student(struct student sh)
{
    printf("\nStudent details : \n");
    printf("\nName : "); puts(sh.Name);
    printf("\nRoll : %d\n",sh.Roll);  
    printf("\nSubjects Marks : \n");
    printf("\nMathematics Marks :  %f\n",sh.Mathematics); 
    printf("\nBengali Marks :  %f\n",sh.Bengali);
    printf("\nEnglish Marks :  %f\n",sh.English);  
    printf("\nComputer Marks :  %f\n",sh.Computer);  
    printf("\nEnter Chemistry Marks :  %f\n",sh.Chemistry);   
    printf("\nPhysics Marks :  %f\n",sh.Physics); 
    printf("\n");
}

void average(struct student sa)
{
    float avg;
    avg=(sa.Bengali+sa.Biology+sa.Chemistry+sa.Computer+
    sa.English+sa.Mathematics+sa.Physics);
    avg=(avg/7);
    printf("\nThe student total Average is :  %f\n",avg);
    printf("\n");
}

struct student* array(int n)
{
    struct student *arr; int i;
    arr=(struct student *)calloc(n,sizeof(struct student));
    for(i=0; i<n; i++)
    {
      printf("\nEnter %d No students information : \n",i+1);
      (*(arr+i))=set_student();
    }
    printf("\n");
    return arr;
}

int main()
{
    struct student s1,s2,*arr;  int n,i;
    printf("\nEnter how many student information you want to store : "); 
    scanf("%d",&n);
    arr=array(n);
    for(i=0; i<n; i++)
    {
        printf("\n%d No student details : \n",i+1);
        show_student(*(arr+i));
        average(*(arr+i));
    }
    printf("\n");
    return 0;
}
