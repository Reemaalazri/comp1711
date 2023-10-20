#include <stdio.h>

float sphereVolume (float r)
{
    float answer;
    answer = 3.14159265359 * r*r*r * (4/3);
    return answer;
}

float main ()
{
    float r = 6;
    float z = sphereVolume(r);

    printf("The Volume of a sphere with radius %.1f is  %.2f\n" , r ,z);
}