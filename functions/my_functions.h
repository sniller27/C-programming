/**
 *      Objective: Transfers data from a specified file to a string-array and a float-array
 *      Precondition: Arrays should always have enough slots for content
 *      Parameters: Function receives array size (corresponding to number of lines in file), name of the file, string-array (2d char-array) and float array
 *      Return value/Postcondition: Returns void (however indirectly changes arrays, since passed arrays are populated)
 * **/
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

        counter++;
    }

    //close file connections
    fclose(read_data);
    
}

/**
 *      Objective: Calculates average value of array float values
 *      Parameters: Receives float array and its size
 *      Return value/Postcondition: Returns the average float value
 * **/
float calc_avr(const float array[], int array_size){

    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        sum += array[i];
    }

    return sum/array_size;
}

/**
 *      Objective: Calculates the sum value of all the values in a float array
 *      Parameters: Receives float array and its size
 *      Return value/Postcondition: returns sum of all array values as a float
 * **/
float calc_accumulated(const float array[], int array_size){

    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        sum += array[i];
    }

    return sum;
}

/**
 *      Objective: Counts the number of elements in a given float array that are above a given value
 *      Parameters: Receives float array, its size and a given comparison value
 *      Return value/Postcondition: Returns number of elements in array that are above the given value (as an integer)
 * **/
int values_more_than(const float array[], int array_size, float value){

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
 *      Return value/Postcondition: Returns number of elements in array that are under the given value (as an integer)
 * **/
int values_less_than(const float array[], int array_size, float value){

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
 *      Return value/Postcondition: Returns number of elements in array that equal given value (as an integer)
 * **/
int values_equals(const float array[], int array_size, float value){

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
 *      Return value/Postcondition: Returns the max value in a float array (as a float)
 * **/
float list_max_value(const float array[], int array_size){

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
 *      Return value/Postcondition: Returns the min value in a float array (as a float)
 * **/
float list_min_value(const float array[], int array_size){

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
 *      Return value/Postcondition: Returns void (however the integer array is populated and the length of the array is assigned an integer)
 * **/
void array_indexes_more_than(int array_size, const float *array, int *indexes, int value, int *index_array_length){
    
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
 *      Objective: Plots diagram based on values of float array. Done by determining intervals values between 
 *                 minimum and maximum values (intervals can be adjusted in function) and then printing "strings"
 *                 in nested loops (as a 2d string array).               
 *      Parameters: Receives float array and its size, minimum value as float, maximum value as float and file pointer 
 *                  (for writing to file).
 *      Return value/Postcondition: Returns void
 **/
void plot_data(const float array[], int array_size, float min, float max, FILE* file1){
    
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

/**
 *      Objective: Compare temperatures in January of two different years and prints the highest temperature of each day in January.            
 *      Precondition: This function requires given arrays to be the same size
 *      Parameters: Receives size of arrays, receives structs for each year and a file pointer 
 *                  (for writing to file).
 *      Return value/Postcondition: Returns void (only printing and writing to file)
 **/
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

/**
 *      Objective: Returns the number of elements in a float array that are greater than a given value and less than/equal to another given value
 *      Parameters: Receives float array and its size, given greater than float value, given less than float value
 *      Returns value: Returns number of values (as an integer)
 * **/
int array_greater_than_less_equal(const float array[], int array_size, float floor, float ceil){

    int qty = 0;

    for (int i = 0; i < array_size; ++i) {
        if(array[i]>floor && array[i]<=ceil){
            qty++;
        }
    }

    return qty;

}

/**
 *      Objective: Selection sort algorithm (this function is from the learning material)
 *      Parameters: Receives float array and its size.
 *      Returns value: Return void (however the float array is sorted)
 * **/
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

/**
 *      Objective: Finds median or array (done by using modulo operator to determine even and odd number of elements in array)
 *      Parameters: Receives float array and its size.
 *      Returns value: Return median value (as a float)
 * **/
float get_median(const float array[], int array_size){

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
