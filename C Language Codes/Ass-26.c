#include<stdio.h>
#include<string.h>

struct marks
{
    int roll;
    char name[30];
    float math,chem,phy;
};


struct marks input()
{
    struct marks m;
    printf("\nEnter roll : "); 
    scanf("%d",&m.roll);
    printf("\nEnter name : "); 
    fflush(stdin); fgets(m.name,30,stdin); m.name[strlen(m.name)-1]='\0';
    printf("\nEnter math marks : ");
    scanf("%f",&m.math);
    printf("\nEnter chemistry marks : ");
    scanf("%f",&m.chem);
    printf("\nEnter physics marks : ");
    scanf("%f",&m.phy);
    return m;
}


struct marks output(struct marks mm)
{
    printf("\nStudent Details : \n");
    printf("\nRoll : %d\n",mm.roll);
    printf("\nName : %s\n",mm.name);
    printf("\nMath Marks : %f\n",mm.math);
    printf("\nChemistry Marks : %f\n",mm.chem);
    printf("\nPhysics Marks : %f\n",mm.phy);
}

float percen(struct marks m3)
{
     float m;
     m=((m3.math+m3.chem+m3.phy)/3.0);
     return m;
}

int main()
{
    struct marks m1,m2;  int i;
    for(i=0; i<5; i++)
    {
     m2=input();
     printf("\nPercentage is :%f\n",percen(m2));
    }
     printf("\n");
     return 0;
}
