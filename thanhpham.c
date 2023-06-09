#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{ //DATA STORES INFORMATIONS OF A STUDENT
  char id[20];
  char full_name[20];
  char birth[20];
  float al;
  float cal;
  float basic;
  float gpa;
  char first_name[20];
  char last_name[20];
}students;

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
    scanf("%s", student[i].id);

    printf("\nThe first name of student %d : ", i + 1);
    scanf("%s", student[i].first_name);
    for(int x = 0; true; x++){
      if (isalpha((student[i].first_name)[x]) != 0){       //isalpha will give back a non-zero number if that position in array have a character
        break;   //break to stop the loop
      }
      else{
        printf("\nInvalid value, please type as letters"); //if the input contains a non-alphabet character, it leads to the "else" function
        printf("\nThe first name of student %d : ", i + 1);
        scanf("%s", student[i].first_name);
        continue;
      }
    }  
    
    printf("\nThe last name of student %d : ", i + 1);
    scanf("%s", student[i].last_name);
    for(int x = 0; true; x++){
      if (isalpha((student[i].last_name)[x]) != 0){
        break;
      }
      else{
        printf("\nInvalid value, please type as letters");
        printf("\nThe last name of student %d : ", i + 1);
        scanf("%s", student[i].last_name);
        continue;
      }
    } 

    printf("\nWhat's your birthday(DD/MM/YYYY): ");
    scanf("%s", student[i].birth);
    for(int x = 0; true; x++){
      int len = strlen(student[i].birth);
      if( len != 10){        //If the len of input is not 10, it will repeart the loop (10 because DD/MM/YYYY has 10 places)
        printf("\nYou might input not enough numbers of characters");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s",student[i].birth);
        continue;
      }
      if((student[i].birth)[2] != '/' || (student[i].birth)[5] != '/'){    //check "/" in between DD and MM, MM and YYYY as well
        printf("\nYou might input wrong pattern, please do it as DD/MM/YYYY");
        printf("\nWhat's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        continue;
      }
      else if(isalpha((student[i].birth)[x]) != 0 && (x != 2 || x != 5)){  //we don't consider x = 2 and x = 5 because it's already checked above to ensure that position for "/"
        printf("\nYou might input a character not a number");
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
        printf("\nOut the range of band Alebra (0 to 20), please try again");
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
        printf("\nOut the range of Algebra (0 to 20), please try again");
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
        printf("\nOut the range of Basic Programming (0 to 20), please try again");
        continue;
      }
      else{
        break;
      }
    }

    student[i].gpa = (student[i].al + student[i].basic + student[i].cal) / 3;
    strcpy(student[i].full_name, student[i].last_name);          //Assign full name to each student by merging last name + white space + full name
    strcat(student[i].full_name, " ");
    strcat(student[i].full_name, student[i].first_name);
    strupr(student[i].full_name);
    strupr(student[i].first_name);
  }
  
  //Print out to the file name "Lists of Students.txt"
  FILE *f = fopen("Lists of Students.txt", "w");
  fprintf(f, "\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID", "Full Name", "Birthdate", "Algebra", "Calculus", "Basic Programming", "GPA");
  fprintf(f, "----------------------------------------------------------------------------------------------\n");
  for (int i = 0; i < num_student; i++){
    fprintf(f, "%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n", student[i].id, student[i].full_name,
            student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
  }
  fclose(f);

  return 0;
}