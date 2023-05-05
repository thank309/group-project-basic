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
    