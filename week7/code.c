#include "utilities.h"

int main()
{
    // array of daily readings (struct of 100 arrays)
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

//read it outside while loop, open it read it save it all once at beginning
    FILE *input = fopen(filename, "r");
        if (!input)
        {
            printf("Error: File could not be opened\n");
            return 1;
        } //error if file not found

//no need to repeat all this again, instead right it once at beg of create a function and then call it each time
    while (fgets(line, buffer_size, input))
    {
    // split up the line and store it in the right place
    // using the & operator to pass in a pointer to the bloodIron so it stores it
    tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
    //mean += daily_readings[counter].bloodIron;
    counter++;
    }

    fclose(input);

    int num_records = counter;

    for(int i = 0; i < num_records; i++)
    {
        if(daily_readings[i].date[0]=='\0' || daily_readings[i].bloodIron == 0)
        {
            printf("Error: Bad data\n");
        }
    }

//it goes forever
    while (1)
    {
        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n"); //quit from while loop which loops forever

        // get the next character typed in and store in the 'choice'
        choice = getchar();//get next charachter the user enters and enter it into choice

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');//enter button(new line)

        // switch statement to control the menu.

        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            break;

        case 'B':
        case 'b':
            mean = 0;
            for (int i = 0; i < num_records; i++)
            {
                mean += daily_readings[i].bloodIron;
            }
            mean /= num_records;
            printf("Your average blood iron was %.2f\n", mean);
            break;
        
        case 'C':
        case 'c':
            return 0;
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}