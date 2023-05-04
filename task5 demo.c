#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void highest(students* p, int size){
  float highest = 0;
  int index = 0;
  for (int i = 0; i<size; i++, p++){
    if (p[i].gpa > highest){
      index = i;
      printf("\nThe HIGHEST GPA is: %0.2f\n", highest);
      printf("\n%-15s%-15s%-15s%s", "StudentID","Full Name", "Birthdate", "GPA");
      printf("\n-------------------------------------------------");
      printf("\n%-15s%-15s%-15s%0.2f", p[index].id, p[index].full_name, p[index].birth, p[index].gpa );
    }
    else if(p[i].gpa == highest){
      index = i;
      printf("\n%-15s%-15s%-15s%0.2f", p[index].id, p[index].full_name, p[index].birth, p[index].gpa );
    }
  }
};

int main(){
    int num_student;
    float arrgpa[num_student];

    do{                       //A LOOP ENSURES THAT USERS HAVE TO INPUT A NUMBER SMALLER THAN 1000
        printf("\nThe numbers of students(Max 1000) is: ");     
        scanf("%d", &num_student);
        if(num_student>1000){
            printf("Outta range!!!\nPlease try again with a number smaller than 1000");
            
        }; 
    }while(num_student>1000);
    students student[num_student];
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
        arrgpa[i] = student[i].gpa;
    }

    //Print the header as the follwing code
    printf("\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    printf("----------------------------------------------------------------------------------------------\n");

    //Print informations of each student
    for( int i=0; i< num_student; i++){
        printf("%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%0.2f\n",student[i].id, student[i].full_name,
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    };

    highest(student, num_student);
    return 0;
}
