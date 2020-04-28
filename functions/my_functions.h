
void get_student_data(int size, const char *file_name, struct Student students[]){

    float weather_value = 0;

    int phone, grade1, grade2, grade3;

    char file_path[80],
        // header_1[255],
        // header_2[255],
        student_no[50],
        firstname[255],
        // phone[20],
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

    while(fscanf(read_data, "%s %s %s %d %d %d %d", student_no, firstname, lastname, &phone, &grade1, &grade2, &grade3)!=EOF){

        //assign data to struct
        strcpy(students[counter].student_no, student_no);
        strcpy(students[counter].firstname, firstname);
        strcpy(students[counter].lastname, lastname);

        students[counter].phone = phone;

        students[counter].grades[0] = grade1;
        students[counter].grades[1] = grade2;
        students[counter].grades[2] = grade3;

        students[counter].no_of_grades = 3;

        counter++;
    }

    // strcpy(students[0].firstname, "Dickbro");
    // printf("dick joe: %s \n", students[0].firstname);

    //close file connections
    fclose(read_data);
    
}

void print_student_data(int size, struct Student students[]){

    for (int i = 0; i < size; i++)
    {
        printf("student no: %s \n", students[i].student_no);
        printf("first name: %s \n", students[i].firstname);
        printf("last name: %s \n", students[i].lastname);
        printf("phone: %d \n", students[i].phone);

        printf("grade1: %d \n", students[i].grades[0]);
        printf("grade2: %d \n", students[i].grades[1]);
        printf("grade3: %d \n", students[i].grades[2]);

        printf("\n");
    }
    
}


void print_highest_grade_info(int size, struct Student students[]){

    int highest_grade_indexes[size];
    int index_counter = 0;

    float highest_grade_avr;

    float total_grade;
    float grade_avr;

    for (int i = 0; i < size; i++)
    {
        total_grade = 0;

        // printf("%d  \n", students[i].grades[0]);
        // printf("%d  \n", students[i].grades[1]);
        // printf("%d  \n", students[i].grades[2]);

        // printf("\n");

        // printf("%d  \n", sizeof(students[i].grades));

        // printf("HEELLO");

        for (int j = 0; j < students[i].no_of_grades; j++)
        {
            // printf("%d  \n", students[i].grades[j]);
            total_grade += students[i].grades[j];
        }

        // printf("total: %-*.2f  \n", 20, total_grade);
        grade_avr = total_grade/students[i].no_of_grades;
        // printf("index: %d  \n", i);
        // printf("avr: %-*.2f  \n", 20, grade_avr);

        // printf("%-*.2f  \n", 20, grade_avr);
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

    printf("\n");

    printf("Student(s) highest average grade: \n");

    //shoule probably be moved somehow
    for (int i = 0; i < index_counter; i++)
    {
        printf("student no: %s \n", students[highest_grade_indexes[i]].student_no);
        printf("first name: %s \n", students[highest_grade_indexes[i]].firstname);
        printf("last name: %s \n", students[highest_grade_indexes[i]].lastname);
        printf("phone: %d \n", students[highest_grade_indexes[i]].phone);

        printf("grade1: %d \n", students[highest_grade_indexes[i]].grades[0]);
        printf("grade2: %d \n", students[highest_grade_indexes[i]].grades[1]);
        printf("grade3: %d \n", students[highest_grade_indexes[i]].grades[2]);

        printf("\n");
    }

}


void print_value_below_avr_grade_info(int size, struct Student students[], int value){

    int highest_grade_indexes[size];
    int index_counter = 0;

    float highest_grade_avr;

    float total_grade;
    float grade_avr;

    for (int i = 0; i < size; i++)
    {
        total_grade = 0;

        for (int j = 0; j < students[i].no_of_grades; j++)
        {
            // printf("%d  \n", students[i].grades[j]);
            total_grade += students[i].grades[j];
        }

        // printf("total: %-*.2f  \n", 20, total_grade);
        grade_avr = total_grade/students[i].no_of_grades;

        if(grade_avr < value){
            //print_info
            print_student_data(1, &students[i]);
        }

    }

}

void print_value_above_avr_grade_info(int size, struct Student students[], int value){

    int highest_grade_indexes[size];
    int index_counter = 0;

    float highest_grade_avr;

    float total_grade;
    float grade_avr;

    for (int i = 0; i < size; i++)
    {
        total_grade = 0;

        for (int j = 0; j < students[i].no_of_grades; j++)
        {
            // printf("%d  \n", students[i].grades[j]);
            total_grade += students[i].grades[j];
        }

        // printf("total: %-*.2f  \n", 20, total_grade);
        grade_avr = total_grade/students[i].no_of_grades;

        if(grade_avr > value){
            //print_info
            print_student_data(1, &students[i]);
        }

    }

}


void print_students_with_top_grade(int size, struct Student students[]){

    int grade_occurence = 0;

    for (int i = 0; i < size; i++)
    {
        grade_occurence = 0;

        for (int j = 0; j < students[i].no_of_grades; j++)
        {
            if(students[i].grades[j] == 12){
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
