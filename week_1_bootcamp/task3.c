
#include <stdio.h>

int main()
{
    char name[15];
    printf("Enter your name\n");
    scanf ("%s", &name) ;
    printf ("The input is= %s\n" , &name);
    return 0;

    int age[2];
    printf("Enter your age\n");
    scanf ("%d",&age) ;
    printf ("The input is= %d\n" , &age);
    return 0;

    float weight[3];
    printf("Enter your weight\n");
    scanf ("%f", &weight) ;
    printf ("The input is= %f\n" , &weight);
    return 0;
}