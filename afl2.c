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

    print_write_float("Highest temperature January 2011: %-*.2f \n", list_max_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE), output_file);
    print_write_float("Highest temperature January 2020: %-*.2f \n", list_max_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE), output_file);
    print_write_float("Lowest temperature January 2011: %-*.2f \n", list_min_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE), output_file);
    print_write_float("Lowest temperature January 2020: %-*.2f \n", list_min_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE), output_file);

    print_write_string("\n", output_file);

    //task 5
    print_write_string("Task 5 \n", output_file);

    print_write_int("Number of days with temperature higher than average January 2011: %d \n", values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, temp_2011_1_avr), output_file);

    print_write_string("\n", output_file);

    //task 6
    print_write_string("Task 6 \n", output_file);

    print_write_string("Days with more than 0 mm rain in January 2011: \n", output_file);

    int indexes_2011[31], indexes_length_2011 = 0;
    array_indexes_more_than(RAIN_2011_1_SIZE, y_2011.rain.weather_value, indexes_2011, 0, &indexes_length_2011);
    print_string_array_from_indexes(indexes_length_2011, y_2011.rain.date, indexes_2011, output_file);

    print_write_string("\n", output_file);

    print_write_string("Days with more than 0 mm rain in January 2020: \n", output_file);

    int indexes_2020[31], indexes_length_2020 = 0;
    array_indexes_more_than(RAIN_2020_1_SIZE, y_2020.rain.weather_value, indexes_2020, 0, &indexes_length_2020);
    print_string_array_from_indexes(indexes_length_2020, y_2020.rain.date, indexes_2020, output_file);
    
    print_write_string("\n", output_file);

    //task 7
    print_write_string("Task 7 \n", output_file);

    float rain_2020_1_avr = calc_avr(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    print_write_float("The average rain January 2020: %-*.2f \n", rain_2020_1_avr, output_file);
    print_write_int("Number of days with less rain than average January 2020: %d \n", values_less_than(y_2020.rain.weather_value, RAIN_2020_1_SIZE, rain_2020_1_avr), output_file);

    print_write_string("\n", output_file);

    //task 8
    print_write_string("Task 8 \n", output_file);

    print_write_string("Rain January 2011: \n \n", output_file);

    plot_data(y_2011.rain.weather_value, RAIN_2011_1_SIZE, list_min_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), list_max_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), output_file);
    
    print_write_string("\n", output_file);

    //task 9
    print_write_string("Task 9 \n", output_file);
    
    compare_temperature_years(31, y_2011, y_2020, output_file);

    print_write_string("\n", output_file);

    //task 10
    print_write_string("Task 10 \n", output_file);

    print_write_int("Days with temperature more than 4 but less than/equal to 6 for January 2020 is: %d \n", values_between(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 4, 6), output_file);
    
    print_write_string("\n", output_file);

    //task 11
    print_write_string("Task 11 \n", output_file);
    print_write_string("Temperature January 2011(sorted): \n", output_file);

    //selection sort (ascending) (this would cause a problem since the weather values are sorted but not the respective dates)
    // float y_2011_01_temp_sorted[31];
    selectionsort(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    print_write_float_array(TEMP_2011_1_SIZE, y_2011.temperature.weather_value, output_file);

    //printing median
    print_write_float("Median: %-*.2f  \n", get_median(y_2011.temperature.weather_value, TEMP_2011_1_SIZE), output_file);

    //close file pointer
    fclose(output_file);

    return 0;
}


