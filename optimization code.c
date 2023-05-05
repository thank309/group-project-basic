#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{ // DATA STORES INFORMATIONS OF A STUDENT
  char id[20];
  char full_name[20];
  char birth[20];
  float al;
  float cal;
  float basic;
  float gpa;
  char first_name[20];
} students;

// Functions on task 5
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

void lowest(students *p, int size)
{ // Find and print the lowest gpa
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
  for (int i = 0; i < size; i++)
  {
    if (p[i].gpa == lowest)
    {
      printf("\n%-15s%-15s%-15s%0.2f", p[i].id, p[i].full_name, p[i].birth, p[i].gpa);
    }
  }
  printf("\n");
};

void hbp(students *p, int size)
{ // Find and print the highest basic programming
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
  for (int i = 0; i < size; i++)
  {
    if (p[i].basic == hbp)
    {
      printf("\n%-15s%-15s%-15s%0.2f", p[i].id, p[i].full_name, p[i].birth, p[i].basic);
    }
  }
  printf("\n");
};

int main()
{
  int num_student;

  do
  { // A LOOP ENSURES THAT USERS HAVE TO INPUT A NUMBER SMALLER THAN 1000
    printf("\nThe numbers of students(Max 1000) is: ");
    scanf("%d", &num_student);
    if (num_student > 1000)
    {
      printf("Outta range!!!\nPlease try again with a number smaller than 1000");
    };
  } while (num_student > 1000);
  
  students student[num_student];
  
  for (int i = 0; i < num_student; i++){
    printf("\nThe ID student %d : ", i + 1);
    scanf("%s", student[i].id);

    printf("\nThe full name of student %d : ", i + 1);
    scanf("%s", student[i].full_name);
    for(int x = 0; true; x++){
      if (isalpha((student[i].full_name)[x]) != 0){
        break;
      }
      else{
        printf("\nInvalid value, please type as letters");
        printf("\nThe full name of student %d : ", i + 1);
        scanf("%s", student[i].full_name);
        continue;
      }
    }  

    printf("What's your birthday(DD/MM/YYYY): ");
    scanf("%s", student[i].birth);
    int len = strlen(student[i].birth);
    for(int x = 0; true; x++){
      if(len < 10 || len >10){
        printf("You might input wrong pattern, please do it as DD/MM/YYYY");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        continue;
      }
      if(isalpha((student[i].birth)[x]) != 0 && (x != 2 || x != 5)){
        printf("\nYou might input a character not a number");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        continue;
      }
      else if((student[i].birth)[2] != '/' || (student[i].birth)[5] != '/'){
        printf("You might input wrong pattern, please do it as DD/MM/YYYY");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        continue;
      }
      else{
        break;
      }
    }  

    
    printf("The score Alebra of student %d : ", i + 1);
    scanf("%f", &student[i].al);
    printf("The score Calculus of student %d : ", i + 1);
    scanf("%f", &student[i].cal);
    printf("The score Basic Programming of student %d : ", i + 1);
    scanf("%f", &student[i].basic);
    student[i].gpa = (student[i].al + student[i].basic + student[i].cal) / 3;

  }
    

  // Print the header as the follwing code
  printf("\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
  printf("----------------------------------------------------------------------------------------------\n");

  // Print informations of each student
  for (int i = 0; i < num_student; i++)
  {
    printf("%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n", student[i].id, student[i].full_name,
           student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
  };

  // Print output to a file
  FILE *f = fopen("Lists of Students.txt", "w");
  fprintf(f, "\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
  fprintf(f, "----------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < num_student; i++)
  {
    fprintf(f, "%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n", student[i].id, student[i].full_name,
            student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
  }
  fclose(f);

  // Task 5

  highest(student, num_student);
  lowest(student, num_student);
  hbp(student, num_student);

  // Task 6
  printf("\n%-15s%-15s%-15s%s\n", "StudentID", "Full Name", "Birthdate", "The last word in the name");
  printf("-----------------------------------------------------------------------\n");
  for (int i = 0; i < num_student; i++)
  {
    printf("%-15s%-15s%-15s%s\n", student[i].id, student[i].full_name, student[i].birth, student[i].first_name);
  }

  return 0;
}