#include <stdio.h>

int main() {
    int P, t;
    float R;
    printf("Enter principal P =\n");
    scanf("%d", &P);
    printf("Enter time t =\n");
    scanf("%d", &t);
    printf("Enter rate R =\n");
    scanf("%f", &R);
    
    
    int intrest = P*(1+(R*t));
    printf ("The intrest is = %d\n", intrest);
    return 0;

}