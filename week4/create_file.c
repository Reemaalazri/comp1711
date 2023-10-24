#include <stdio.h>

int main () {
    char filename [] = "data.txt"; //char array and name of file
    FILE *file = fopen (filename, "w"); //open a file in write mode can be: "a", "w+", "a+"
    if (file == NULL) { //error check
        perror("");
        return 1;
    }
//if no error, close file and return success
    fclose(file);
    return 0;
}