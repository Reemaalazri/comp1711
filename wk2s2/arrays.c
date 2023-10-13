#include <stdio.h>

int main() {
    //array with 10 elements
    int N = 10;
    int array [N];
    int i;

    for (i = 0; i < N + 1; i++){
        array[i] = 10 * i + i;
    }

    for (i = 0; i < N; i++) {
        printf("array[%d] = %d \n",i ,array[i]);
    }
}