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


void plot_data(float array[], int array_size, float min, float max){
    
    //diagram height can be changed depending on the plot accuracy wanted
    int diagram_height = 10;

    //determining total range for intervals
    float difference = max-min;

    //determining length for each interval
    float interval_length = difference/(diagram_height - 1);

    //creating array for intervals by adding interval length for each value and subtracting it from max-value.
    float intervals[diagram_height];

    for (int i = 0; i < diagram_height; ++i) {
        intervals[i]=max - (i*interval_length);
    }

    //plotting data by comparing to intervals
    for (int j = 0; j < diagram_height; ++j) {

        printf("%-*.2f ", 5, intervals[j]);

        for (int i = 0; i < array_size; ++i) {

            if(array[i]==max){
                printf("|");
            }else if(array[i]>intervals[j]){
                printf("|");
            }else {
                printf(" ");
            }

        }

        printf("\n");
    }

}