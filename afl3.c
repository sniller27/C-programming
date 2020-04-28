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

    // print_write_string("\n", output_file);

    return 0;
}


