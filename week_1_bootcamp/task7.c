
#include <stdio.h>

int main()
{
    float fahrenheit;
    printf("Enter the temperature in Fahrenheit\n");
    scanf ("%f" , &fahrenheit) ;

    float degree = (fahrenheit - 32) * 5/9 ;
    printf ("The temperature in celsius is= %f\n" , degree);
    return 0;
}