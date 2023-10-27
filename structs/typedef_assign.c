#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10, i;
    student students [10];//none of them have any values
//assign data to it
//name and id are strings so, you need to type in things
//sptinf creates a string based on whats added
    for (i=0; i < number_of_students; i++) {
        sprintf(students[i].name, "Student %d", i);//toprint student 1 - to print it to string
        sprintf(students[i].student_id, "174343%d", i);//print string and copy that to that string
        students[i].mark = 35 + (13 + (i*17)) %65; //mark
    }

    for (i = 0; i < number_of_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}