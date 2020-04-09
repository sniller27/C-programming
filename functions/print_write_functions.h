//print and write functions (size of char-array should probably be passed as well)
void print_write_string(char text[255], FILE* w_file) {

    printf(text);
    fprintf(w_file, text);
    
}

void print_write_float(char text[255], float float_value, FILE* w_file) {

    printf(text, 20, float_value);
    fprintf(w_file, text, 20, float_value);
    
}

void print_write_int(char text[255], int int_value, FILE* w_file) {

    printf(text, int_value);
    fprintf(w_file, text, int_value);
    
}

//print and write arrays
void print_write_float_array(int array_size, float *float_array, FILE* w_file) {

    for (int i = 0; i < array_size; ++i) {
        print_write_float("%-*.2f  \n", float_array[i], w_file);
    }
    
}