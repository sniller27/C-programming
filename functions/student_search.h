void search_students_lastname(int size, struct Student students[], char lastname[50]){

    for (int i = 0; i < size; i++)
    {
        if(strcmp(students[i].lastname, lastname) == 0) {
            print_student_data(1, &students[i]);
        }
    }

}
