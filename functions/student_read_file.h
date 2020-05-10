// Function reads data from file, adds it to a student array and returns the array
// expects a filename as parameter
Student_Array get_student_data(const char *file_name){

    // declare variables for filereading
    int phone, grade1, grade2, grade3;

    char file_path[80],
        student_no[50],
        firstname[255],
        lastname[255];

    // concatenation of filepath
    strcpy(file_path, "data/");
    strcat(file_path, file_name);
    strcat(file_path, ".txt");

    //instatiates filepointer for reading from file
    FILE* read_data = fopen(file_path,"r");

    // error checking filepointer
    if (read_data==NULL) 
    { 
        printf("no such file."); 
    }

    int counter = 0;
    Student_Array a;

    // initializes dynamic student array before insertion
    init_student_array(&a, INITIAL_SIZE_STUDENT_ARRAY); 

    // inserts into student array by looping through fscanf function with filepointer
    while(fscanf(read_data, "%s %s %s %d %d %d %d", student_no, firstname, lastname, &phone, &grade1, &grade2, &grade3)!=EOF){

        // instantiates grades array and assigns grades to array (this ensures that the number of elements in the array is known)
        int_Array grades;
        init_int_Array(&grades, INITIAL_SIZE_INT_ARRAY);

        insert_int_Array(&grades, grade1);
        insert_int_Array(&grades, grade2);
        insert_int_Array(&grades, grade3);

        // insertion in student array
        insert_student_array(&a, student_no, firstname, lastname, phone, &grades);

        counter++;
    }

    //close file connection
    fclose(read_data);
    return a;
}