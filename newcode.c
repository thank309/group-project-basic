#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct students{                //DATA STORES INFORMATIONS OF A STUDENT 
    char id[20];                                           
    char first_name[20];
    char last_name[20];
    char birth[20];
    float al;
    float cal;
    float basic;
    float gpa;
};

struct time{                    //DATA STORES THE DATE OF BIRTH OF A STUDENT
    int day;
    int month;
    int year;
};

int nday(struct students *p){       //Convert the string of day to integer
    char nday[20];
    strncpy(nday, p->birth, 2);
    return atoi(nday);
    }


int nmonth(struct students *p){       //Convert the string of month to integer
    char nmonth[20];
    strncpy(nmonth, p->birth, 5);
    strnset(nmonth, '0', 3);

    return atoi(nmonth);
    }

int nyear(struct students *p){       //Convert the string of year to integer
    char nyear[20];
    strrev(p->birth);
    strncat(nyear, p->birth, 4);
    strrev(nyear);

    return atoi(nyear);
}


int main(){
    int num_student;
    float highest, lowest, hbp; 
    do{                       //A LOOP ENSURES THAT USERS HAVE TO INPUT A NUMBER SMALLER THAN 1000
        printf("\nThe numbers of students(Max 1000) is: ");     
        scanf("%d", &num_student);
        if(num_student>1000){
            printf("Outta range!!!\nPlease try again with a number smaller than 1000");
            
        }; 
    }while(num_student>1000);
    struct students student[num_student];
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
        strcat(student[i].last_name," ");     //This merges a space to the end of str 
    }

    //Print the header as the follwing code
    printf("\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    printf("----------------------------------------------------------------------------------------------\n");
    
    //Print informations of each student
    for( int i=0; i< num_student; i++){
        printf("%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%0.2f\n",student[i].id, strcat(student[i].last_name, student[i].first_name),
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    };
    
    //Print output to a file
    FILE *f = fopen("Lists of Students.txt", "w");
    fprintf(f,"\n%-15s%-15s%-15s%-12s%-12s%-20s%s\n", "StudentID","Full Name","Birthdate","Algebra","Calculus","Basic Programming","GPA");
    fprintf(f,"----------------------------------------------------------------------------------------------\n");
    for( int i=0; i< num_student; i++){
        fprintf(f, "%-15s%-15s%-15s%-12.2f%-12.2f%-20.2f%0.2f\n",student[i].id, strcat(student[i].last_name, student[i].first_name),
        student[i].birth, student[i].al, student[i].cal, student[i].basic, student[i].gpa);
    }
    fclose(f);


    highest = 0;    
    for (int i=0; i < num_student; i++){     //Find the highest GPA
        if (student[i].gpa > highest){
            highest = student[i].gpa;
        }
    }
   
    lowest = 100;
    for (int i=0; i < num_student; i++){     //Find the lowest GPA
        if (student[i].gpa < lowest){
            lowest = student[i].gpa ;
        }
    }
    hbp = 0;                                 //Find the highest Basic Programming Grade
    for (int i=0; i < num_student; i++){
        if (student[i].basic > hbp){
            hbp = student[i].basic;  
            }
    }
    
    printf("\nThe Student has highest GPA is: %0.2f", highest);
    printf("\nThe Student has lowest GPA is: %0.2f", lowest);
    printf("\nThe Student has highest Basic Programming is: %0.2f", hbp);

    struct time date[num_student];
    for (int i=0; i < num_student; i++){     //Split the date of birth to more detailed sections 
        date[i].day = nday(&student[i]);         
        date[i].month = nmonth(&student[i]);
        date[i].year = nyear(&student[i]);
    }
    
    
    return 0;
}
