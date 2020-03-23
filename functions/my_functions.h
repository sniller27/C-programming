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
        // printf("%-*.2f \n", 20, weather_value);

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

float calc_accumulated(float array[], int array_size){

    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        sum += array[i];
    }

    return sum;
}

int more_than(float array[], int array_size, float value){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]>value){
            qty++;
        }
    }

    return qty;
}

int less_than(float array[], int array_size, float value){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]<value){
            qty++;
        }
    }

    return qty;
}

int equals(float array[], int array_size, float value){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]==value){
            qty++;
        }
    }

    return qty;
}

float list_max_value(float array[], int array_size){

    float max;
    
    for (int i = 0; i < array_size; ++i) {

        if(i==0){
            max = array[i];
        }

        if(array[i]>max){
            max = array[i];
        }

    }

    return max;
}

float list_min_value(float array[], int array_size){

    float min;

    for (int i = 0; i < array_size; ++i) {

        if(i==0){
            min = array[i];
        }

        if(array[i]<min){
            min = array[i];
        }

    }

    return min;
}


void create_digram(float array[], int array_size, float min, float max){

    int diagram_height = 10;

    // printf("min: %-*.2f \n", 20, min);
    // printf("max: %-*.2f \n", 20, max);

    float difference = max-min;
    float interval_length = difference/(diagram_height - 1);

    float intervals[diagram_height];

    for (int i = 0; i < diagram_height; ++i) {
        intervals[i]=max - (i*interval_length);
        // printf("lol: %-*.2f \n", 20, intervals[i]);
    }

    // for (int i = 0; i < array_size; ++i) {
    //     printf("%-*.2f \n", 20, array[i]);

    //     if(array[i]==max){
    //         printf("big lol");
    //     }
    // }

    for (int j = 0; j < diagram_height; ++j) {

        printf("%-*.2f ", 5, intervals[j]);
        // printf("o ");

        for (int i = 0; i < array_size; ++i) {
            // printf("%-*.2f \n", 20, array[i]);
            // printf("O");
            if(array[i]==max){
                printf("|");
            } 
            else if(array[i]>intervals[j]){
                printf("|");
            }else {
                printf(" ");
            }
        }


        // for (int j = 0; j < 30; ++j) {

        //     if(9,20==array[i]){
        //         printf("O");
        //     }else {
        //         printf("|");            
        //     }

        // }
        // break;
        printf("\n");
    }

}