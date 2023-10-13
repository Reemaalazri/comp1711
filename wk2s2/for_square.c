#include <stdio.h>

int main() {
    int a, count, square;

    for(a = 1; a <=10; count++) {
        square = a*a;
        printf("%d\n", square);
        a++;
    }

    return 0;
}