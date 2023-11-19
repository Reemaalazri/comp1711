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
    int num_records = counter;

    //char buffer_size = 0;

    // get filename from the user
    //printf("Input filename: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    //fgets(bufferLine, bufferLength, stdin);
    //sscanf(bufferLine, " %s ", filename);
//read it outside while loop, open it read it save it all once at beginning
    //FILE *input = fopen(filename, "r");
    //    if (!input)
    //    {
    //        printf("Error: Could not find or open the file.\n");
    //        return 1;
    //    } //error if file not found

    //fclose(input);

    char date[11];
    char time[6];
    char steps[6];

//while (fgets(bufferLine, bufferLength, input) !=NULL) {
//take all the records and list them uniquely
//    tokeniseRecord(bufferLine, "," , date, time, steps);
//copies the string pointed and print it
//    strcpy(record[counter].date, date);
//    strcpy(record[counter].time, time);
//change string into integer representation
//    record[counter].steps = atoi(steps);
//all lines until end
//   counter++;
//}
//while (fgets(bufferLine, bufferLength, input))
  //  {
    // split up the line and store it in the right place
    // using the & operator to pass in a pointer to the bloodIron so it stores it
    //tokeniseRecord(bufferLine, ",", record[counter].date, record[counter].time, record[counter].steps);
    //strcpy(record[counter].date, date);
    //strcpy(record[counter].time, time);
    //record[counter].steps = atoi(steps);
    //mean += daily_readings[counter].bloodIron;
    //counter++;
    //}
//print number of lines in the file
//printf("Number of records in file: %d\n", counter);

//it goes forever
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

            printf("Input filename:");

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

                    while (fgets(bufferLine, bufferLength, input) !=NULL) {
                    tokeniseRecord(bufferLine, "," , date, time, steps);
                    strcpy(record[counter].date, date);
                    strcpy(record[counter].time, time);
                    record[counter].steps = atoi(steps);
                    counter++;}
                    printf("File successfully loaded.\n");
                }
                
            fclose(input);
            //return 0;
            break;
        
        case 'B':
        case 'b':

            for(int i = 0; i < num_records; i++)
            {
              if(record[i].date[0]=='\0' || record[i].time[0]=='\0' || record[i].steps == 0)
              {
                  printf("Error: Bad data\n");
              }
            }
            printf("Number of records in file: %d\n", counter);
            //return 0;
            break;
        
        case 'C':
        case 'c':
        //calculate for fewest steps
            //int min = INT_
            //for(int i = 0; i < num_records; i++)
            //if min>
            //if(record[i].date[0]=='\0' || record[i].time[0]=='\0' || record[i].steps == 0)
            return 0;
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            mean = 0;
            for (int i = 0; i < counter; i++)
            {
                mean += record[i].steps;
            }
            mean /= counter;
            printf("Mean step count: %f\n", mean);
            //change float to decimal
            break;

        case 'F':
        case 'f':
            return 0;
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
