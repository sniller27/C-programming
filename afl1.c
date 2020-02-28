#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100 
#define OE "\x9B"

int main(int argc,char *argv[])
{
    // setlocale(LC_ALL, "en_US.UTF-8");
    // setlocale(LC_ALL, 'da, DK');
    // setlocale(LC_TIME, "Danish");
    // setlocale (LC_ALL, "C");
    // char *locale = setlocale(LC_ALL, "");

    //solves æøå problem by switching character encoding to UTF-8 (from stdlib) [kan køre batch-kommandoer herfra direkte]
    //æøå ser ud til at være et problem med windows DOS-konsoller
    system("CHCP 65001");

    //variables
    FILE* fp_order = fopen("bestilling.txt","r"); 

    // int price_reading = 0;
    float sum = 0;
    float total_price_clean = 0;
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
    // char product_qty_header[MAX], product_name_header[MAX], product_price_header[MAX];

    //read from file
    char product_name_header[20], product_qty_header[20], product_price_header[20];
    fscanf(fp_order, "%s %s %s",product_name_header, product_qty_header, product_price_header);

    //headers
    printf("%-*s", 20, product_name_header);
    fprintf(fp_invoice, "%-*s", 20, product_name_header);

    printf("%-*s", 20, product_qty_header);
    fprintf(fp_invoice, "%-*s", 20, product_price_header);

    printf("%-*s", 20, product_price_header);
    fprintf(fp_invoice, "%-*s", 20, "Stkpris");

    printf("%-*s", 20, "Stkpris (m. rabat)");
    fprintf(fp_invoice, "%-*s", 20, "Stkpris (m. rabat)");

    printf("%-*s", 20, "Saldo");
    fprintf(fp_invoice, "%-*s", 20, "Saldo");

    printf("%-*s", 20, "Saldo (m. rabat)");
    fprintf(fp_invoice, "%-*s", 20, "Saldo (m. rabat)");

    fprintf(fp_invoice, "\n");
    printf("\n");
    
    //continue reading from file
    //product_name peger vi på en memory adresse (og det gør product_qty automatisk)
    while(fscanf(fp_order, "%d %s %f", &product_qty, product_name, &product_price)!=EOF){
        readfile_counter++;

        if(readfile_counter == 1) {
            //printf("hello: %-*d %-*s %-*f", 20, product_qty, product_name, product_price);
            
            // printf("%-*s", 20, gcvt(product_qty, 6, product_qty_header));
            // printf("%-*s", 20, product_name);
            // printf("%-*.2f", 20, product_price);

            // fprintf(fp_invoice, "%-*s", 20, "Varenavn");
            // printf("%-*s", 20, "Varenavn");
            // fprintf(fp_invoice, "%-*s", 20, "Antal");
            // printf("%-*s", 20, "Antal");
            // fprintf(fp_invoice, "%-*s", 20, "Stkpris");
            // printf("%-*s", 20, "Stkpris");
            // fprintf(fp_invoice, "%-*s", 20, "Stkpris (m. rabat)");
            // printf("%-*s", 20, "Stkpris (m. rabat)");
            // fprintf(fp_invoice, "%-*s", 20, "Saldo");
            // printf("%-*s", 20, "Saldo");
            // fprintf(fp_invoice, "%-*s", 20, "Saldo (m. rabat)");
            // printf("%-*s", 20, "Saldo (m. rabat)");

            // fprintf(fp_invoice, "\n");
            // printf("\n");

            // continue;
        }

        product_price_discount = product_price - (15.0/100.0)*product_price;
        price_of_products = product_qty*product_price;
        price_of_products_discount = product_qty*product_price_discount;

        // if(strchr(product_name, OE) != NULL)
        // {
        //     printf("LOOOOOOOOOOOOLZ");
        // }
        
        // printf("ø != " OE "\n");

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
        

        //calculations discount
        if (product_qty > 10) {
            // price_of_products = price_of_products_discount;

            fprintf(fp_invoice, "%-*.2f", 20, price_of_products_discount);
            printf("%-*.2f", 20, price_of_products_discount);
            sum += price_of_products_discount;
        } else {
            fprintf(fp_invoice, "%-*.2f", 20, price_of_products);
            printf("%-*.2f", 20, price_of_products);
            sum += price_of_products;
        }

        total_price_clean += price_of_products;
        

        fprintf(fp_invoice, "\n");
        printf("\n");        
    }  

    fprintf(fp_invoice, "Total pris: %.2f\n", total_price_clean);
    printf("Total pris: %.2f\n", total_price_clean);

    fprintf(fp_invoice, "Total pris med rabat: %.2f\n", sum);
    printf("Total pris med rabat: %.2f\n", sum );

    fprintf(fp_invoice, "(Rabat: %.2f)\n", total_price_clean-sum);
    printf("(Rabat: %.2f)\n", total_price_clean-sum);

    // fflush(fp_invoice);

    //close file connection
    fclose(fp_order);
    fclose(fp_invoice);

    //prevent prompt from closing
    // system("pause");
  
    return 0;
}
