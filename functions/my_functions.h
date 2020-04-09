/**
 *      Objective: Transfers data from a specified file to a string-array and a float-array
 *      Parameters: Function receives array size (corresponding to number of lines in file), name of the file, string-array (2d char-array) and float array
 *      Return value: Returns void (however indirectly changes arrays, since passed arrays are populated)
 * **/
void scan_values_from_file(int size, char *file_name, char date_array[][size], float *value_array){

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

    // error checking filepointers
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

        counter++;
    }

    //close file connections
    fclose(read_data);
    
}

/**
 *      Objective: Calculates average value of array float values
 *      Parameters: Receives float array and its size
 *      Return value: Returns the average float value
 * **/
float calc_avr(float array[], int array_size){

    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        sum += array[i];
    }

    return sum/array_size;
}

/**
 *      Objective: Calculates the sum value of all the values in a float array
 *      Parameters: Receives float array and its size
 *      Return value: returns sum of all array values as a float
 * **/
float calc_accumulated(float array[], int array_size){

    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        sum += array[i];
    }

    return sum;
}

/**
 *      Objective: Counts the number of elements in a given float array that are above a given value
 *      Parameters: Receives float array, its size and a given comparison value
 *      Return value: Returns number of elements in array that are above the given value (as an integer)
 * **/
int values_more_than(float array[], int array_size, float value){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]>value){
            qty++;
        }
    }

    return qty;
}

/**
 *      Objective: Counts the number of elements in a given float array that are under a given value
 *      Parameters: Receives float array, its size and a given comparison value
 *      Return value: Returns number of elements in array that are under the given value (as an integer)
 * **/
int values_less_than(float array[], int array_size, float value){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]<value){
            qty++;
        }
    }

    return qty;
}

/**
 *      Objective: Counts the number of elements in a given float array that equal a given value
 *      Parameters: Receives float array, its size and a given comparison value
 *      Return value: Returns number of elements in array that equal given value (as an integer)
 * **/
int values_equals(float array[], int array_size, float value){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]==value){
            qty++;
        }
    }

    return qty;
}

/**
 *      Objective: Finds and returns the max value in a float array
 *      Parameters: Receives float array and its size
 *      Return value: Returns the max value in a float array (as a float)
 * **/
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

/**
 *      Objective: Finds and returns the min value in a float array
 *      Parameters: Receives float array and its size
 *      Return value: Returns the min value in a float array (as a float)
 * **/
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

/**
 *      Objective: Finds values in float array that are more than a given value. Indexes of found values are
 *                 stored in a integer array and number of elements are assigned to integer variable.
 *      Parameters: Receives float array and its size, an integer array for the found indexes, an integer
 *                  value for a given comarison value and a variable for length of the array of indexes.
 *      Return value: Return void (however the integer array is populated and the length of the array is assigned an integer)
 * **/
void array_indexes_more_than(int array_size, float *array, int *indexes, int value, int *index_array_length){
    
    int counter = 0;
    
    for (int i = 0; i < array_size; ++i) {
        if (array[i]>value) {
            indexes[counter] = i;
            counter++;
        }
    }

    *index_array_length = counter;

}

/**
 *      Objective: Prints and writes to file specific values of string array (2d char-array) based on values of a given integer array.
 *      Parameters: Receives an integer array and its size, a string-array and a filepointer (write to file)
 *      Return value: Returns void
 * **/
void print_string_array_from_indexes(int array_size, char dates[][31], int *indexes, FILE* file){
    for (int i = 0; i < array_size; ++i) {
        printf("%s \n", dates[indexes[i]]);
        fprintf(file, "%s \n", dates[indexes[i]]);
    }
}

void plot_data(float array[], int array_size, float min, float max, FILE* file1){
    
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
        fprintf(file1, "%-*.2f ", 5, intervals[j]);

        for (int i = 0; i < array_size; ++i) {

            if(array[i]==max){
                print_write_string("|", file1);
            }else if(array[i]>intervals[j]){
                print_write_string("|", file1);
            }else {
                print_write_string(" ", file1);
            }

        }

        print_write_string("\n", file1);
    }

}

void compare_temperature_years(int array_size, struct Year year1, struct Year year2, FILE* file1){

    for (int i = 0; i < array_size; ++i) {

        if(year1.temperature.weather_value[i]>year2.temperature.weather_value[i]) {

            printf("On %s the temperature was higher than %s \n", year1.temperature.date[i], year2.temperature.date[i]);
            fprintf(file1, "On %s the temperature was higher than %s \n", year1.temperature.date[i], year2.temperature.date[i]);

        } else {

            printf("On %s the temperature was higher than %s \n", year2.temperature.date[i], year1.temperature.date[i]);
            fprintf(file1, "On %s the temperature was higher than %s \n", year2.temperature.date[i], year1.temperature.date[i]);

        }
    }

}

//function can be extended with parameter that determines equal values
int values_between(float array[], int array_size, float floor, float ceil){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]>floor && array[i]<=ceil){
            qty++;
        }
    }

    return qty;

}

//this function is from the learning material (selection sort algorithm)
void selectionsort(float a[],int n) {

        int pos;
        float gem;

        for(int i=0; i<n-1; i++) {

            pos=i;

            for(int j=i+1;j<n;j++){
                if(a[pos]>a[j]){
                    pos=j;                    
                }
            }

            if(pos!=i){
                gem=a[i];
                a[i]=a[pos];
                a[pos]=gem;
            }
        }
}

float get_median(float array[], int array_size){

    int middle_index;
    float middle_average;

    if(array_size % 2 == 0) {
        middle_index = array_size/2;
        middle_average = (array[middle_index - 1] + array[middle_index])/2;

        return middle_average;
    } else {
        middle_index = array_size/2;
        
        return array[middle_index];
    }

}
