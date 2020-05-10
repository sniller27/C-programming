
void print_student_data(int size, struct Student students[], FILE* output_file){

    for (int i = 0; i < size; i++)
    {
        print_write_string_arg("student no: %s \n", students[i].student_no, output_file);
        print_write_string_arg("first name: %s \n", students[i].firstname, output_file);
        print_write_string_arg("last name: %s \n", students[i].lastname, output_file);
        print_write_int("phone: %d \n", students[i].phone, output_file);

        for (int j = 0; j < students[i].grades.used; j++)
        {
            print_write_int("grade: %d \n", students[i].grades.array[j], output_file);
        }

        print_write_string("\n", output_file);
    }
    
}

void print_student_data_index(int size, struct Student students[], int indexes[], FILE* w_file){

    for (int i = 0; i < size; i++)
    {
        print_write_string_arg("student no: %s \n", students[indexes[i]].student_no, w_file);
        print_write_string_arg("first name: %s \n", students[indexes[i]].firstname, w_file);
        print_write_string_arg("last name: %s \n", students[indexes[i]].lastname, w_file);
        print_write_int("phone: %d \n", students[indexes[i]].phone, w_file);

        for (int j = 0; j < students[indexes[i]].grades.used; j++)
        {
            print_write_int("grade: %d \n", students[indexes[i]].grades.array[j], w_file);
        }

        print_write_string("\n", w_file);
    }
    
}