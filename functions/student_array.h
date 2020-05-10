// kilde: https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
typedef struct {
    struct Student *array;
    int used;
    int size;
} Student_Array;

void init_student_array(Student_Array *a, int initialSize) {
    a->array = (struct Student *)malloc(initialSize * sizeof(struct Student));
    a->used = 0;
    a->size = initialSize;
}

void insert_student_array(Student_Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int_Array *grades) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    }

    strcpy(a->array[a->used].student_no, stud_id);
    strcpy(a->array[a->used].firstname, firstname);
    strcpy(a->array[a->used].lastname, lastname);

    a->array[a->used].phone = phone;

    init_int_Array(&a->array[a->used].grades, INITIAL_SIZE_INT_ARRAY);

    insert_int_Array(&a->array[a->used].grades, grades->array[0]);
    insert_int_Array(&a->array[a->used].grades, grades->array[1]);
    insert_int_Array(&a->array[a->used].grades, grades->array[2]);

    a->used++;
}

void free_student_array(Student_Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void add_grade(Student_Array *a, int index, int grade) {

    insert_int_Array(&a->array[index].grades, grade);

}