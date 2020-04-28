#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// internal constants
#include "constants/my_constants.h"

// internal structs
#include "structs/my_structs.h"
#include "structs/student.h"

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

    struct Student students[10];
    struct Student a;
    scan_values_from_file(TEMP_2011_1_SIZE, "temp_avg_2011_1", y_2011.temperature.date, y_2011.temperature.weather_value);
    get_student_data(10, "tekstfil", students[10]);

    print_write_string("\n", output_file);

    return 0;
}


