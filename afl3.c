#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// internal constants
// #include "constants/my_constants.h"

// internal structs
#include "structs/my_structs.h"
#include "structs/student.h"

// internal libraries
// #include "functions/print_write_functions.h"
#include "functions/my_functions.h"

int main(int argc,char *argv[])
{

    //creating filepointer for writing outputs to file
    FILE* output_file = fopen("output.txt", "w");

    //TASK 1

    //assigning data to Student structs
    struct Student students[10];
    
    printf("TASK 1 \n");
    printf("\n");

    get_student_data(10, "tekstfil", students);
    print_student_data(10, students);

    printf("\n");

    printf("TASK 2 \n");
    print_highest_grade_info(10, students);

    printf("\n");

    printf("TASK 3 \n");

    printf("Students with grades below avg. 2 grade: \n");
    printf("\n");

    print_value_below_avr_grade_info(10, students, 2);

    printf("\n");

    printf("TASK 4 \n");

    printf("Students with grades above avg. 2 grade: \n");
    printf("\n");
    
    print_value_above_avr_grade_info(10, students, 2);

    printf("\n");

    printf("TASK 5 \n");

    print_students_with_top_grade(10, students);

    printf("\n");

    printf("TASK 6 \n");

    printf("Average grade of all students: %-*.2f  \n", 20, print_avr_grade_students_total(10, students));

    printf("\n");

    printf("TASK 7 \n");

    printf("Info about all students with lastname Hansen (solely): \n");

    search_students_lastname(10, students, "Hansen");

    printf("\n");
    
    printf("TASK 8 \n");

    selectionsort_by_firstname(students, 10);
    print_student_data(10, students);

    printf("\n");

    // int result = strcmp("gog", "bil");
    // printf("strcmp(str1, str2) = %d\n", result);

    // if(strcmp("gog", "bil")){
    //     printf("last lowest");
    // }

    // int result2 = strcmp("bil", "gog");
    // printf("strcmp(str1, str2) = %d\n", result2);

    // int result3 = strcmp("bil", "bil");
    // printf("strcmp(str1, str2) = %d\n", result3);

    // int result4 = strcmp("bil", "bila");
    // printf("strcmp(str1, str2) = %d\n", result4);

    // print_write_string("\n", output_file);

    return 0;
}


