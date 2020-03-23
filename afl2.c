#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
#include <string.h>

// internal libraries
#include "functions/my_functions.h"

// constants
#define TEMP_2011_1_SIZE 31
#define TEMP_2020_1_SIZE 31
#define RAIN_2011_1_SIZE 31
#define RAIN_2020_1_SIZE 31

int main(int argc,char *argv[])
{
    //assign arrays
    float temp_2011_1[TEMP_2011_1_SIZE];
    float temp_2020_1[TEMP_2020_1_SIZE];
    float rain_2011_1[RAIN_2011_1_SIZE];
    float rain_2020_1[RAIN_2020_1_SIZE];

    //task 1
    printf("Task 1 \n");

    scan_values_from_file(temp_2011_1, TEMP_2011_1_SIZE, "temp_avg_2011_1");
    float temp_2011_1_avr = calc_avr(temp_2011_1, TEMP_2011_1_SIZE);
    printf("The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);

    scan_values_from_file(temp_2020_1, TEMP_2020_1_SIZE, "temp_avg_2020_1");
    float temp_2020_1_avr = calc_avr(temp_2020_1, TEMP_2020_1_SIZE);
    printf("The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);

    if(temp_2011_1_avr < temp_2020_1_avr) {
        printf("Avg temperature was lowest for 2011 \n");
    } else {
        printf("Avg temperature was lowest for 2020 \n");
    }

    printf("\n");

    //task 2
    printf("Task 2 \n");

    scan_values_from_file(rain_2011_1, RAIN_2011_1_SIZE, "rain_2011_1");
    float rain_2011_1_total = calc_accumulated(rain_2011_1, RAIN_2011_1_SIZE);
    printf("Total rain for January 2011: %-*.2f \n", 20, rain_2011_1_total);

    scan_values_from_file(rain_2020_1, RAIN_2020_1_SIZE, "rain_2020_1");
    float rain_2020_1_total = calc_accumulated(rain_2020_1, RAIN_2020_1_SIZE);
    printf("Total rain for January 2020: %-*.2f \n", 20, rain_2020_1_total);

    if(rain_2011_1_total < rain_2020_1_total) {
        printf("It rained the most in January 2020 \n");
    } else {
        printf("It rained the most in January 2011 \n");
    }

    printf("\n");

    //task 3
    printf("Task 3 \n");
    printf("Days with more than 0 degrees in 2011: %d \n", more_than(temp_2011_1, TEMP_2011_1_SIZE, 0));
    printf("Days with more than 0 degrees in 2020: %d \n", more_than(temp_2020_1, TEMP_2020_1_SIZE, 0));
    printf("Days with 0 degrees in 2011: %d \n", equals(temp_2011_1, TEMP_2011_1_SIZE, 0));
    printf("Days with 0 degrees in 2020: %d \n", equals(temp_2020_1, TEMP_2020_1_SIZE, 0));
    printf("Days with less than 0 degrees in 2011: %d \n", less_than(temp_2011_1, TEMP_2011_1_SIZE, 0));
    printf("Days with less than 0 degrees in 2020: %d \n", less_than(temp_2020_1, TEMP_2020_1_SIZE, 0));

    printf("\n");

    //task 4
    printf("Task 4 \n");
    printf("Highest temperature January 2011: %-*.2f \n", 20, list_max_value(temp_2011_1, TEMP_2011_1_SIZE));
    printf("Highest temperature January 2020: %-*.2f \n", 20, list_max_value(temp_2020_1, TEMP_2020_1_SIZE));
    printf("Lowest temperature January 2011: %-*.2f \n", 20, list_min_value(temp_2011_1, TEMP_2011_1_SIZE));
    printf("Lowest temperature January 2020: %-*.2f \n", 20, list_min_value(temp_2020_1, TEMP_2020_1_SIZE));

    printf("\n");

    //task 5
    printf("Task 5 \n");
    printf("Number of days with temperature higher than average January 2011: %d \n", more_than(temp_2011_1, TEMP_2011_1_SIZE, temp_2011_1_avr));

    printf("\n");

    //task 6
    printf("Task 6 \n");
    printf("... \n");
    printf("\n");

    //task 7
    printf("Task 7 \n");
    float rain_2020_1_avr = calc_avr(rain_2020_1, RAIN_2020_1_SIZE);
    printf("The average rain January 2020: %-*.2f \n", 20, rain_2020_1_avr);
    printf("Number of days with less rain than average January 2020: %d \n", less_than(rain_2020_1, RAIN_2020_1_SIZE, rain_2020_1_avr));
    
    printf("\n");

    //task 8
    printf("Task 8 \n");

    printf("\n");
    
    create_digram(rain_2011_1, RAIN_2011_1_SIZE, list_min_value(rain_2011_1, RAIN_2011_1_SIZE), list_max_value(rain_2011_1, RAIN_2011_1_SIZE));
    // printf(".  .  \n");
    // printf(".  .  \n");
    // printf(".  .. \n");
    // printf(".. .. \n");
    // printf(".. ...\n");
    // printf("......\n");
    // printf("......\n");
    // printf("......\n");
    // printf("......\n");
    // printf("......\n");

    return 0;
}
