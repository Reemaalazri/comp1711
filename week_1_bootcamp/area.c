
#include <stdio.h>

int main()
{
    int length;
    printf("Enter the length\n");
    scanf ("%d" , &length) ;

    int width;
    printf("Enter the width\n");
    scanf ("%d" , &width) ;

    int area = length * width;
    printf ("The input is= %d\n" , area);
    return 0;
}