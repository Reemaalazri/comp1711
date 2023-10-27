#include <stdio.h>
#include <string.h>

typedef unsigned char mark_t; //ot typedef long long int mark_t or typedef char mark_t or unsigned long long int
//defines another name to give a new type a name
typedef struct { //defines a new name to a type
    char name [20];
    char student_id [10];
    mark_t mark;
} student;
//student and mark_t are now types
int main() {
    int n = 3;
    students students [] = {
        {}, {}, {}
    };
    return 0;
}


