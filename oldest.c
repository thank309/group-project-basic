#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "oldest.h"

void findoldest(students* student, int size){
  int old_year = 9999, old_month = 13, old_day = 32;
  int index;
  for (int i=0; i < size; i++){
    int day = atoi(strtok(student[i].birth, "/"));
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
  