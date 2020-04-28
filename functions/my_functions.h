void scan_values_from_file(int size, const char *file_name, char date_array[][size], float *value_array){

    float weather_value = 0;

    char file_path[80],
        header_1[255],
        header_2[255],
        date[255];

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
    fscanf(read_data, "%s %s", header_1, header_2);

    int counter = 0;

    while(fscanf(read_data, "%s %f", date, &weather_value)!=EOF){

        strcpy(date_array[counter], date);

        value_array[counter]=weather_value;

        // printf("looping \n"); 
        // printf("val: %-*.2f \n", 20, value_array[counter]);
        printf("%s \n", date);

        counter++;
    }

    //close file connections
    fclose(read_data);
    
}
