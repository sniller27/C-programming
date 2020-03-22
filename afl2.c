#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
#include <string.h>

// internal libraries
#include "functions/my_functions.h"
#define ARRAY_SIZE 30

int main(int argc,char *argv[])
{
    //assign arrays
    float temp_2011_1[ARRAY_SIZE];
    float temp_2020_1[ARRAY_SIZE];
    float rain_2011_1[ARRAY_SIZE];
    float rain_2020_1[ARRAY_SIZE];

    //task 1
    printf("Task 1 \n");

    scan_values_from_file(temp_2011_1, ARRAY_SIZE, "temp_avg_2011_1");
    float temp_2011_1_avr = calc_avr(temp_2011_1, ARRAY_SIZE);
    printf("The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);

    scan_values_from_file(temp_2020_1, ARRAY_SIZE, "temp_avg_2020_1");

    float temp_2020_1_avr = calc_avr(temp_2020_1, ARRAY_SIZE);
    printf("The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);

    if(temp_2011_1_avr < temp_2020_1_avr) {
        printf("Avg temperature was lowest for 2011 \n");
    } else {
        printf("Avg temperature was lowest for 2020 \n");
    }

    printf("\n");

    //task 2
    printf("Task 2 \n");

    scan_values_from_file(rain_2011_1, ARRAY_SIZE, "rain_2011_1");
    float rain_2011_1_total = calc_accumulated(rain_2011_1, ARRAY_SIZE);
    printf("The rain for January 2011: %-*.2f \n", 20, rain_2011_1_total);

    scan_values_from_file(rain_2020_1, ARRAY_SIZE, "rain_2020_1");
    float rain_2020_1_total = calc_accumulated(rain_2020_1, ARRAY_SIZE);
    printf("The rain for January 2020: %-*.2f \n", 20, rain_2020_1_total);

    if(rain_2011_1_total < rain_2020_1_total) {
        printf("It rained the most in January 2020 \n");
    } else {
        printf("It rained the most in January 2011 \n");
    }

    return 0;
}
