#include <stdio.h>

float circleArea (float r)
{
    float answer;
    answer = 3.14159265359 * r * r;
    return answer;
}

float main ()
{
    float r = 6;
    float z = circleArea(r);

    printf("The Area of a circle with radius 2 is  %.2f\n" , z);
}