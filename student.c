#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
void print_the_oldest(students* student, int total_student) {
    int oldest_index = -1;
    int oldest_year = 9999;
    int oldest_month = 13;
    int oldest_day = 32;

    for (int i = 0; i < total_student; i++) {
    	//tach date dd/mm/yyyy
        char tmp[11];
        strncpy(tmp, student[i].birth, 10);
        tmp[10] = '\0';
        int day = atoi(strtok(tmp, "/"));
        int month = atoi(strtok(NULL, "/"));
        int year = atoi(strtok(NULL, "/"));
        //dieu kien 
        if (year < oldest_year || (year == oldest_year && month < oldest_month) || (year == oldest_year && month == oldest_month && day < oldest_day)) {
            oldest_index = i;
            oldest_year = year;
            oldest_month = month;
            oldest_day = day;
        }
    }
    // in ra ket qua 
    if (oldest_index != -1) {
        printf("Oldest student:\n");
        printf("ID: %s\n", student[oldest_index].id);
        printf("Full name: %s\n", student[oldest_index].full_name);
        printf("Birthdate: %s\n", student[oldest_index].birth);
    } else {
        printf("No students found.\n");
    }
}
