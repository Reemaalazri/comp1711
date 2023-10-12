
#include <stdio.h>

int main(){
    int a, b, temp;
    printf("Enter First variable a=\n");
    scanf("%d", &a);
    printf("Enter Second variable b=\n");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping\na = %d \nb = %d \n", a,b);

    return 0;

}