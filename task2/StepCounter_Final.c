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
//with the help of the codes taken in class
//create an array of 500 FITNESS_DATA records
    FITNESS_DATA record [500];
//keep track of how many times a code is executed
//store index position

//additional variables
    char choice;
    float mean = 0;
    int counter = 0;
    int bufferLength = 100; //size of file (lines)
    char bufferLine[bufferLength];
    char filename[bufferLength];
    int min,max,i;
    int row = 0;
    int col = 0;
    int currentLength = 0;
    int maxLength = 0;
    int first = -1;
    int longestStart = -1;   

//create temp storage for date, time and steps with number of characters
    char date[11];
    char time[6];
    char steps[8];
        
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
        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');//enter button(new line)

        // switch statement to control the menu.

        switch (choice)
        {
        //this allows for either capital or lower case
//case A, ask for filename and open it
        case 'A':
        case 'a':
//ask user to input the filename 
            printf("Input filename: ");
// read in a line from the stdin (where the user types), it removes any spaces or newlines after extracting the actual string from it
            fgets(bufferLine, bufferLength, stdin);
            sscanf(bufferLine, " %s ", filename);

//search for file and open it           
            FILE *file = fopen(filename, "r");
                if (!file)
                {
                    printf("Error: Could not find or open the file.\n");//if file not found, print a statement
                    return 1;
                }
                else
                {
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
                    counter++;}
                    printf("File successfully loaded.\n");//print a statement after loading the file
                }
                
            fclose(file);
            break;
//case B, count number of lines in the file       
        case 'B':
        case 'b':
//initialize i from first line and then count until end
            for(int i = 0; i < counter; i++)
            {
                printf("Number of records in file: %d\n", counter);
              //if(record[i].date[0]=='\0' || record[i].time[0]=='\0' || record[i].steps == 0)
            }
                  //printf("Error: Bad data\n");
              //}
            //}
            //printf("Number of records in file: %d\n", counter);
            //return 0;
            break;
//case C, search for the fewest steps and print the time and date for that record        
        case 'C':
        case 'c':
        //calculate for fewest steps
            if (counter > 0){
            //initialize min to first record in steps
            min = record[0].steps;
            //then compare it to all lines until finding the smallest number
            for (i = 1; i < counter; i++)
            {
                //after comparing and finiding the smallest one print the date and time
                if (record[i].steps < min)
                {
                    //let the record found be min
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
        //initialize max to first record in steps
            max = record[0].steps;
            //then compare it to all lines until finding the largest number of steps
            for (i = 1; i < counter; i++)
            {
                //after comparing and finiding the largest one print the date and time
                if (record[i].steps > max)
                {
                    //let the record found be max
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
        //initialize mean to zero
            //mean = 0;
            //then get all records of steps
            for (int i = 0; i < counter; i++)
            {
                //add them all
                mean += record[i].steps;
            }
            //then divide it by the number of lines of steps
            mean /= counter;
            //print the answer and round it to whole number
            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
        //find the records for the longest continouos period where steps where more than 500
            first = -1;
            longestStart = -1;
            maxLength = 0;
            currentLength = 0;

            for (i = 0; i < counter; i++) {
                if (record[i].steps > 500) {
                    if (first == -1) 
                    {
                        first = i;
                    }
                    currentLength++;
                } else {
                    if (currentLength > maxLength) 
                    {
                        maxLength = currentLength;
                        longestStart = first;
                    }
                    first = -1;
                    currentLength = 0;
                }
            }

            //make sure that the last period printed is within the range
            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                longestStart = first;
            }

            if (maxLength > 0) 
            {
                // Print the start and end records of the longest continuous period
                printf("Longest period start: %s %s\n", record[longestStart].date, record[longestStart].time);
                printf("Longest period end: %s %s\n", record[longestStart + maxLength - 1].date, record[longestStart + maxLength - 1].time);
            } 
            else 
            {
                printf("No continuous period above 500 steps found.\n");
            }
            //return 0;
            break;

        case 'Q':
        case 'q':
            //Q to quit
            return 0;
            break;
        //if the user entered a letter out of the range, ask them to re-enter a letter
            default:
            printf("Invalid choice. Try Again.\n");
            break;
        }
    }
}

