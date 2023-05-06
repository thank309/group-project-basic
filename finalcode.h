#ifndef FINALCODE_H
#define FiNALCODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{ // DATA STORES INFORMATIONS OF A STUDENT
  char id[20];
  char full_name[20];
  char birth[20];
  float al;
  float cal;
  float basic;
  float gpa;
  char *first_name;
  char *last_name;
} students;

//Task 5
void highest(students *p, int size){ // Find and print the highest gpa
  float highest = 0;
  for (int i = 0; i < size; i++)
  {
    if (p[i].gpa > highest)
    {
      highest = p[i].gpa;
    }
  }
  printf("\nThe HIGHEST GPA grade is: %.2f", highest);
  printf("\n%-15s%-15s%-15s%s", "StudentID", "Full Name", "Birthdate", "GPA");
  printf("\n---------------------------------------------------");
  for (int i = 0; i < size; i++)
  {
    if (p[i].gpa == highest)
    {
      printf("\n%-15s%-15s%-15s%0.2f", p[i].id, p[i].full_name, p[i].birth, p[i].gpa);
    }
  }
  printf("\n");
};

void lowest(students *p, int size){ // Find and print the lowest gpa
  float lowest = p[0].gpa;
  int index = 0;
  for (int i = 0; i < size; i++)
  {
    if (p[i].gpa < lowest)
    {
      lowest = p[i].gpa;
    }
  }
  printf("\nThe LOWEST GPA grade is: %.2f", lowest);
  printf("\n%-15s%-15s%-15s%s", "StudentID", "Full Name", "Birthdate", "GPA");
  printf("\n---------------------------------------------------");
  for (int i = 0; i < size; i++){
    if (p[i].gpa == lowest)
    {
      printf("\n%-15s%-15s%-15s%0.2f", p[i].id, p[i].full_name, p[i].birth, p[i].gpa);
    }
  }
  printf("\n");
};

void hbp(students *p, int size){ // Find and print the highest basic programming
  float hbp = 0;
  for (int i = 0; i < size; i++)
  {
    if (p[i].basic > hbp)
    {
      hbp = p[i].basic;
    }
  }
  printf("\nThe HIGHEST BASIC PROGRAMMING grade is: %.2f", hbp);
  printf("\n%-15s%-15s%-15s%s", "StudentID", "Full Name", "Birthdate", "GRADE");
  printf("\n---------------------------------------------------");
  for (int i = 0; i < size; i++){
    if (p[i].basic == hbp)
    {
      printf("\n%-15s%-15s%-15s%0.2f", p[i].id, p[i].full_name, p[i].birth, p[i].basic);
    }
  }
  printf("\n");
};

void findoldest(students* student, int size){      //Find oldeset student
  int old_year = 9999, old_month = 13, old_day = 32;
  int index;
  for (int i=0; i < size; i++){
    char compare[20];
    strcpy(compare, student[i].birth);
    int day = atoi(strtok(compare, "/"));
    int month = atoi(strtok(NULL, "/"));
    int year = atoi(strtok(NULL, "/"));
      if(year < old_year){
        index = i;
        old_year = year;
      }
      else if(month < old_month && year == old_year){
        index = i;
        old_month = month;
      }
      else if(day < old_day && month  == old_month && year == old_year){
        index = i;
        old_day = day;
      }
    }
    if (index != -1){
       printf("\nTHE OLDEST STUDENT INFORMATION");
       printf("\nStudentID: %s", student[index].id);
       printf("\nFull name: %s", student[index].full_name);
       printf("\nBirthdate: %s", student[index].birth);
    }
    else{
       printf("\nNo students found!!!");
    }
}

#endif