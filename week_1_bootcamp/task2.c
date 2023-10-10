
#include <stdio.h>

int main()
{
    int first;
    printf("Enter first number:\n");
    scanf ("%d" , &first);

    int second;
    printf("Enter second number:\n");
    scanf ("%d" , &second);

    int sum = first + second;
    printf("The sum is = %d\n" , sum);
    return 0;
}