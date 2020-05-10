

void init_int_Array(int_Array *a, int initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insert_int_Array(int_Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void free_int_Array(int_Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}











// void get_student_data(int size, const char *file_name, struct Student students[]){

//     float weather_value = 0;

//     int phone, grade1, grade2, grade3;

//     char file_path[80],
//         // header_1[255],
//         // header_2[255],
//         student_no[50],
//         firstname[255],
//         // phone[20],
//         lastname[255]
        
        
        
//         ;

//     strcpy(file_path, "data/");
//     strcat(file_path, file_name);
//     strcat(file_path, ".txt");

//     //instatiate filepointer instance (one for reading and one for writing)
//     FILE* read_data = fopen(file_path,"r");

//     // error checking filepointer
//     if (read_data==NULL) 
//     { 
//         printf("no such file."); 
//     }

//     //reading headers from 1st line in file and save them to variables
//     // fscanf(read_data, "%s %s", header_1, header_2);

//     int counter = 0;

//     while(fscanf(read_data, "%s %s %s %d %d %d %d", student_no, firstname, lastname, &phone, &grade1, &grade2, &grade3)!=EOF){

//         //assign data to struct
//         strcpy(students[counter].student_no, student_no);
//         strcpy(students[counter].firstname, firstname);
//         strcpy(students[counter].lastname, lastname);

//         students[counter].phone = phone;

//         students[counter].grades[0] = grade1;
//         students[counter].grades[1] = grade2;
//         students[counter].grades[2] = grade3;

//         students[counter].no_of_grades = 3;

//         counter++;
//     }

//     // strcpy(students[0].firstname, "Dickbro");
//     // printf("dick joe: %s \n", students[0].firstname);

//     //close file connections
//     fclose(read_data);
    
// }







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

    // a->array[a->used].grades[0] = grades[0];
    // a->array[a->used].grades[1] = grades[1];
    // a->array[a->used].grades[2] = grades[2];

    a->array[a->used].no_of_grades = 3;

    // a->array[a->used] = element;

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

    










Array get_student_data2(const char *file_name){

    int phone, grade1, grade2, grade3;

    char file_path[80],
        student_no[50],
        firstname[255],
        lastname[255]
        ;

    strcpy(file_path, "data/");
    strcat(file_path, file_name);
    strcat(file_path, ".txt");

    //instatiate filepointer instance (one for reading and one for writing)
    FILE* read_data = fopen(file_path,"r");

    // error checking filepointer
    if (read_data==NULL) 
    { 
        printf("no such file."); 
    }

    //reading headers from 1st line in file and save them to variables
    // fscanf(read_data, "%s %s", header_1, header_2);

    int counter = 0;
    Array a;

    initArray(&a, 5); 

    while(fscanf(read_data, "%s %s %s %d %d %d %d", student_no, firstname, lastname, &phone, &grade1, &grade2, &grade3)!=EOF){

        int grades[3] = {grade1, grade2, grade3};
        // insertArray(&a, "S11", "Bob", "Jensen", 34526623, grades);  // automatically resizes as necessary
        insertArray(&a, student_no, firstname, lastname, phone, grades);

        // students[counter].no_of_grades = 3;

        // printf("et index: %s\n", a.array[counter].firstname);  // print 10th element
        // printf("et index: %s\n", a.array[counter].lastname);  // print 10th element
        // printf("brugte: %d\n", a.used);  // print number of elements
        // printf("size: %d\n", a.size);  // print number of elements
    
        // printf("used: %d\n", a.array[counter].grades.used);
        // printf("size: %d\n", a.array[counter].grades.size);
        // printf("grade: %d\n", a.array[counter].grades.array[0]);
        // printf("grade: %d\n", a.array[counter].grades.array[1]);
        // printf("grade: %d\n", a.array[counter].grades.array[2]);

        // printf("\n");

        counter++;
    }

    // strcpy(students[0].firstname, "Dickbro");
    // printf("dick joe: %s \n", students[0].firstname);
    // printf("%s \n", a.array[9].firstname);

    //close file connections
    fclose(read_data);
    return a;
}






void print_student_data(int size, struct Student students[]){

    for (int i = 0; i < size; i++)
    {
        printf("student no: %s \n", students[i].student_no);
        printf("first name: %s \n", students[i].firstname);
        printf("last name: %s \n", students[i].lastname);
        printf("phone: %d \n", students[i].phone);

        for (int j = 0; j < students[i].grades.used; j++)
        {
            printf("grade: %d \n", students[i].grades.array[j]);
        }

        // printf("number of grades: %d \n", students[i].grades.used);

        // printf("grade1: %d \n", students[i].grades.array[0]);
        // printf("grade2: %d \n", students[i].grades.array[1]);
        // printf("grade3: %d \n", students[i].grades.array[2]);

        printf("\n");
    }
    
}

void print_student_data_index(int size, struct Student students[], int indexes[], FILE* w_file){

    for (int i = 0; i < size; i++)
    {
        print_write_string_arg("student no: %s \n", students[indexes[i]].student_no, w_file);
        print_write_string_arg("first name: %s \n", students[indexes[i]].firstname, w_file);
        print_write_string_arg("last name: %s \n", students[indexes[i]].lastname, w_file);
        print_write_int("phone: %d \n", students[indexes[i]].phone, w_file);

        for (int j = 0; j < students[indexes[i]].grades.used; j++)
        {
            print_write_int("grade: %d \n", students[indexes[i]].grades.array[j], w_file);
        }

        print_write_string("\n", w_file);
    }
    
}

float calc_avg_grade(struct Student students){

    float total_grade = 0, grade_avr;

    for (int j = 0; j < students.no_of_grades; j++)
    {
        total_grade += students.grades.array[j];
    }

    grade_avr = total_grade/students.no_of_grades;

    students.avr_grade = grade_avr;
    
    return grade_avr;
}


void print_highest_grade_info(int size, struct Student students[], int highest_grade_indexes[size], int *array_size){

    int index_counter = 0;

    float highest_grade_avr, 
    grade_avr;

    for (int i = 0; i < size; i++)
    {
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        if(i==0){
            highest_grade_avr = grade_avr;
            highest_grade_indexes[index_counter] = i;
            index_counter++;
        }

        if(grade_avr > highest_grade_avr){
            highest_grade_avr = grade_avr;
            //empty array indexes

            //new index counter
            index_counter = 0;

            //new max value
            highest_grade_indexes[index_counter] = i;

            index_counter++;
        } else if(grade_avr == highest_grade_avr){
            //add to indexes
            highest_grade_indexes[index_counter] = i;
            index_counter++;
        }

    }

    *array_size = index_counter;

}


void print_value_below_avr_grade_info(int size, struct Student students[], int low_grade_indexes[size], int *array_size, int value){

    int index_counter = 0;
    float grade_avr;

    for (int i = 0; i < size; i++)
    {
    
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        if(grade_avr < value){
            //print_info
            // print_student_data(1, &students[i]);
            low_grade_indexes[index_counter] = i;
            index_counter++;
        }

    }

    *array_size = index_counter;

}

int print_value_above_avr_grade_info(int size, struct Student students[], int value){

    float grade_avr;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        if(grade_avr > value){
            count ++;
        }

    }

    return count;
}


void print_students_with_top_grade(int size, struct Student students[]){

    int grade_occurence = 0;

    for (int i = 0; i < size; i++)
    {
        grade_occurence = 0;

        for (int j = 0; j < students[i].no_of_grades; j++)
        {
            if(students[i].grades.array[j] == 12){
                grade_occurence++;
            }
        }

        if(grade_occurence > 0) {
            print_student_data(1, &students[i]);
            printf("%s has %d max grades in total \n", students[i].firstname, grade_occurence);
            printf("\n");
        }

    }

}

float print_avr_grade_students_total(int size, struct Student students[]){

    float students_avr = 0;

    for (int i = 0; i < size; i++)
    {
        students_avr += students[i].avr_grade;
    }

    return students_avr/size;

}

void search_students_lastname(int size, struct Student students[], char lastname[50]){

    for (int i = 0; i < size; i++)
    {
        if(strcmp(students[i].lastname, "Hansen") == 0) {
            print_student_data(1, &students[i]);
        }
    }

}

void selectionsort_by_firstname(struct Student a[],int n) {

        int pos;
        struct Student gem;

        for(int i=0; i<n-1; i++) {

            pos=i;

            //finding lowest index
            for(int j=i+1;j<n;j++){

                if(0 < strcmp(a[pos].firstname, a[j].firstname)){
                    pos=j;
                }

            }

            //swapping indexes
            if(pos!=i){

                struct Student tmp = a[i];
                a[i] = a[pos];
                a[pos] = tmp;

            }
        }
}

void selectionsort_by_avrgrade(struct Student a[],int n) {

        int pos;
        struct Student gem;

        for(int i=0; i<n-1; i++) {

            pos=i;

            //finding lowest index
            for(int j=i+1;j<n;j++){

                if(a[pos].avr_grade > a[j].avr_grade){
                    pos=j;
                }

            }

            //swapping indexes
            if(pos!=i){

                struct Student tmp = a[i];
                a[i] = a[pos];
                a[pos] = tmp;

            }
        }
}


void insert_student_by_name(Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int grades[]) {


    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    }

    for (int i = 0; i < a->used; i++)
    {
        // printf("eriks: %d \n", strcmp(firstname, "Erik"));
        // printf("ene: %s \n", firstname);
        // printf("anden: %s \n", a->array[i].firstname);

        // printf("her: %d \n", strcmp(firstname, a->array[i].firstname));

        //Tager ikke hensyn til andre med samme navn og sorterer ikke efter efternavn!
        if (strcmp(firstname, a->array[i].firstname) == -1)
        {
            // printf("yes \n");
            for (int j = a->used; j > i; j--)
            {
                // printf("flyt: %s \n", a->array[j].firstname);
                a->array[j] = a->array[j-1];
            }

            // insertArray(&a, stud_id, firstname, lastname, phone, grades);

            strcpy(a->array[i].student_no, stud_id);
            strcpy(a->array[i].firstname, firstname);
            strcpy(a->array[i].lastname, lastname);

            a->array[i].phone = phone;

            for (int j = 0; j < a->array[i].grades.used; j++)
            {
                a->array[i].grades.array[j] = grades[j];
            }
            
            a->array[i].no_of_grades = a->array[i].grades.used;

            a->used++;
            
            break;
        }
        
    }

}

void remove_student_by_id(Array *a, char stud_id[50]) {

    for (int i = 0; i < a->used; i++)
    {

        if (strcmp(stud_id, a->array[i].student_no) == 0)
        {
            // printf("Fjern: %s \n", a->array[i].firstname);

            // printf("\n");

            //remove student
            for (int j = i; j < a->used-1; j++)
            {
                a->array[j] = a->array[j+1];
            }

            // free(a->array[10]);
            
            a->used--;
            
            break;
        }
        
    }

}
