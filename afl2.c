#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
    //assigning variables
    float value = 0;

    char header_1[255],
        header_2[255],
        date[255];

    //instatiate filepointer instance (one for reading and one for writing)
    FILE* read_data = fopen("data/temp_avg_2011_1.txt","r");

    //error checking filepointers
    if (read_data==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    }

    //reading headers from 1st line in file and save them to variables
    fscanf(read_data, "%s %s", header_1, header_2);
    printf("%-*s", 20, header_1);
    printf("%-*s \n", 20, header_2);

    // printf("Gennemsnitstemperatur: \n");
    while(fscanf(read_data, "%s %f", date, &value)!=EOF){
        printf("%-*s", 20, date);
        printf("%-*.2f", 20, value);

        //add to array


        printf("\n");
    }

    return 0;
}
