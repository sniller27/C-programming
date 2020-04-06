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

    struct Weather_Values {
        int ost;
        char kanin[255];
        char date[255][31];
        float weather_value[TEMP_2011_1_SIZE];
        // char array1[31];
        // char date[10][50]; 
    };
    
    struct Year {
        int x;
        struct Weather_Values temperature;
        // struct Weather_Values rain;
    };

    
    
    // struct Year _2011;
    // _2011.x = 5;
    // _2011.temperature.weather_value = temp_2011_1;

    //assign arrays
    float temp_2011_1[TEMP_2011_1_SIZE];
    float temp_2020_1[TEMP_2020_1_SIZE];
    float rain_2011_1[RAIN_2011_1_SIZE];
    float rain_2020_1[RAIN_2020_1_SIZE];

    //task 1
    printf("Task 1 \n");

    // scan_values_from_file(temp_2011_1, TEMP_2011_1_SIZE, "temp_avg_2011_1");
    // float temp_2011_1_avr = calc_avr(temp_2011_1, TEMP_2011_1_SIZE);
    // printf("The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);

    // scan_values_from_file(temp_2020_1, TEMP_2020_1_SIZE, "temp_avg_2020_1");
    // float temp_2020_1_avr = calc_avr(temp_2020_1, TEMP_2020_1_SIZE);
    // printf("The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);

    // if(temp_2011_1_avr < temp_2020_1_avr) {
    //     printf("Avg temperature was lowest for 2011 \n");
    // } else {
    //     printf("Avg temperature was lowest for 2020 \n");
    // }

    struct Year y_2011;

    // strcpy(y_2011.temperature.date[0], "kage");
    scan_values_from_file(TEMP_2011_1_SIZE, "temp_avg_2011_1", y_2011.temperature.date, y_2011.temperature.weather_value);
    
    // printf("indhold: %-*.2f \n", 20, y_2011.temperature.weather_value[0]);
    // printf("indhold: %-*.2f \n", 20, y_2011.temperature.weather_value[1]);
    // printf("indhold: %-*.2f \n", 20, y_2011.temperature.weather_value[2]);

    // printf("indhold2a: %s \n", y_2011.temperature.date[0]);
    // printf("indhold2b: %s \n", y_2011.temperature.date[1]);

    for (int i = 0; i < 31; i++)
    {
        printf("geeez: %s \t", y_2011.temperature.date[i]);
        printf("%-*.2f \n", 20, y_2011.temperature.weather_value[i]);
        /* code */
    }
    

    // y_2011.temperature.ost = 5;
    // char header_2[255];

    // strcpy(header_2, "ulal");
    // printf("indhold: %s \n", header_2);
    
    // strcpy(y_2011.temperature.kanin, "rabbit");
    // printf("indhold: %s \n", y_2011.temperature.kanin);

    // strcpy(y_2011.temperature.date[20], "kage");
    // strcpy(y_2011.temperature.date[21], "kage2");

    // // // y_2011.temperature.date[0] = "kage";
    // printf("indhold: %s \n", y_2011.temperature.date[20]);
    // printf("indhold: %s \n", y_2011.temperature.date[21]);

    // printf("indhold: %-*.2f \n", &y_2011.temperature.kanin[255]);
    // printf("indhold: %d \n", y_2011.temperature.ost);

    printf("banan\n");

    printf("\n");

    // //task 2
    // printf("Task 2 \n");

    // scan_values_from_file(rain_2011_1, RAIN_2011_1_SIZE, "rain_2011_1");
    // float rain_2011_1_total = calc_accumulated(rain_2011_1, RAIN_2011_1_SIZE);
    // printf("Total rain for January 2011: %-*.2f \n", 20, rain_2011_1_total);

    // scan_values_from_file(rain_2020_1, RAIN_2020_1_SIZE, "rain_2020_1");
    // float rain_2020_1_total = calc_accumulated(rain_2020_1, RAIN_2020_1_SIZE);
    // printf("Total rain for January 2020: %-*.2f \n", 20, rain_2020_1_total);

    // if(rain_2011_1_total < rain_2020_1_total) {
    //     printf("It rained the most in January 2020 \n");
    // } else {
    //     printf("It rained the most in January 2011 \n");
    // }

    // printf("\n");

    // //task 3
    // printf("Task 3 \n");
    // printf("Days with more than 0 degrees in 2011: %d \n", more_than(temp_2011_1, TEMP_2011_1_SIZE, 0));
    // printf("Days with more than 0 degrees in 2020: %d \n", more_than(temp_2020_1, TEMP_2020_1_SIZE, 0));
    // printf("Days with 0 degrees in 2011: %d \n", equals(temp_2011_1, TEMP_2011_1_SIZE, 0));
    // printf("Days with 0 degrees in 2020: %d \n", equals(temp_2020_1, TEMP_2020_1_SIZE, 0));
    // printf("Days with less than 0 degrees in 2011: %d \n", less_than(temp_2011_1, TEMP_2011_1_SIZE, 0));
    // printf("Days with less than 0 degrees in 2020: %d \n", less_than(temp_2020_1, TEMP_2020_1_SIZE, 0));

    // printf("\n");

    // //task 4
    // printf("Task 4 \n");
    // printf("Highest temperature January 2011: %-*.2f \n", 20, list_max_value(temp_2011_1, TEMP_2011_1_SIZE));
    // printf("Highest temperature January 2020: %-*.2f \n", 20, list_max_value(temp_2020_1, TEMP_2020_1_SIZE));
    // printf("Lowest temperature January 2011: %-*.2f \n", 20, list_min_value(temp_2011_1, TEMP_2011_1_SIZE));
    // printf("Lowest temperature January 2020: %-*.2f \n", 20, list_min_value(temp_2020_1, TEMP_2020_1_SIZE));

    // printf("\n");

    // //task 5
    // printf("Task 5 \n");
    // printf("Number of days with temperature higher than average January 2011: %d \n", more_than(temp_2011_1, TEMP_2011_1_SIZE, temp_2011_1_avr));

    // printf("\n");

    // //task 6
    // printf("Task 6 \n");
    // printf("... \n");
    // printf("\n");

    // //task 7
    // printf("Task 7 \n");
    // float rain_2020_1_avr = calc_avr(rain_2020_1, RAIN_2020_1_SIZE);
    // printf("The average rain January 2020: %-*.2f \n", 20, rain_2020_1_avr);
    // printf("Number of days with less rain than average January 2020: %d \n", less_than(rain_2020_1, RAIN_2020_1_SIZE, rain_2020_1_avr));
    
    // printf("\n");

    // //task 8
    // printf("Task 8 \n");
    // printf("Rain January 2011: \n");
    // printf("\n");
    // plot_data(rain_2011_1, RAIN_2011_1_SIZE, list_min_value(rain_2011_1, RAIN_2011_1_SIZE), list_max_value(rain_2011_1, RAIN_2011_1_SIZE));
    // printf("\n");

    // //task 9
    // printf("Task 9 \n");
    // printf("... \n");
    // printf("\n");

    // //task 10
    // printf("Task 10 \n");
    // printf("Days with temperature more than 4 but less than/equal to 6 for January 2011 is:");
    // printf(" %d \n", values_between(temp_2020_1, TEMP_2020_1_SIZE, 4, 6));
    // printf("\n");

    // //task 11
    // printf("Task 10 \n");
    // printf("Temperature January 2011(sorted): \n");

    // //selection sort (ascending)
    // selectionsort(temp_2011_1, TEMP_2011_1_SIZE);

    // for (int i = 0; i < TEMP_2011_1_SIZE; ++i) {
    //     printf("%-*.2f  \n", 20, temp_2011_1[i]);
    // }

    // //median
    // printf("median: %-*.2f  \n", 20, get_median(temp_2011_1, TEMP_2011_1_SIZE));

    return 0;
}


