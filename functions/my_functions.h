// void scan_values_from_file(int size, const char *file_name, char date_array[][size], float *value_array){

//     float weather_value = 0;

//     char file_path[80],
//         header_1[255],
//         header_2[255],
//         date[255];

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
//     fscanf(read_data, "%s %s", header_1, header_2);

//     int counter = 0;

//     while(fscanf(read_data, "%s %f", date, &weather_value)!=EOF){

//         strcpy(date_array[counter], date);

//         value_array[counter]=weather_value;

//         // printf("looping \n"); 
//         // printf("val: %-*.2f \n", 20, value_array[counter]);
//         printf("%s \n", date);

//         counter++;
//     }

//     //close file connections
//     fclose(read_data);
    
// }

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

        // print check
        printf("student no: %s \n", student_no);
        printf("first name: %s \n", firstname);
        printf("last name: %s \n", lastname);
        printf("phone: %d \n", phone);

        printf("grade1: %d \n", students[counter].grades[0]);
        printf("grade2: %d \n", students[counter].grades[1]);
        printf("grade3: %d \n", students[counter].grades[2]);

        printf("\n");
        printf("\n");

        counter++;
    }

    // strcpy(students[0].firstname, "Dickbro");
    // printf("dick joe: %s \n", students[0].firstname);

    //close file connections
    fclose(read_data);
    
}