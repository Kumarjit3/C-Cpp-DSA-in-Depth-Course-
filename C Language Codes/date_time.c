#include<stdio.h>
#include<time.h>

int main()
{
    time_t t;
    time(&t);
    printf("\nThe current date & time is: ");
    printf("%s\n",ctime(&t));
    return 0;
}