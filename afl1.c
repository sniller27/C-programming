#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>

int main(int argc,char *argv[])
{

    //variables
    FILE* fp = fopen("bestilling.txt","r"); 
    char str1[10], str2[10], str3[10];
    int val1, val2;


    // int price_reading = 0;
    float sum = 0;
    int total_price = 0;

    //check if file exists 
    if (fp==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    }



    //read from file
    // char product_qty[255];
    int product_qty;
    char product_name[255];
    float product_price;

    //product_name peger vi på en memory adresse (og det gør product_qty automatisk)
    while(fscanf(fp, "%d %s %f", &product_qty, product_name, &product_price)!=EOF){

        // printf(fp);
        
        printf("%d\t", product_qty );
        printf("%s \t", product_name );
        printf("%.2f \t", product_price );
        printf("\n");

        sum += product_price;
        
    }  

    printf("Total price: %.2f\n", sum );

    //close file connection
    fclose(fp);

    //prevent prompt from closing
    // system("pause");
  
    return 0;
}
