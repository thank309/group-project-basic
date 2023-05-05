#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "stdint.h"
#include "student.c"


//Task 1
void entersv(students* student, int num_student){
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

  printf("What's your birthday(DD/MM/YYYY): ");
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
    
  printf("The score Alebra of student %d : ", i + 1);
  scanf("%f", &student[i].al);
  printf("The score Calculus of student %d : ", i + 1);
  scanf("%f", &student[i].cal);
  printf("The score Basic Programming of student %d : ", i + 1);
  scanf("%f", &student[i].basic);
  student[i].gpa = (student[i].al + student[i].basic + student[i].cal) / 3;
  strcpy(student[i].full_name, student[i].last_name);          //Assign full name to each student by merging last name + white space + full name
  strcat(student[i].full_name, " ");
  strcat(student[i].full_name, student[i].first_name);
  strupr(student[i].full_name);
  strupr(student[i].last_name);
  }  
}
//Taks 2
void inSV(students* student, int num_student){
		    //Print the header as the follwing code
    printf("\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    printf("----------------------------------------------------------------------------------------------\n");

    //Print informations of each student
    for( int i=0; i< num_student; i++){
        printf("%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n",student[i].id, student[i].full_name,
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    }
}
//task 4
void inFile(students* student, int num_student){
	    	    //Print output to a file
    FILE *f = fopen("Lists of Students.txt", "w");
    fprintf(f,"\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    fprintf(f,"----------------------------------------------------------------------------------------------\n");
    for( int i=0; i< num_student; i++){
        fprintf(f, "%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%.2f\n",student[i].id, student[i].full_name,
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    }
    fclose(f);
}

//task 5
void highest(students* student, int num_student){        //Find and print the highest gpa
  float highest = 0;
  for(int i = 0; i<num_student; i++){
    if (student[i].gpa > highest){
      highest = student[i].gpa;
    }
  }
  printf("\nThe HIGHEST GPA grade is: %.2f", highest);
  printf("\n%-15s%-15s%-15s%s", "StudentID","Full Name", "Birthdate", "GPA");
  printf("\n---------------------------------------------------");
  for(int i = 0; i<num_student; i++){
    if(student[i].gpa == highest){
      printf("\n%-15s%-15s%-15s%0.2f", student[i].id, student[i].full_name, student[i].birth, student[i].gpa );
    }
  }
  printf("\n");
};

void lowest(students* student, int num_student){       //Find and print the lowest gpa
  float lowest = student[0].gpa;
  int index = 0;
  for(int i = 0; i<num_student; i++){
    if (student[i].gpa < lowest){
      lowest = student[i].gpa;
    }
  }
  printf("\nThe LOWEST GPA grade is: %.2f", lowest);
  printf("\n%-15s%-15s%-15s%s", "StudentID","Full Name", "Birthdate", "GPA");
  printf("\n---------------------------------------------------");
  for(int i = 0; i<num_student; i++){
    if(student[i].gpa == lowest){
      printf("\n%-15s%-15s%-15s%0.2f", student[i].id, student[i].full_name, student[i].birth, student[i].gpa );
    }
  }
  printf("\n");
};

void hbp(students* student, int num_student){        //Find and print the highest basic programming
  float hbp = 0;  
  for(int i = 0; i<num_student; i++){
    if (student[i].basic > hbp){
      hbp = student[i].basic;
    }
  }
  printf("\nThe HIGHEST BASIC PROGRAMMING grade is: %.2f", hbp);
  printf("\n%-15s%-15s%-15s%s", "StudentID","Full Name", "Birthdate", "GRADE");
  printf("\n---------------------------------------------------");
  for(int i = 0; i<num_student; i++){
    if(student[i].basic == hbp){
      printf("\n%-15s%-15s%-15s%-15s%0.2f", student[i].id, student[i].full_name, student[i].birth, student[i].basic );
    }
  }
  printf("\n");
};
//task 6
void lastName(students* student, int num_student){
  printf("\n%-15s%-15s%-15s%s\n", "StudentID","Full Name","Birthdate","The last word in the name");
  printf("-----------------------------------------------------------------------\n");
  for (int i=0; i<num_student; i++){
    printf("%-15s%-15s%-15s%s\n", student[i].id, student[i].full_name, student[i].birth, student[i].last_name);
    }
}
int main(){
	students sv;
	students student[1000];
	int size;
	int num_student;
    int select;
    	do {
		printf("\n=============== MENU ===============");
		printf("\n1. Add students into the list.");
		printf("\n2. Display the list of students.");
		printf("\n3. Print students informations into file.");
		printf("\n4. Find students who has the highest GPA.");
		printf("\n5. Find students who has the lowest GPA.");
		printf("\n6. Find students who has the highest basic programming grade.");
		printf("\n7. Display the students name");
		printf("\n8. Find the oldest student.");
		printf("\n0. Exit.");
		printf("\nSelect: ");

		scanf("%d", &select);
		switch(select) {
    case 0:
    	break;
    case 1:
    	do{
	                //A LOOP ENSURES THAT USERS HAVE TO INPUT A NUMBER SMALLER THAN 1000
        printf("\nThe numbers of students(Max 1000) is: ");     
        scanf("%d", &num_student);
        if(num_student>1000){
            printf("Outta range!!!\nPlease try again with a number smaller than 1000");          
        }; 
        
	    }while(num_student>1000);
    	entersv(student, num_student);
    	student[num_student+1];
    	break;
	  case 2:
    inSV(student, num_student);
		break;
	  case 3:
		inFile(student, num_student);
		break;
    case 4:
    highest(student, num_student);
		break;
	  case 5:
		lowest(student, num_student);
		break;
	  case 6:
		hbp(student, num_student); 
		break;
	  case 7:
		lastName(student, num_student);
		break;
	  case 8: 
	  print_the_oldest(student , num_student);
	  break;
	  default:
		printf("Wrong syntax, please try again!\n");
		break;
		}
	}while(select);

    return 0;
}
