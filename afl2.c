#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//internal structs
#include "structs/my_structs.h"

// internal libraries
#include "functions/my_functions.h"

// constants
#define TEMP_2011_1_SIZE 31
#define TEMP_2020_1_SIZE 31
#define RAIN_2011_1_SIZE 31
#define RAIN_2020_1_SIZE 31

int main(int argc,char *argv[])
{
    //declare arrays
    float temp_2011_1[TEMP_2011_1_SIZE], temp_2020_1[TEMP_2020_1_SIZE], rain_2011_1[RAIN_2011_1_SIZE], rain_2020_1[RAIN_2020_1_SIZE];

    //assigning data arrays to structs
    struct Year y_2011, y_2020;
    scan_values_from_file(TEMP_2011_1_SIZE, "temp_avg_2011_1", y_2011.temperature.date, y_2011.temperature.weather_value);
    scan_values_from_file(TEMP_2011_1_SIZE, "rain_2011_1", y_2011.rain.date, y_2011.rain.weather_value);

    scan_values_from_file(TEMP_2020_1_SIZE, "temp_avg_2020_1", y_2020.temperature.date, y_2020.temperature.weather_value);
    scan_values_from_file(TEMP_2020_1_SIZE, "rain_2020_1", y_2020.rain.date, y_2020.rain.weather_value);

    //task 1
    printf("Task 1 \n");

    float temp_2011_1_avr = calc_avr(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    printf("The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);

    float temp_2020_1_avr = calc_avr(y_2020.temperature.weather_value, TEMP_2020_1_SIZE);
    printf("The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);

    //determine which month has the lowest average temperature
    if(temp_2011_1_avr < temp_2020_1_avr) {
        printf("Avg temperature was lowest for 2011 \n");
    } else {
        printf("Avg temperature was lowest for 2020 \n");
    }

    // for (int i = 0; i < 31; i++)
    // {
    //     printf("geeez: %s \t", y_2020.rain.date[i]);
    //     printf("%-*.2f \n", 20, y_2020.rain.weather_value[i]);
    //     /* code */
    // }

    printf("\n");

    //task 2
    printf("Task 2 \n");

    float rain_2011_1_total = calc_accumulated(y_2011.rain.weather_value, RAIN_2011_1_SIZE);
    printf("Total rain for January 2011: %-*.2f \n", 20, rain_2011_1_total);

    float rain_2020_1_total = calc_accumulated(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    printf("Total rain for January 2020: %-*.2f \n", 20, rain_2020_1_total);

    if(rain_2011_1_total < rain_2020_1_total) {
        printf("It rained the most in January 2020 \n");
    } else {
        printf("It rained the most in January 2011 \n");
    }

    printf("\n");

    //task 3
    printf("Task 3 \n");
    printf("Days with more than 0 degrees in 2011: %d \n", values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0));
    printf("Days with more than 0 degrees in 2020: %d \n", values_more_than(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0));
    printf("Days with 0 degrees in 2011: %d \n", values_equals(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0));
    printf("Days with 0 degrees in 2020: %d \n", values_equals(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0));
    printf("Days with less than 0 degrees in 2011: %d \n", values_less_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0));
    printf("Days with less than 0 degrees in 2020: %d \n", values_less_than(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0));

    printf("\n");

    //task 4
    printf("Task 4 \n");
    printf("Highest temperature January 2011: %-*.2f \n", 20, list_max_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE));
    printf("Highest temperature January 2020: %-*.2f \n", 20, list_max_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE));
    printf("Lowest temperature January 2011: %-*.2f \n", 20, list_min_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE));
    printf("Lowest temperature January 2020: %-*.2f \n", 20, list_min_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE));

    printf("\n");

    //task 5
    printf("Task 5 \n");
    printf("Number of days with temperature higher than average January 2011: %d \n", values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, temp_2011_1_avr));

    printf("\n");

    //task 6
    printf("Task 6 \n");

    printf("Dage med med mere end 0 mm nedbør i Januar 2011: \n");
    int indexes_2011[31], indexes_length_2011 = 0;
    array_indexes_more_than(RAIN_2011_1_SIZE, y_2011.rain.weather_value, indexes_2011, 0, &indexes_length_2011);
    print_string_array_from_indexes(indexes_length_2011, y_2011.rain.date, indexes_2011);
    
    printf("Dage med med mere end 0 mm nedbør i Januar 2020: \n");
    int indexes_2020[31], indexes_length_2020 = 0;
    array_indexes_more_than(RAIN_2020_1_SIZE, y_2020.rain.weather_value, indexes_2020, 0, &indexes_length_2020);
    print_string_array_from_indexes(indexes_length_2020, y_2020.rain.date, indexes_2020);
    
    printf("\n");

    //task 7
    printf("Task 7 \n");
    float rain_2020_1_avr = calc_avr(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    printf("The average rain January 2020: %-*.2f \n", 20, rain_2020_1_avr);
    printf("Number of days with less rain than average January 2020: %d \n", values_less_than(y_2020.rain.weather_value, RAIN_2020_1_SIZE, rain_2020_1_avr));
    
    printf("\n");

    //task 8
    printf("Task 8 \n");
    printf("Rain January 2011: \n");
    printf("\n");
    plot_data(y_2011.rain.weather_value, RAIN_2011_1_SIZE, list_min_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), list_max_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE));
    printf("\n");

    //task 9
    printf("Task 9 \n");
    int comparison_array[31];
    compare_temperature_years(31, y_2011, y_2020);

    printf("\n");

    //task 10
    printf("Task 10 \n");
    printf("Days with temperature more than 4 but less than/equal to 6 for January 2020 is:");
    printf(" %d \n", values_between(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 4, 6));
    printf("\n");

    //task 11
    printf("Task 10 \n");
    printf("Temperature January 2011(sorted): \n");

    //selection sort (ascending)
    selectionsort(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);

    for (int i = 0; i < TEMP_2011_1_SIZE; ++i) {
        printf("%-*.2f  \n", 20, y_2011.temperature.weather_value[i]);
    }

    //median
    printf("median: %-*.2f  \n", 20, get_median(y_2011.temperature.weather_value, TEMP_2011_1_SIZE));

    return 0;
}


