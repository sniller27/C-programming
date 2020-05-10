Array get_student_data(const char *file_name){

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

    int counter = 0;
    Array a;

    initArray(&a, 5); 

    while(fscanf(read_data, "%s %s %s %d %d %d %d", student_no, firstname, lastname, &phone, &grade1, &grade2, &grade3)!=EOF){

        int grades[3] = {grade1, grade2, grade3};
        insertArray(&a, student_no, firstname, lastname, phone, grades);

        counter++;
    }

    //close file connections
    fclose(read_data);
    return a;
}