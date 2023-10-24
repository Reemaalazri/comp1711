#include <stdio.h>
#include <stdlib.h>
int main () {
    char filename [] = "data.txt"; 
    FILE *file = fopen (filename, "r"); 
    if (file == NULL) { //error check
        perror("");
        return 1;
    }

    int buffer_size = 100; //size of file (lines)
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) !=NULL) { //read each line, when no more lines to read it exits the loop
        printf("%d\n", atoi(line_buffer)); //
    }

//fprintf writes in file
//if no error, close file and return success
    fclose(file);
    return 0;
}