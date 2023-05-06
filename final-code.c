#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "finalcode.h"


int main(){
  int num_student;           
  do{ // A LOOP ENSURES THAT USERS HAVE TO INPUT A NUMBER SMALLER THAN 1000
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
    scanf("%s",student[i].id);
    
    gets(student[i].full_name);
    printf("\nThe full name of student %d : ", i + 1);
    gets(student[i].full_name);
    for(int x = 0; true; x++){
      if (isalpha((student[i].full_name)[x]) != 0){       //isalpha will give back a non-zero number if that position in array have a character
        break;   //break to stop the loop
      }
      else{
        printf("\nInvalid value, please type as letters"); //if the input contains a non-alphabet character, it leads to the "else" function
        printf("\nThe full name of student %d : ", i + 1);
        scanf("%s" ,student[i].full_name);
        continue;
      }
    }  
    
    printf("\nWhat's your birthday(DD/MM/YYYY): ");
    scanf("%s", student[i].birth);
    for(int x = 0; true; x++){
      int len = strlen(student[i].birth);
      if( len != 10){        //If the len of input is not 10, it will repeart the loop (10 because DD/MM/YYYY has 10 places)
        printf("\nNot enough character, your input must in format DD/MM/YYYY");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s",student[i].birth);
        continue;
      }
      if((student[i].birth)[2] != '/' || (student[i].birth)[5] != '/'){    //check "/" in between DD and MM, MM and YYYY as well
        printf("\nWrong format, please do it as DD/MM/YYYY");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        continue;
      }
      else if(isalpha((student[i].birth)[x]) != 0 && (x != 2 || x != 5)){  //we don't consider x = 2 and x = 5 because it's already checked above to ensure that position for "/"
        printf("\nYour input must be numbers");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        continue;
      }
      else{
        break;
      }
    }  
    
    while(true){
      printf("\nThe score Alebra of student %d : ", i + 1);
      scanf("%f", &student[i].al);
      if(student[i].al > 20 || student[i].al <0){
        printf("\nOut of range (0 to 20), please try again");
        continue;
      }
      else{
        break;
      }
    }
    
    while(true){
      printf("\nThe score Calculus of student %d : ", i + 1);
      scanf("%f", &student[i].cal);
      if(student[i].cal > 20 || student[i].cal <0){
        printf("\nOut of range, please try again");
        continue;
      }
      else{
        break;
      }
    }

    while(true){
      printf("\nThe score Basic Programming of student %d : ", i + 1);
      scanf("%f", &student[i].basic);
      if(student[i].basic > 20 || student[i].basic <0){
        printf("\nOut of range, please try again");
        continue;
      }
      else{
        break;
      }
    }

    student[i].gpa = (student[i].al + student[i].basic + student[i].cal) / 3;
    strupr(student[i].full_name);
    char cpy[20];
    strcpy(cpy, student[i].full_name);
    student[i].last_name = strtok(cpy, " ");
    student[i].first_name = strtok(NULL, " ");
  }
  
  //Task 3
  // Print the header as the follwing code  
  printf("\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
  printf("----------------------------------------------------------------------------------------------\n");

  // Print informations of each student
  for (int i = 0; i < num_student; i++){
    printf("%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n", student[i].id, student[i].full_name,
           student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
  };

  // Print output to a file         //Task 4
  FILE *f = fopen("Lists of Students.txt", "w");
  fprintf(f, "\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
  fprintf(f, "----------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < num_student; i++){
    fprintf(f, "%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n", student[i].id, student[i].full_name,
            student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
  }
  fclose(f);
  printf("\nThe File 'List of Student.txt' has been printed out succesfully, please check in your folder \n");

  //Task 5

  highest(student, num_student);
  lowest(student, num_student);
  hbp(student, num_student);

  // Task 6
  printf("\n%-15s%-15s%-15s%s\n", "StudentID", "Full Name", "Birthdate", "The last word in the name");
  printf("-----------------------------------------------------------------------\n");
  for (int i = 0; i < num_student; i++){
    printf("%-15s%-15s%-15s%s\n", student[i].id, student[i].full_name, student[i].birth, student[i].first_name);
  }

  findoldest(student, num_student);
  return 0;
}