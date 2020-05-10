// kilde: https://stackoverflow.com/questions/3536153/c-dynamically-growing-array

//intializes student array with memory allocated, spaces used and size
void init_student_array(Student_Array *a, int initialSize) {
    a->array = (struct Student *)malloc(initialSize * sizeof(struct Student));
    a->used = 0;
    a->size = initialSize;
}

// inserts student into array and updates array size if necessary. All student data is passed as parameters.
void insert_student_array(Student_Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int_Array *grades) {

    // extends array if more space is needed
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    }

    // assigns data to array with highest index (strings)
    strcpy(a->array[a->used].student_no, stud_id);
    strcpy(a->array[a->used].firstname, firstname);
    strcpy(a->array[a->used].lastname, lastname);

    // assigns data to array with highest index (integers)
    a->array[a->used].phone = phone;

    // initializes dynamic int array for grades
    init_int_Array(&a->array[a->used].grades, INITIAL_SIZE_INT_ARRAY);

    // assigns grades to student in array by iteration
    for (int i = 0; i < grades->used; i++)
    {
        insert_int_Array(&a->array[a->used].grades, grades->array[i]);
    }

    // increment for used spot
    a->used++;
}

// free student memory
void free_student_array(Student_Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

// add grade to student (by inserting in dynamic grades array)
void add_grade(Student_Array *a, int index, int grade) {

    insert_int_Array(&a->array[index].grades, grade);

}