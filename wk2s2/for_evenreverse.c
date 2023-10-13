#include <stdio.h>

int main() {
    int a = 20;

    while (a >= 0) {
        printf("a=%d\n", a);
        a-=2;
    }

    //printf("After exiting the loop: a = %d\n" , a);
    return 0;
}