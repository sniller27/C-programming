#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
    //assigning variables
    float sum = 0, 
    total_price_clean = 0, 
    price_of_products, 
    price_of_products_discount, 
    product_price, 
    product_price_discount;
    
    int product_qty;

    char product_name[255], 
    product_name_header[20], 
    product_qty_header[20], 
    product_price_header[20];

    //solves æøå problem by switching character encoding to UTF-8 (from stdlib) [kan køre batch-kommandoer herfra direkte]
    //æøå seems to be a problem related to Windows DOS-consoles (although it messes with console indentation)
    system("CHCP 65001");

    //instatiate filepointer instance (one for reading and one for writing)
    FILE* fp_order = fopen("bestilling.txt","r"); 
    FILE* fp_invoice = fopen("faktura.txt", "w");

    //error checking filepointers
    if (fp_order==NULL || fp_invoice==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    }

    //reading headers from 1st line in file and save them to variables
    fscanf(fp_order, "%s %s %s",product_name_header, product_qty_header, product_price_header);

    //printing headers to console and writing to them to file
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
    
    //reading file through iterations
    //NOTE: product_name points to a memory adress (product_qty does it automatically)
    while(fscanf(fp_order, "%d %s %f", &product_qty, product_name, &product_price)!=EOF){

        //calculation of discount
        product_price_discount = product_price - (15.0/100.0)*product_price;
        price_of_products = product_qty*product_price;
        price_of_products_discount = product_qty*product_price_discount;

        //printing and writing data from file to console and other file
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

        //check qty for discount and adds to total price (with discount)
        if (product_qty > 10) {

            fprintf(fp_invoice, "%-*.2f", 20, price_of_products_discount);
            printf("%-*.2f", 20, price_of_products_discount);

            //adds discount price
            sum += price_of_products_discount;

        } else {

            fprintf(fp_invoice, "%-*.2f", 20, price_of_products);
            printf("%-*.2f", 20, price_of_products);

            //adds non-discount price
            sum += price_of_products;

        }

        //add to total price
        total_price_clean += price_of_products;

        fprintf(fp_invoice, "\n");
        printf("\n");        
    }  

    //printing and writing total/accumulated prices
    fprintf(fp_invoice, "Total pris: %.2f\n", total_price_clean);
    printf("Total pris: %.2f\n", total_price_clean);

    fprintf(fp_invoice, "Total pris med rabat: %.2f\n", sum);
    printf("Total pris med rabat: %.2f\n", sum );

    fprintf(fp_invoice, "(Rabat: %.2f)\n", total_price_clean-sum);
    printf("(Rabat: %.2f)\n", total_price_clean-sum);

    //close file connections
    fclose(fp_order);
    fclose(fp_invoice);
  
    return 0;
}
