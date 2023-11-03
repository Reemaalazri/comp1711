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
//with the help of the codes taken in class
//create an array of 100 FITNESS_DATA records
    FITNESS_DATA record [100];
//keep track of how many times a code is executed
//store index position
    int counter = 0;
    int bufferLength = 100; //size of file (lines)
    char bufferLine[bufferLength];

//create temp storage for the fields and change them to char for now
//store each one in the correct format requested like YYYY-MM-DD  for date and HH:mm for time and steps is numbers of int
    char date[11];
    char time[6];
    char steps[6];

//get data form the file and read each line, until  no more lines to read then it exits the loop
while (fgets(bufferLine, bufferLength, file) !=NULL) {
//take all the records and list them uniquely
    tokeniseRecord(bufferLine, "," , date, time, steps);
//copies the string pointed and print it
    strcpy(record[counter].date, date);
    strcpy(record[counter].time, time);
//change string into integer representation
    record[counter].steps = atoi(steps);
//all lines until end
    counter++;
}
//print number of lines in the file
printf("Number of records in file: %d\n", counter);

//print the first 3 records in the file using for loop
//got little help form ChatGBT
for (int i = 0; i < 3 && i < counter; i++)
//choose the fields you specified before to print
    {
    printf("%s/%s/%d\n", record[i].date, record[i].time, record[i].steps);
    }

//if no error, close file and return success
    fclose(file);
    return 0;
}