#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here

// Global variables for filename and FITNESS_DATA array


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
    char choice;
    float mean = 0;
    int counter = 0;
    int bufferLength = 100; //size of file (lines)
    char bufferLine[bufferLength];
    //char line[buffer_size];
    char filename[bufferLength];
    //int num_records = counter;
    int min,max,i;
    int row = 0;
    int col=0;
    int currentLength = 0;
    int maxLength = 0;
    int first = -1;
    int longestStart = -1;   
    //fclose(input);

    char date[11];
    char time[6];
    char steps[8];

    while (fgets(bufferLine, bufferLength, file) !=NULL) {
        tokeniseRecord(bufferLine, "," , date, time, steps);
        strcpy(record[counter].date, date);
        strcpy(record[counter].time, time);
        record[counter].steps = atoi(steps);
        counter++;}

        
//it runs forever
    while (1)
    {
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");                       // BRONZE
        printf("B: Display the total number of records in the file\n");                    // BRONZE
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                     // SILVER
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                    // SILVER
        printf("E: Find the mean step count of all the records in the file\n");       // SILVER/GOLD
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); // GOLD - see readme.md
        printf("Q: Quit\n"); //quit from while loop which loops forever
        printf("Enter your choice: ");
        scanf("%s", &choice);

        // get the next character typed in and store in the 'choice'
        //choice = getchar();//get next charachter the user enters and enter it into choice

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');//enter button(new line)

        // switch statement to control the menu.

        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':

            printf("Input filename: ");

            fgets(bufferLine, bufferLength, stdin);
            sscanf(bufferLine, " %s ", filename);
            
            FILE *input = fopen(filename, "r");
                if (!input)
                {
                    printf("Error: Could not find or open the file.\n");
                    return 1;
                }
                else
                {
                    printf("File successfully loaded.\n");
                }
                
            fclose(input);
            break;
        
        case 'B':
        case 'b':

            for(int i = 0; i < counter; i++)
            {
              //if(record[i].date[0]=='\0' || record[i].time[0]=='\0' || record[i].steps == 0)
              //{
                  //printf("Error: Bad data\n");
              //}
            }
            printf("Number of records in file: %d\n", counter);
            //return 0;
            break;
        
        case 'C':
        case 'c':
        //calculate for fewest steps
            if (counter > 0){
            min = record[0].steps;
            for (i = 1; i < counter; i++)
            {
                if (record[i].steps < min)
                {
                    min = record[i].steps;
                    row = i;
                }
            }
        //print date and time where the steps were the fewest
        printf("Fewest steps: %s %s \n", record[row].date, record[row].time);
            break;
        }

        case 'D':
        case 'd':
        //calculate for largest steps
            max = record[0].steps;
            for (i = 1; i < counter; i++)
            {
                if (record[i].steps > max)
                {
                    max = record[i].steps;
                    col = i;
                }
            }
        //print date and time where the steps were the highest
        printf("Largest steps: %s %s \n", record[col].date, record[col].time);

        break;

        case 'E':
        case 'e':
        //calculate mean for steps
            mean = 0;
            for (int i = 0; i < counter; i++)
            {
                mean += record[i].steps;
            }
            mean /= counter;
            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
            first = -1;
            longestStart = -1;
            maxLength = 0;
            currentLength = 0;

            for (i = 0; i < counter; i++) {
                if (record[i].steps > 500) {
                    if (first == -1) {
                        first = i;
                    }
                    currentLength++;
                } else {
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        longestStart = first;
                    }
                    first = -1;
                    currentLength = 0;
                }
            }

                // Check for the last period in case it extends to the end of the array
            if (currentLength > maxLength) {
                maxLength = currentLength;
                longestStart = first;
            }

            if (maxLength > 0) {
                // Print the start and end records of the longest continuous period
                printf("Longest period start: %s %s\n", record[longestStart].date, record[longestStart].time);
                printf("Longest period end: %s %s\n", record[longestStart + maxLength - 1].date,
                        record[longestStart + maxLength - 1].time);
            } else {
                printf("No continuous period above 500 steps found.\n");
            }
            //return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice. Try Again.\n");
            break;
        }
    }
}

