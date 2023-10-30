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
//open the file and read it
    FILE *file = fopen ("FitnessData_2023.csv", "r");
//error check
    if (file == NULL) {
        perror("");
        return 1;
    }

//create an array of 100 FITNESS_DATA records
    FITNESS_DATA record [100];
    int lines = 0;
    int buffer_size = 100; //size of file (lines)
    char line_buffer[buffer_size];

//create temp storage for and change steps to characters for now
    char date [11];
    char time[6];
    char steps[6];

//get data form the file and read each line, until  no more lines to read it then it exits the loop
while (fgets(line_buffer, buffer_size, file) !=NULL) {
//take all the records and list them uniquely
    tokeniseRecord(line_buffer, "," , date, time, steps);
//copies the string pointed and print it
    strcpy(record[lines].date, date);
    strcpy(record[lines].time, time);
    record[lines].steps = atoi(steps);
//print all lines until end
    lines++;
}
//print number of lines in the file
printf("Number of records in file: %d \n", lines);

//print the first 3 records in the file using for loop
for(lines = 0; lines < 3; lines++)
//choose the fields you want to print 
    {
    printf("%s/%s/%d\n", record[lines].date, record[lines].time, record[lines].steps);
    }

//if no error, close file and return success
    fclose(file);
    return 0;
}