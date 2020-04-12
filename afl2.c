#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// internal constants
#include "constants/my_constants.h"

// internal structs
#include "structs/my_structs.h"

// internal libraries
#include "functions/print_write_functions.h"
#include "functions/my_functions.h"

int main(int argc,char *argv[])
{
    /**
     *  Comments:
     * 
     *  Use of variables have been limited to some degree, since the variable are not currently 
     *  used to anything but printing to console and writing to output-file (example of variable name could be no_days_01_2011_temp_more_than_0).
     *  The arrays used are not dynamic but fixed values. I haven't figured how to solve that yet.
     *  Other information could be added to structs as well, such as number of year (2011 and 2020) and name of month (January).
     * 
     * **/

    //declaring and assigning array sizes (each file have 31 lines of data)
    int TEMP_2011_1_SIZE, TEMP_2020_1_SIZE, RAIN_2011_1_SIZE, RAIN_2020_1_SIZE;
    TEMP_2011_1_SIZE = TEMP_2020_1_SIZE = RAIN_2011_1_SIZE = RAIN_2020_1_SIZE = FIXED_ARRAY_SIZE;

    //creating filepointer for writing outputs to file
    FILE* output_file = fopen("output.txt", "w");

    //assigning data arrays to structs (data stored in arrays)
    struct Year y_2011, y_2020;
    scan_values_from_file(TEMP_2011_1_SIZE, "temp_avg_2011_1", y_2011.temperature.date, y_2011.temperature.weather_value);
    scan_values_from_file(RAIN_2011_1_SIZE, "rain_2011_1", y_2011.rain.date, y_2011.rain.weather_value);
    scan_values_from_file(TEMP_2020_1_SIZE, "temp_avg_2020_1", y_2020.temperature.date, y_2020.temperature.weather_value);
    scan_values_from_file(RAIN_2020_1_SIZE, "rain_2020_1", y_2020.rain.date, y_2020.rain.weather_value);

    //task 1
    print_write_string("Task 1 \n", output_file);

    //assigning, printing and writing average temperature for January 2011
    float temp_2011_1_avr = calc_avr(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    print_write_float("The average temperature for January 2011: %-*.2f \n", temp_2011_1_avr, output_file);

    //assigning, printing and writing average temperature for January 2020
    float temp_2020_1_avr = calc_avr(y_2020.temperature.weather_value, TEMP_2020_1_SIZE);
    print_write_float("The average temperature for January 2020: %-*.2f \n", temp_2020_1_avr, output_file);

    //determine which month has the lowest average temperature
    if(temp_2011_1_avr < temp_2020_1_avr) {
        print_write_string("Avg temperature was lowest for 2011 \n", output_file);
    } else {
        print_write_string("Avg temperature was lowest for 2020 \n", output_file);
    }

    print_write_string("\n", output_file);

    //task 2
    print_write_string("Task 2 \n", output_file);

    //assigning total rain for January 2011
    float rain_2011_1_total = calc_accumulated(y_2011.rain.weather_value, RAIN_2011_1_SIZE);
    print_write_float("Total rain for January 2011: %-*.2f \n", rain_2011_1_total, output_file);

    //assigning total rain for January 2020
    float rain_2020_1_total = calc_accumulated(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    print_write_float("Total rain for January 2020: %-*.2f \n", rain_2020_1_total, output_file);

    //determine in which year it rained the most
    if(rain_2011_1_total < rain_2020_1_total) {
        print_write_string("It rained the most in January 2020 \n", output_file);
    } else {
        print_write_string("It rained the most in January 2011 \n", output_file);
    }

    print_write_string("\n", output_file);

    //task 3
    print_write_string("Task 3 \n", output_file);

    //Determining days with more than 0 degrees in January 2011 and 2020
    print_write_int("Days with more than 0 degrees in January 2011: %d \n", values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0), output_file);
    print_write_int("Days with more than 0 degrees in January 2020: %d \n", values_more_than(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0), output_file);

    //Determining days with 0 degrees in January 2011 and 2020
    print_write_int("Days with 0 degrees in January 2011: %d \n", values_equals(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0), output_file);
    print_write_int("Days with 0 degrees in January 2020: %d \n", values_equals(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0), output_file);

    //Determining days with less than 0 degrees in January 2011 and 2020
    print_write_int("Days with less than 0 degrees in January 2011: %d \n", values_less_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0), output_file);
    print_write_int("Days with less than 0 degrees in January 2020: %d \n", values_less_than(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0), output_file);

    print_write_string("\n", output_file);

    //task 4
    print_write_string("Task 4 \n", output_file);

    //Determining and printing highest/lowest temperatures in January 2011 and 2020 by using functions
    print_write_float("Highest temperature January 2011: %-*.2f \n", list_max_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE), output_file);
    print_write_float("Highest temperature January 2020: %-*.2f \n", list_max_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE), output_file);
    print_write_float("Lowest temperature January 2011: %-*.2f \n", list_min_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE), output_file);
    print_write_float("Lowest temperature January 2020: %-*.2f \n", list_min_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE), output_file);

    print_write_string("\n", output_file);

    //task 5
    print_write_string("Task 5 \n", output_file);

    //Determining and printing number of days with temperatures above average in January 2011
    print_write_int("Number of days with temperature higher than average January 2011: %d \n", values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, temp_2011_1_avr), output_file);

    print_write_string("\n", output_file);

    //task 6
    print_write_string("Task 6 \n", output_file);
    
    print_write_string("Days with more than 0 mm rain in January 2011: \n", output_file);

    int indexes_2011[RAIN_2011_1_SIZE], indexes_length_2011 = 0;
    //Determining days/dates with more than 0 mm rain in January 2011 (done by storing indexes in new array and integer for the size)
    array_indexes_more_than(RAIN_2011_1_SIZE, y_2011.rain.weather_value, 0, indexes_2011, &indexes_length_2011);
    //Printing dates
    print_string_array_from_indexes(indexes_length_2011, y_2011.rain.date, indexes_2011, output_file);

    print_write_string("\n", output_file);

    print_write_string("Days with more than 0 mm rain in January 2020: \n", output_file);

    int indexes_2020[RAIN_2020_1_SIZE], indexes_length_2020 = 0;
    //Determining days/dates with more than 0 mm rain in January 2020 (done by storing indexes in new array and integer for the size)
    array_indexes_more_than(RAIN_2020_1_SIZE, y_2020.rain.weather_value, 0, indexes_2020, &indexes_length_2020);
    //Printing dates
    print_string_array_from_indexes(indexes_length_2020, y_2020.rain.date, indexes_2020, output_file);
    
    print_write_string("\n", output_file);

    print_write_string("For both: \n", output_file);

    int indexes_both[RAIN_2011_1_SIZE], indexes_length_both = 0;
    //Determining days/dates with more than 0 mm rain in January 2011 (done by storing indexes in new array and integer for the size)
    array_indexes_more_than_both(RAIN_2011_1_SIZE, y_2011.rain.weather_value, y_2020.rain.weather_value, 0, indexes_both, &indexes_length_both);
    //Printing dates
    print_string_array_from_indexes(indexes_length_both, y_2011.rain.date, indexes_both, output_file);

    print_write_string("\n", output_file);

    //task 7
    print_write_string("Task 7 \n", output_file);

    //Calculating and printing average rain in January 2020
    float rain_2020_1_avr = calc_avr(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    print_write_float("The average rain January 2020: %-*.2f \n", rain_2020_1_avr, output_file);
    //Calculating and printing number of days with less rain than average in January 2020 (calculation based on average rain value from above)
    print_write_int("Number of days with less rain than average January 2020: %d \n", values_less_than(y_2020.rain.weather_value, RAIN_2020_1_SIZE, rain_2020_1_avr), output_file);

    print_write_string("\n", output_file);

    //task 8
    print_write_string("Task 8 \n", output_file);

    print_write_string("Rain January 2011: \n \n", output_file);

    //Plots diagram (by passing rain values, min rain value and max rain value)
    plot_data(y_2011.rain.weather_value, RAIN_2011_1_SIZE, list_min_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), list_max_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), output_file);
    
    print_write_string("\n", output_file);

    //task 9
    print_write_string("Task 9 \n", output_file);
    
    //Compares and printing temperatures. Assumed the arrays have the same sizes in the structs (e.g. TEMP_2011_1_SIZE = 31).
    compare_temperature_years(TEMP_2011_1_SIZE, y_2011, y_2020, output_file);

    print_write_string("\n", output_file);

    //task 10
    print_write_string("Task 10 \n", output_file);

    //Calculating and priting days with temperatures more than 4 but less/equal to 6 in January 2020 (done by passing temperatures to function)
    print_write_int("Days with temperature more than 4 but less than/equal to 6 for January 2020 is: %d \n", array_greater_than_less_equal(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 4, 6), output_file);
    
    print_write_string("\n", output_file);

    //task 11
    print_write_string("Task 11 \n", output_file);
    print_write_string("Temperature January 2011(sorted): \n", output_file);

    //declare new array (in order to avoid inconsistency in struct if it were sorted directly)
    float y_2011_01_temp_sorted[TEMP_2011_1_SIZE];

    //assign array to weather values
    //memcpy is a functions from string.h (https://stackoverflow.com/questions/7882735/why-cant-i-assign-arrays-as-a-b)
    memcpy(&y_2011_01_temp_sorted, &y_2011.temperature.weather_value, sizeof y_2011_01_temp_sorted);

    //sort array by using selection sort
    selectionsort(y_2011_01_temp_sorted, TEMP_2011_1_SIZE);

    //print array (by iterating through it in function)
    print_write_float_array(TEMP_2011_1_SIZE, y_2011_01_temp_sorted, output_file);

    //printing median
    print_write_float("Median: %-*.2f  \n", get_median(y_2011_01_temp_sorted, TEMP_2011_1_SIZE), output_file);

    //close file pointer
    fclose(output_file);

    return 0;
}


