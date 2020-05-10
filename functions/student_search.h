// searches for students with a given lastname and print their information
// function expects student array, its size, a given lastname and a filepointer for writing to file
void search_students_lastname(int size, struct Student students[], char lastname[50], FILE* output_file){

    for (int i = 0; i < size; i++)
    {
        if(strcmp(students[i].lastname, lastname) == 0) {
            print_student_data(1, &students[i], output_file);
        }
    }

}
