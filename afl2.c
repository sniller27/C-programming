#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
#include <string.h>

// internal libraries
#include "functions/my_functions.h"
#define ARRAY_SIZE 30

int main(int argc,char *argv[])
{
    //assigning variables
    // float weather_value = 0;

    // char header_1[255],
    //     header_2[255],
    //     date[255];

    //assign arrays
    float temp_2011_1[ARRAY_SIZE];
    float temp_2020_1[ARRAY_SIZE];

    // //instatiate filepointer instance (one for reading and one for writing)
    // FILE* read_data = fopen("data/temp_avg_2011_1.txt","r");

    // //error checking filepointers
    // if (read_data==NULL) 
    // { 
    //     printf("no such file."); 
    //     return 0; 
    // }

    // //reading headers from 1st line in file and save them to variables
    // fscanf(read_data, "%s %s", header_1, header_2);
    // printf("%-*s", 20, header_1);
    // printf("%-*s \n", 20, header_2);

    // // printf("Gennemsnitstemperatur: \n");
    // int counter = 0;

    // while(fscanf(read_data, "%s %f", date, &weather_value)!=EOF){
    //     printf("%-*s", 20, date);
    //     printf("%-*.2f", 20, weather_value);

    //     //add to array
    //     weather_value_array[counter]=weather_value;

    //     printf("\n");
    //     counter++;
    // }

    scan_values_from_file(temp_2011_1, ARRAY_SIZE, "temp_avg_2011_1");
    float temp_2011_1_avr = calc_avr(temp_2011_1, ARRAY_SIZE);
    printf("The average temperature for January 2011: %-*.2f \n", 20, temp_2011_1_avr);

    scan_values_from_file(temp_2020_1, ARRAY_SIZE, "temp_avg_2020_1");

    float temp_2020_1_avr = calc_avr(temp_2020_1, ARRAY_SIZE);
    printf("The average temperature for January 2020: %-*.2f \n", 20, temp_2020_1_avr);

    if(temp_2011_1_avr < temp_2020_1_avr) {
         printf("Avg temperature was lowest for 2011");
    } else {
        printf("Avg temperature was lowest for 2020");
    }

    return 0;
}
