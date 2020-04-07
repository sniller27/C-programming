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
    //creating filepointer for writing outputs to file
    FILE* output_file = fopen("output.txt", "w");

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
    fprintf(output_file, "Task 1 \n");

    float temp_2011_1_avr = calc_avr(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    printf("The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);
    fprintf(output_file, "The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);

    float temp_2020_1_avr = calc_avr(y_2020.temperature.weather_value, TEMP_2020_1_SIZE);
    printf("The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);
    fprintf(output_file, "The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);

    //determine which month has the lowest average temperature
    if(temp_2011_1_avr < temp_2020_1_avr) {
        printf("Avg temperature was lowest for 2011 \n");
        fprintf(output_file, "Avg temperature was lowest for 2011 \n");
    } else {
        printf("Avg temperature was lowest for 2020 \n");
        fprintf(output_file, "Avg temperature was lowest for 2020 \n");
    }

    // for (int i = 0; i < 31; i++)
    // {
    //     printf("geeez: %s \t", y_2020.rain.date[i]);
    //     printf("%-*.2f \n", 20, y_2020.rain.weather_value[i]);
    //     /* code */
    // }

    printf("\n");
    fprintf(output_file, "\n");

    //task 2
    printf("Task 2 \n");
    fprintf(output_file, "Task 2 \n");

    float rain_2011_1_total = calc_accumulated(y_2011.rain.weather_value, RAIN_2011_1_SIZE);
    printf("Total rain for January 2011: %-*.2f \n", 20, rain_2011_1_total);
    fprintf(output_file, "Total rain for January 2011: %-*.2f \n", 20, rain_2011_1_total);

    float rain_2020_1_total = calc_accumulated(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    printf("Total rain for January 2020: %-*.2f \n", 20, rain_2020_1_total);
    fprintf(output_file, "Total rain for January 2020: %-*.2f \n", 20, rain_2020_1_total);

    if(rain_2011_1_total < rain_2020_1_total) {
        printf("It rained the most in January 2020 \n");
        fprintf(output_file, "It rained the most in January 2020 \n");
    } else {
        printf("It rained the most in January 2011 \n");
        fprintf(output_file, "It rained the most in January 2011 \n");
    }

    printf("\n");
    fprintf(output_file, "\n");

    //task 3
    printf("Task 3 \n");
    fprintf(output_file, "Task 3 \n");

    int no_of_days = 0;

    no_of_days = values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0);
    printf("Days with more than 0 degrees in 2011: %d \n", no_of_days);
    fprintf(output_file, "Days with more than 0 degrees in 2011: %d \n", no_of_days);

    no_of_days = values_more_than(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0);
    printf("Days with more than 0 degrees in 2020: %d \n", no_of_days);
    fprintf(output_file, "Days with more than 0 degrees in 2020: %d \n", no_of_days);

    no_of_days = values_equals(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0);
    printf("Days with 0 degrees in 2011: %d \n", no_of_days);
    fprintf(output_file, "Days with 0 degrees in 2011: %d \n", no_of_days);

    no_of_days = values_equals(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0);
    printf("Days with 0 degrees in 2020: %d \n", no_of_days);
    fprintf(output_file, "Days with 0 degrees in 2020: %d \n", no_of_days);

    no_of_days = values_less_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, 0);
    printf("Days with less than 0 degrees in 2011: %d \n", no_of_days);
    fprintf(output_file, "Days with less than 0 degrees in 2011: %d \n", no_of_days);

    no_of_days = values_less_than(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 0);
    printf("Days with less than 0 degrees in 2020: %d \n", no_of_days);
    fprintf(output_file, "Days with less than 0 degrees in 2020: %d \n", no_of_days);

    printf("\n");
    fprintf(output_file, "\n");

    //task 4
    printf("Task 4 \n");
    fprintf(output_file, "Task 4 \n");

    float min, max;

    max = list_max_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    printf("Highest temperature January 2011: %-*.2f \n", 20, max);
    fprintf(output_file, "Highest temperature January 2011: %-*.2f \n", 20, max);
    
    max = list_max_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE);
    printf("Highest temperature January 2020: %-*.2f \n", 20, max);
    fprintf(output_file, "Highest temperature January 2020: %-*.2f \n", 20, max);

    min = list_min_value(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    printf("Lowest temperature January 2011: %-*.2f \n", 20, min);
    fprintf(output_file, "Lowest temperature January 2011: %-*.2f \n", 20, min);

    min = list_min_value(y_2020.temperature.weather_value, TEMP_2020_1_SIZE);
    printf("Lowest temperature January 2020: %-*.2f \n", 20, min);
    fprintf(output_file, "Lowest temperature January 2020: %-*.2f \n", 20, min);

    printf("\n");
    fprintf(output_file, "\n");

    //task 5
    printf("Task 5 \n");
    fprintf(output_file, "Task 5 \n");

    int more_than;

    more_than = values_more_than(y_2011.temperature.weather_value, TEMP_2011_1_SIZE, temp_2011_1_avr);
    printf("Number of days with temperature higher than average January 2011: %d \n", more_than);
    fprintf(output_file, "Number of days with temperature higher than average January 2011: %d \n", more_than);

    printf("\n");
    fprintf(output_file, "\n");

    //task 6
    printf("Task 6 \n");
    fprintf(output_file, "Task 6 \n");

    printf("Dage med med mere end 0 mm nedbør i Januar 2011: \n");
    fprintf(output_file, "Dage med med mere end 0 mm nedbør i Januar 2011: \n");

    int indexes_2011[31], indexes_length_2011 = 0;
    array_indexes_more_than(RAIN_2011_1_SIZE, y_2011.rain.weather_value, indexes_2011, 0, &indexes_length_2011);
    print_string_array_from_indexes(indexes_length_2011, y_2011.rain.date, indexes_2011, output_file);

    printf("\n");
    fprintf(output_file, "\n");
    
    printf("Dage med med mere end 0 mm nedbør i Januar 2020: \n");
    fprintf(output_file, "Dage med med mere end 0 mm nedbør i Januar 2020: \n");

    int indexes_2020[31], indexes_length_2020 = 0;
    array_indexes_more_than(RAIN_2020_1_SIZE, y_2020.rain.weather_value, indexes_2020, 0, &indexes_length_2020);
    print_string_array_from_indexes(indexes_length_2020, y_2020.rain.date, indexes_2020, output_file);
    
    printf("\n");
    fprintf(output_file, "\n");

    //task 7
    printf("Task 7 \n");
    fprintf(output_file, "Task 7 \n");

    float rain_2020_1_avr = calc_avr(y_2020.rain.weather_value, RAIN_2020_1_SIZE);
    printf("The average rain January 2020: %-*.2f \n", 20, rain_2020_1_avr);
    fprintf(output_file, "The average rain January 2020: %-*.2f \n", 20, rain_2020_1_avr);
    
    no_of_days = values_less_than(y_2020.rain.weather_value, RAIN_2020_1_SIZE, rain_2020_1_avr);
    printf("Number of days with less rain than average January 2020: %d \n", no_of_days);
    fprintf(output_file, "Number of days with less rain than average January 2020: %d \n", no_of_days);

    printf("\n");
    fprintf(output_file, "\n");

    //task 8
    printf("Task 8 \n");
    fprintf(output_file, "Task 8 \n");

    printf("Rain January 2011: \n");
    fprintf(output_file, "Rain January 2011: \n");

    printf("\n");
    fprintf(output_file, "\n");

    plot_data(y_2011.rain.weather_value, RAIN_2011_1_SIZE, list_min_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), list_max_value(y_2011.rain.weather_value, RAIN_2011_1_SIZE), output_file);
    
    printf("\n");
    fprintf(output_file, "\n");

    //task 9
    printf("Task 9 \n");
    fprintf(output_file, "Task 9 \n");
    
    compare_temperature_years(31, y_2011, y_2020, output_file);

    printf("\n");
    fprintf(output_file, "\n");

    //task 10
    printf("Task 10 \n");
    fprintf(output_file, "Task 10 \n");

    printf("Days with temperature more than 4 but less than/equal to 6 for January 2020 is:");
    fprintf(output_file, "Days with temperature more than 4 but less than/equal to 6 for January 2020 is:");

    no_of_days = values_between(y_2020.temperature.weather_value, TEMP_2020_1_SIZE, 4, 6);
    printf(" %d \n", no_of_days);
    fprintf(output_file, " %d \n", no_of_days);
    
    printf("\n");
    fprintf(output_file, "\n");

    //task 11
    printf("Task 11 \n");
    fprintf(output_file, "Task 11 \n");

    printf("Temperature January 2011(sorted): \n");
    fprintf(output_file, "Temperature January 2011(sorted): \n");

    //selection sort (ascending)
    selectionsort(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);

    for (int i = 0; i < TEMP_2011_1_SIZE; ++i) {
        printf("%-*.2f  \n", 20, y_2011.temperature.weather_value[i]);
        fprintf(output_file, "%-*.2f  \n", 20, y_2011.temperature.weather_value[i]);
    }

    //median
    float median = get_median(y_2011.temperature.weather_value, TEMP_2011_1_SIZE);
    printf("median: %-*.2f  \n", 20, median);
    fprintf(output_file, "median: %-*.2f  \n", 20, median);

    return 0;
}


