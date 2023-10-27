#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name [20];
    char student_id [10]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student = {.mark = 35};
    strcpy(new_student.name, "Name Surname");//copies name into .name
    strcpy(new_student.student_id, "13902178");
    char mark_string[] = "35";
    new_student.mark = atoi(mark_string);
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}