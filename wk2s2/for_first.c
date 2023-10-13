#include <stdio.h>

int main() {
//a=1
    int a;

    for (a = 1; a <= 5; a += 2) {
        printf("a = %d\n", a);
    }
    
    printf("After exiting the loop: a = %d\n", a);
    return 0;
}