#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// internal constants
// #include "constants/my_constants.h"

// internal structs
#include "structs/my_structs.h"
#include "structs/student.h"

// internal libraries
#include "functions/print_write_functions.h"
#include "functions/my_functions.h"

int main(int argc,char *argv[])
{

    //creating filepointer for writing outputs to file
    FILE* output_file = fopen("output.txt", "w");

    //TASK 1

    //assigning data to Student structs
    // struct Student students[10];

    Array a;
    initArray(&a, 5);
    
    a = get_student_data2("tekstfil");
    
    print_write_string("TASK 1 \n", output_file);

    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    // get_student_data(10, "tekstfil", students);

    // print_student_data(10, students);

    print_write_string("\n", output_file);

    print_write_string("TASK 2 \n", output_file);

    int array_size, highest_grades_indexes[10];
    print_highest_grade_info(a.used, a.array, highest_grades_indexes, &array_size);

    print_write_string("Student(s) with highest average grade: \n", output_file);
    print_student_data_index(array_size, a.array, highest_grades_indexes);

    print_write_string("\n", output_file);

    print_write_string("TASK 3 \n", output_file);

    int array_size2, low_grades_indexes[10];
    print_value_below_avr_grade_info(a.used, a.array, low_grades_indexes, &array_size2, 2);

    print_write_string("Students with grades below avg. 2 grade: \n", output_file);
    print_student_data_index(array_size2, a.array, low_grades_indexes);

    print_write_string("\n", output_file);

    print_write_string("TASK 4 \n", output_file);

    print_write_string("\n", output_file);
    
    int number_of_students = print_value_above_avr_grade_info(a.used, a.array, 2);

    print_write_int("Number of students with avg. grade above avg. 2 grade: %d \n", number_of_students, output_file);

    print_write_string("\n", output_file);

    print_write_string("TASK 5 \n", output_file);

    print_write_string("Students with at least one maximum grade: \n", output_file);
    print_students_with_top_grade(a.used, a.array);

    print_write_string("\n", output_file);

    print_write_string("TASK 6 \n", output_file);

    print_write_float("Average grade of all students: %-*.2f  \n", print_avr_grade_students_total(a.used, a.array), output_file);

    print_write_string("\n", output_file);

    print_write_string("TASK 7 \n", output_file);

    print_write_string("Info about all students with lastname Hansen (solely): \n", output_file);

    search_students_lastname(a.used, a.array, "Hansen");

    print_write_string("\n", output_file);
    
    print_write_string("TASK 8 \n", output_file);

    selectionsort_by_firstname(a.array, a.used);
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    print_write_string("TASK 9 \n", output_file);

    selectionsort_by_avrgrade(a.array, a.used);
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

    print_write_string("TASK 10 \n", output_file);

    


    // typedef struct {
    // struct Student *array;
    // int used;
    // int size;
    // } Array;

    // void initArray(Array *a, int initialSize) {
    // a->array = (struct Student *)malloc(initialSize * sizeof(struct Student));
    // a->used = 0;
    // a->size = initialSize;
    // }

    // void insertArray(Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int grades[]) {
    // // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // // Therefore a->used can go up to a->size 
    // if (a->used == a->size) {
    //     a->size *= 2;
    //     a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    // }

    // strcpy(a->array[a->used].student_no, stud_id);
    // strcpy(a->array[a->used].firstname, firstname);
    // strcpy(a->array[a->used].lastname, lastname);

    // a->array[a->used].phone = phone;

    // a->array[a->used].grades[0] = grades[0];
    // a->array[a->used].grades[1] = grades[1];
    // a->array[a->used].grades[2] = grades[2];

    // // a->array[a->used] = element;

    // a->used++;
    // }

    // void freeArray(Array *a) {
    // free(a->array);
    // a->array = NULL;
    // a->used = a->size = 0;
    // }


     // initially 5 elements
    // int grades[3] = {7,7,12};
    // for (int i = 0; i < 20; i++){
    //     insertArray(&a, "S11", "Bob", "Jensen", 34526623, grades);  // automatically resizes as necessary
    // }
    
    // printf("et index: %s\n", a.array[9].student_no);  // print 10th element
    // printf("et index: %s\n", a.array[9].firstname);  // print 10th element
    // printf("brugte: %d\n", a.used);  // print number of elements
    // printf("size: %d\n", a.size);  // print number of elements
    // freeArray(&a);

    // Array a;
    // initArray(&a, 5); 
    
    // a = get_student_data2("tekstfil");

    print_write_string("\n", output_file);

    selectionsort_by_firstname(a.array, a.used);



    // print_student_data(a.used, a.array);

    // print_student_data(10, students);
    // printf("back \n");
    // printf("%s \n", a.array[5].firstname);
    // printf("%s \n", a.array[7].firstname);

    // int grades[3] = {12, 12, 10};
    // insertArray(&a, "S13", "Coco", "Bandicoot", 25445525, grades);
    // printf("%s \n", a.array[10].firstname);
    // printf("%d \n", a.used);
    // printf("%d \n", a.size);

    int grades[3] = {2, 4, 10};
    insert_student_by_name(&a, "S11", "Erik", "Eriksen", 34343434, grades);
    print_student_data(a.used, a.array);

    print_write_string("\n", output_file);

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


    print_write_string("TASK 11 \n", output_file);

    remove_student_by_id(&a, "S5");
    print_student_data(a.used, a.array);

    //Susanne er desværre stadig på samme adresse (selvom felter og størrelse på array er blevet ændret)
    // printf("se: %s \n", a.array[9].firstname);
    // printf("se: %s \n", a.array[10].firstname);

    print_write_string("\n", output_file);

    print_write_string("TASK 12 \n", output_file);

    for (int i = 0; i < a.used; i++)
    {
        add_grade(&a, i, 7);
    }

    print_student_data(a.used, a.array);
    // int_Array b;

    // init_int_Array(&b, 5);  // initially 5 elements
    // for (int i = 0; i < 100; i++) {
    //     insert_int_Array(&b, i);  // automatically resizes as necessary
    // }
    // printf("%d\n", b.array[9]);  // print 10th element
    // printf("%d\n", b.used);  // print number of elements
    // freeArray(&b);

    print_write_string("\n", output_file);

    print_write_string("TASK 13 \n", output_file);

    print_write_string("\n", output_file);


    return 0;
}


