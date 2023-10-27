#include <stdio.h>

struct student { //define a data type
    char name [20];
    char student_id [10]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student; //new_student is the name of the variable and then declare the items (it has 3 fields) access it with . nottaion
    printf("Insert data [name, id, mark]\n");
    scanf("%s", new_student.name);
    scanf("%s", new_student.student_id);
    scanf("%d", &new_student.mark);
    printf("Student name: %s\n", new_student.name); //after the dot there is new student
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}