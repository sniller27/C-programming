typedef struct {
    struct Student *array;
    int used;
    int size;
} Array;

void initArray(Array *a, int initialSize) {
    a->array = (struct Student *)malloc(initialSize * sizeof(struct Student));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int grades[]) {
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size 
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    }

    strcpy(a->array[a->used].student_no, stud_id);
    strcpy(a->array[a->used].firstname, firstname);
    strcpy(a->array[a->used].lastname, lastname);

    a->array[a->used].phone = phone;

    init_int_Array(&a->array[a->used].grades, 5);

    insert_int_Array(&a->array[a->used].grades, grades[0]);
    insert_int_Array(&a->array[a->used].grades, grades[1]);
    insert_int_Array(&a->array[a->used].grades, grades[2]);

    a->array[a->used].no_of_grades = 3;

    a->used++;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void add_grade(Array *a, int index, int grade) {

    insert_int_Array(&a->array[index].grades, grade);

    a->array[a->used].no_of_grades = a->array->grades.used;

}