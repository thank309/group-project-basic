#ifndef OLDEST_H
#define OLDEST_H


typedef struct    //common task
{ // DATA STORES INFORMATIONS OF A STUDENT
  char id[20];
  char full_name[20];
  char birth[20];
  float al;
  float cal;
  float basic;
  float gpa;
  char first_name[20];
  char last_name[20];
} students;

void findoldest(students* student, int size);

#endif