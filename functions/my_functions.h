void scan_values_from_file(float *array, int size, char *file_name){

    float weather_value = 0;

    char header_1[255],
        header_2[255],
        date[255];

    char file_path[80];
    strcpy(file_path, "data/");
    strcat(file_path, file_name);
    strcat(file_path, ".txt");

    //instatiate filepointer instance (one for reading and one for writing)
    FILE* read_data = fopen(file_path,"r");

    // error checking filepointers
    if (read_data==NULL) 
    { 
        printf("no such file."); 
        // return 0; 
    }

    //reading headers from 1st line in file and save them to variables
    fscanf(read_data, "%s %s", header_1, header_2);
    // printf("%-*s", 20, header_1);
    // printf("%-*s \n", 20, header_2);

    // printf("Gennemsnitstemperatur: \n");
    int counter = 0;

    while(fscanf(read_data, "%s %f", date, &weather_value)!=EOF){
        // printf("%-*s", 20, date);
        // printf("%-*.2f", 20, weather_value);

        //add to array
        array[counter]=weather_value;

        // printf("\n");
        counter++;
    }
    
}

float calc_avr(float array[], int array_size){

    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        sum += array[i];
    }


    return sum/array_size;
}