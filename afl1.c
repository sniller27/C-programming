#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
// #include <locale.h>
#define MAX 100 

int main(int argc,char *argv[])
{
    // setlocale(LC_ALL, "en_US.UTF-8");

    //variables
    FILE* fp_order = fopen("bestilling.txt","r"); 

    // int price_reading = 0;
    float sum = 0;
    int total_price = 0, product_qty;
    float price_of_products, price_of_products_discount, product_price, product_price_discount;
    char product_name[255];

    //check if file exists 
    if (fp_order==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    }

    FILE* fp_invoice = fopen("faktura.txt", "w");
    // fprintf(fp_invoice, "This is testing for fprintf...\n");
    // fputs("This is testing for fputs...\n", fp_invoice);
    

    int readfile_counter = 0;
    
    //1. line variables
    char product_qty_header[MAX], product_name_header[MAX], product_price_header[MAX];

    //read from file
    //product_name peger vi på en memory adresse (og det gør product_qty automatisk)
    while(fscanf(fp_order, "%d %s %f", &product_qty, product_name, &product_price)!=EOF){
        readfile_counter++;

        if(readfile_counter == 1) {
            //printf("hello: %-*d %-*s %-*f", 20, product_qty, product_name, product_price);
            
            // printf("%-*s", 20, gcvt(product_qty, 6, product_qty_header));
            // printf("%-*s", 20, product_name);
            // printf("%-*.2f", 20, product_price);

            fprintf(fp_invoice, "%-*s", 20, "Varenavn");
            printf("%-*s", 20, "Varenavn");
            fprintf(fp_invoice, "%-*s", 20, "Antal");
            printf("%-*s", 20, "Antal");
            fprintf(fp_invoice, "%-*s", 20, "Stkpris");
            printf("%-*s", 20, "Stkpris");
            fprintf(fp_invoice, "%-*s", 20, "Stkpris (m. rabat)");
            printf("%-*s", 20, "Stkpris (m. rabat)");
            fprintf(fp_invoice, "%-*s", 20, "Saldo");
            printf("%-*s", 20, "Saldo");
            fprintf(fp_invoice, "%-*s", 20, "Saldo (m. rabat)");
            printf("%-*s", 20, "Saldo (m. rabat)");

            fprintf(fp_invoice, "\n");
            printf("\n");

            // continue;
        }

        product_price_discount = product_price - (15.0/100.0)*product_price;
        price_of_products = product_qty*product_price;
        price_of_products_discount = product_qty*product_price_discount;
        
        //printing to output
        fprintf(fp_invoice, "%-*s", 20, product_name);
        printf("%-*s", 20, product_name);
        fprintf(fp_invoice, "%-*d", 20, product_qty);
        printf("%-*d", 20, product_qty);
        fprintf(fp_invoice, "%-*.2f", 20, product_price);
        printf("%-*.2f", 20, product_price);
        fprintf(fp_invoice, "%-*.2f", 20, product_price_discount);
        printf("%-*.2f", 20, product_price_discount);
        fprintf(fp_invoice, "%-*.2f", 20, price_of_products);
        printf("%-*.2f", 20, price_of_products);
        fprintf(fp_invoice, "%-*.2f", 20, price_of_products_discount);
        printf("%-*.2f", 20, price_of_products_discount);

        //calculations discount
        if (product_qty > 10) {
            price_of_products = price_of_products_discount;
        }

        sum += price_of_products;

        fprintf(fp_invoice, "\n");
        printf("\n");        
    }  

    fprintf(fp_invoice, "Total price: %.2f\n", sum);
    printf("Total price: %.2f\n", sum );

    // fflush(fp_invoice);

    //close file connection
    fclose(fp_order);
    fclose(fp_invoice);

    //prevent prompt from closing
    // system("pause");
  
    return 0;
}
