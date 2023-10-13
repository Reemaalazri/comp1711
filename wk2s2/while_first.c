#include <stdio.h>

int main() {

    int a = 1;

    while (a <= 5) {
        printf("a = %d\n", a);
        a+= 2;
    }
    printf("After exiting the loop: a = %d\n", a);
    return 0;
}