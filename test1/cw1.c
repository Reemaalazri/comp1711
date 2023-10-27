#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FILE *file = fopen ("FitnessData_2023.csv", "r"); 
    if (file == NULL) { //error check
        perror("");
        return 1;
    }

    // FITNESS_DATA record [1000];

    // int buffer_size = 100; //size of file (lines)
    // char line_buffer[buffer_size];
    // char date [11], char time[6],int steps;
    // while (fgets(line_buffer, buffer_size, file) !=NULL) { //read each line, when no more lines to read it exits the loop
    //     printf("%s\n", line_buffer); //
    // }



    // tokeniseRecord(fitness, "," , date, time, steps);


//fprintf writes in file
//if no error, close file and return success
    fclose(file);
    return 0;
}