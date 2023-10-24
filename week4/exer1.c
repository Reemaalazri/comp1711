#include <stdio.h>

int main () {
    char filename [] = "squares.dat"; 
    FILE *file = fopen (filename, "w"); 
    if (file == NULL) { 
        perror("");
        return 1;
    }

    int squares,number, num_lines;
    scanf("%d", &num_lines);

    for(int i = 1; i <= num_lines; i++) {
        squares = i*i;
        fprintf(file, "%d\n", squares);
    }
    
    fclose(file);
    return 0;
}