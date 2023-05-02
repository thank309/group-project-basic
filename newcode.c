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

typedef struct{               //DATA STORES THE DATE OF BIRTH OF A STUDENT
    int day;
    int month;
    int year;
} time;

int nday(students *p){       //Convert a strings of day to integer
    char nday[20];
    strncpy(nday, p->birth, 2);
    return atoi(nday);
    }


int nmonth(students *p){       //Convert a string of month to integer
    char nmonth[20];
    strncpy(nmonth, p->birth, 5);
    strnset(nmonth, '0', 3);

    return atoi(nmonth);
    }

int nyear(students *p){       //Convert a string of year to integer
    char nyear[20];
    strrev(p->birth);
    strncat(nyear, p->birth, 4);
    strrev(nyear);
    strrev(p->birth);
    return atoi(nyear);
}

char letter(students *p){    //Split a string to a final character of string
    char letter;
    int len = strlen(p->first_name);
    strupr(p->first_name);
    letter = (p->first_name)[len-1];
    return letter; 
}


int main(){
    int num_student;
    float high_point, low_point, hbp_point; 
    int highest, lowest, hbp;
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
    }

    //Print the header as the follwing code
    printf("\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    printf("----------------------------------------------------------------------------------------------\n");

    //Print informations of each student
    for( int i=0; i< num_student; i++){
        printf("%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%0.2f\n",student[i].id, student[i].full_name,
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    };
    
    //Print output to a file
    FILE *f = fopen("Lists of Students.txt", "w");
    fprintf(f,"\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    fprintf(f,"----------------------------------------------------------------------------------------------\n");
    for( int i=0; i< num_student; i++){
        fprintf(f, "%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%0.2f\n",student[i].id, student[i].full_name,
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    }
    fclose(f);

    //Task 5
    high_point = 0;
    for (int i=0; i < num_student; i++){     //Find the highest GPA
        if (student[i].gpa > high_point){
            high_point = student[i].gpa;
            highest = i;
        }
    }
   
    low_point = 100;
    for (int i=0; i < num_student; i++){     //Find the lowest GPA
        if (student[i].gpa < low_point){
            low_point = student[i].gpa;
            lowest = i;
        }
    }
    hbp_point = 0;                           //Find the highest Basic Programming Grade
    for (int i=0; i < num_student; i++){
        if (student[i].basic > hbp_point){
            hbp_point = student[i].basic;
            hbp = i;  
            }
    }
    
    printf("\nThe Student has highest GPA is: %s %s\nGPA: %0.2f\n",student[highest].id, student[highest].full_name ,high_point);
    printf("\nThe Student has lowest GPA is: %s %s\nGPA: %0.2f\n",student[lowest].id, student[lowest].full_name ,low_point);
    printf("\nThe Student has highest Basic Programming Grade is: %s %s\nGRADE: %0.2f\n",student[hbp].id, student[hbp].full_name,hbp_point);
    
    //Task 6
    printf("\n%-15s%-15s%-15s%s\n", "StudentID","Full Name","Birthdate","The last word in the name");
    printf("------------------------------------------------------------------------\n");
    for (int i=0; i<num_student; i++){
        char word = letter(&student[i]);
        printf("%-15s%-15s%-15s%c\n", student[i].id, student[i].full_name, student[i].birth, word);
    }

    //Task 7
    time date[num_student];
    for (int i=0; i < num_student; i++){     //Split the date of birth to more detailed sections 
        date[i].day = nday(&student[i]);         
        date[i].month = nmonth(&student[i]);
        date[i].year = nyear(&student[i]);
    }
    
    int index =0;
    for (int i=0; i < num_student; i++){
        if(date[index].year < date[i].year || date[index].year == date[i].year){
            index = i;
        }
        else if(date[index].month < date[i].month || date[index].month == date[i].month){
            index = i;
        }
        else if(date[index].day < date[i].day || date[index].day == date[i].day){
            index = i;
        }
    }

    printf("The oldest student: %d", index);
    
    return 0;
}
