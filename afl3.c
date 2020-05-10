#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// internal constants
// #include "constants/my_constants.h"

// internal structs
// int and student structs
#include "structs/my_structs.h"
#include "structs/student.h"

// internal libraries
//int and student arrays (dynamic)
#include "functions/int_array.h"
#include "functions/student_array.h"

//student functions
#include "functions/print_write_functions.h"
#include "functions/student_read_file.h"
#include "functions/student_print.h"
#include "functions/student_calc.h"
#include "functions/student_search.h"
#include "functions/student_sort.h"
#include "functions/student_manipulations.h"

int main(int argc,char *argv[])
{

    //creating filepointer for writing outputs to file
    FILE* output_file = fopen("output.txt", "w");

    Array a;
    initArray(&a, 5);
    
    a = get_student_data("tekstfil");
    
    //TASK 1
    print_write_string("TASK 1 \n", output_file);

    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 2
    print_write_string("TASK 2 \n", output_file);

    int array_size, highest_grades_indexes[10];
    highest_grades_info(a.used, a.array, highest_grades_indexes, &array_size);

    print_write_string("Student(s) with highest average grade: \n", output_file);
    print_student_data_index(array_size, a.array, highest_grades_indexes, output_file);

    print_write_string("\n", output_file);

    //TASK 3
    print_write_string("TASK 3 \n", output_file);

    int array_size2, low_grades_indexes[10];
    value_below_avr_grade_info(a.used, a.array, low_grades_indexes, &array_size2, 2);

    print_write_string("Students with grades below avg. 2 grade: \n", output_file);
    print_student_data_index(array_size2, a.array, low_grades_indexes, output_file);

    print_write_string("\n", output_file);

    //TASK 4
    print_write_string("TASK 4 \n", output_file);

    print_write_string("\n", output_file);
    
    int number_of_students = value_above_avr_grade_info(a.used, a.array, 2);

    print_write_int("Number of students with avg. grade above avg. 2 grade: %d \n", number_of_students, output_file);

    print_write_string("\n", output_file);

    //TASK 5
    print_write_string("TASK 5 \n", output_file);

    print_write_string("Students with at least one maximum grade: \n", output_file);
    print_students_with_top_grade(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 6
    print_write_string("TASK 6 \n", output_file);

    print_write_float("Average grade of all students: %-*.2f  \n", avr_grade_students_total(a.used, a.array), output_file);

    print_write_string("\n", output_file);

    //TASK 7
    print_write_string("TASK 7 \n", output_file);

    print_write_string("Info about all students with lastname Hansen (solely): \n", output_file);

    search_students_lastname(a.used, a.array, "Hansen");

    print_write_string("\n", output_file);
    
    //TASK 8
    print_write_string("TASK 8 \n", output_file);

    selectionsort_by_firstname(a.array, a.used);
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 9
    print_write_string("TASK 9 \n", output_file);

    selectionsort_by_avrgrade(a.array, a.used);
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 10
    print_write_string("TASK 10 \n", output_file);

    selectionsort_by_firstname(a.array, a.used);

    int grades[3] = {2, 4, 10};
    insert_student_by_name(&a, "S11", "Erik", "Eriksen", 34343434, grades);
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 11
    print_write_string("TASK 11 \n", output_file);

    remove_student_by_id(&a, "S5");
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 12
    print_write_string("TASK 12 \n", output_file);

    for (int i = 0; i < a.used; i++)
    {
        add_grade(&a, i, 7);
    }

    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    //TASK 13
    print_write_string("TASK 13 \n", output_file);

    print_write_string("\n", output_file);
    print_write_string("De studerende skulle gerne blive laest i opgave 1 med et array af pointere, studerende structs og dynamisk lagerallokering. \n", output_file);
    


    return 0;
}


