
#include <stdio.h>

int main()
{
    float radius;
    printf("Enter the raduis of the circle\n");
    scanf ("%f" , &radius) ;

    float area = radius * radius * 3.14159265359;
    printf ("The area is= %f\n" , area);
    return 0;
}