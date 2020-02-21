#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
// #include <locale.h>

int main(int argc,char *argv[])
{
    // setlocale(LC_ALL, "en_US.UTF-8");

    //variables
    FILE* fp = fopen("bestilling.txt","r"); 
    char str1[10], str2[10], str3[10];
    int val1, val2;


    // int price_reading = 0;
    float sum = 0;
    int total_price = 0;
    float price_of_products = 0;

    //check if file exists 
    if (fp==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    }

    //read from file
    int product_qty;
    char product_name[255];
    float product_price;

    //product_name peger vi på en memory adresse (og det gør product_qty automatisk)
    while(fscanf(fp, "%d %s %f", &product_qty, product_name, &product_price)!=EOF){

        price_of_products = product_qty*product_price;
        
        printf("%-*d", 20, product_qty );
        printf("%-*s", 20, product_name );
        printf("%-*.2f", 20, product_price );
        printf("%-*.2f", 20, product_qty*product_price );

        sum += price_of_products;

        printf("\n");        
    }  

    printf("Total price: %.2f\n", sum );

    //close file connection
    fclose(fp);

    //prevent prompt from closing
    // system("pause");
  
    return 0;
}
