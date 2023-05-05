#ifndef STUDENT_H
#define STUDENT_H

typedef struct{                //DATA STORES INFORMATIONS OF A STUDENT 
    char id[20];                                           
    char first_name[20];
    char last_name[20];
    char birth[20];
    float al;
    float cal;
    float basic;
    float gpa;
    char full_name[20];
} students;

void print_the_oldest(students* student, int total_student);

#endif 
