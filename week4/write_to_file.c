#include <stdio.h>

int main () {
    char filename [] = "data.txt"; //char array and name of file
    FILE *file = fopen (filename, "w"); //open a file in write mode can be: "a", "w+", "a+"
    if (file == NULL) { //error check
        perror("");
        return 1;
    }

    int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines);

    for(int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
    }

//fprintf writes in file
//if no error, close file and return success
    fclose(file);
    return 0;
}