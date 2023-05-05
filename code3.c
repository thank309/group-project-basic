#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdint.h"
#include "stduent.c"
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


//Task 1
void nhapSV(students* student, int num_student){
		do{
	                //A LOOP ENSURES THAT USERS HAVE TO INPUT A NUMBER SMALLER THAN 1000
        printf("\nThe numbers of students(Max 1000) is: ");     
        scanf("%d", &num_student);
        if(num_student>1000){
            printf("Outta range!!!\nPlease try again with a number smaller than 1000");          
        }; 
	}while(num_student>1000);
    for ( int i=0; i < num_student; i++){
        printf("\nThe ID student %d is: ",i+1);
        scanf("%s", student[i].id);
        printf("The first name of student %d is: ",i+1);
        scanf("%s", student[i].first_name);
        printf("The last name of student %d is: ",i+1);
        scanf("%s", student[i].last_name);
        printf("What's your birthday(DD/MM/YYYY): ");
        scanf("%s", student[i].birth);
        printf("The score Alebra of student %d is: ",i+1);
        scanf("%f", &student[i].al);
        printf("The score Calculus of student %d is: ",i+1);
        scanf("%f", &student[i].cal);
        printf("The score Basic Programming of student %d is: ",i+1);
        scanf("%f", &student[i].basic);
        student[i].gpa = (student[i].al + student[i].basic + student[i].cal)/3;
        strcpy(student[i].full_name, student[i].last_name);          //Assign full name to each student by merging last name + white space + full name
        strcat(student[i].full_name, " ");
        strcat(student[i].full_name, student[i].first_name);
        strupr(student[i].full_name);
        strupr(student[i].last_name);
    }
}
//taks 2
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
			    //Task 6
    printf("\n%-15s%-15s%-15s%s\n", "StudentID","Full Name","Birthdate","The last word in the name");
    printf("-----------------------------------------------------------------------\n");
    for (int i=0; i<num_student; i++){
        printf("%-15s%-15s%-15s%s\n", student[i].id, student[i].full_name, student[i].birth, student[i].last_name);
}
}
int main(void)
{
	students sv;
	students student[100];
	students p[100];
	int size;
	int num_student;
    int luaChon;
    	do {
		printf("\n=============== MENU ===============");
		printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. In thong tin sv ra file.");
		printf("\n4. Tim sinh vien co GPA cao nhat.");
		printf("\n5. Tim sinh vien co GPA thap nhat.");
		printf("\n6. Tim sinh vien co BP cao nhat.");
		printf("\n7. Hien thi ten sinh vien.");
		printf("\n8. Tim sinh vien lon tuoi nhat.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		switch(luaChon) {
    case 0:
    	break;
    case 1:
    	nhapSV(student, num_student);
    	student[num_student++];
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
	default:
		printf("Sai chuc nang, vui long chon lai!\n");
		break;
		}
	} while(luaChon);
    
    return 0;
}
