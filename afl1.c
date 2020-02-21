#include <stdio.h> /* printf, sprintf */
#include <stdlib.h>

int main(int argc,char *argv[])
{

    //variables
    FILE* fp = fopen("bestilling.txt","r"); 
    char str1[10], str2[10], str3[10];
    int val1, val2;


    // int price_reading = 0;
    int sum = 0;
    int total_price = 0;

    //check if file exists 
    if (fp==NULL) 
    { 
        printf("no such file."); 
        return 0; 
    }





    // save data in program memory
    // char* data[100]; 
    // while (fscanf(fp,"%*s %s ",&data)==1) {
        
    // printf("%s\n", data);
    // sum += (int) &data;

    // }

    // printf("sum: %d\n", sum);





    // char data1[100];
    // char data2[100];
    // while (fscanf(fp,"%s %s ", &data1, &data2)==1) {
        
    //     printf("%s\n", data1);
    //     printf("%s\n", data2);

    // }


    //write to file
    char new_product_name[255];
    int new_product_price[255];

    // printf("Enter product name:"); 
    // scanf("%s", &new_product_name);
    
    // printf("Enter product price:"); 
    // scanf("%d", &new_product_price);

    //read from file
    char buff[255];
    int buff2;

    //buff2 peger vi på en memory adresse (og det gør buff automatisk)
    while(fscanf(fp, "%s %d", buff, &buff2)!=EOF){  
        
        printf("Produkt: %s \n", buff );
        printf("Pris: %d \n", buff2 );

        sum += buff2;
        
    }  

    printf("Total price: %d\n", sum );





    //close file connection
    fclose(fp);

    //prevent prompt from closing
    // system("pause");
  
    return 0;
}
