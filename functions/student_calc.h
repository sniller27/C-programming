float calc_avg_grade(struct Student students){

    float total_grade = 0, grade_avr;

    for (int j = 0; j < students.no_of_grades; j++)
    {
        total_grade += students.grades.array[j];
    }

    grade_avr = total_grade/students.no_of_grades;

    students.avr_grade = grade_avr;
    
    return grade_avr;
}

void highest_grades_info(int size, struct Student students[], int highest_grade_indexes[size], int *array_size){

    int index_counter = 0;

    float highest_grade_avr, 
    grade_avr;

    for (int i = 0; i < size; i++)
    {
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        if(i==0){
            highest_grade_avr = grade_avr;
            highest_grade_indexes[index_counter] = i;
            index_counter++;
        }

        if(grade_avr > highest_grade_avr){
            highest_grade_avr = grade_avr;
            //empty array indexes

            //new index counter
            index_counter = 0;

            //new max value
            highest_grade_indexes[index_counter] = i;

            index_counter++;
        } else if(grade_avr == highest_grade_avr){
            //add to indexes
            highest_grade_indexes[index_counter] = i;
            index_counter++;
        }

    }

    *array_size = index_counter;

}

void value_below_avr_grade_info(int size, struct Student students[], int low_grade_indexes[size], int *array_size, int value){

    int index_counter = 0;
    float grade_avr;

    for (int i = 0; i < size; i++)
    {
    
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        if(grade_avr < value){
            //print_info
            // print_student_data(1, &students[i]);
            low_grade_indexes[index_counter] = i;
            index_counter++;
        }

    }

    *array_size = index_counter;

}

int value_above_avr_grade_info(int size, struct Student students[], int value){

    float grade_avr;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        if(grade_avr > value){
            count ++;
        }

    }

    return count;
}

void print_students_with_top_grade(int size, struct Student students[]){

    int grade_occurence = 0;

    for (int i = 0; i < size; i++)
    {
        grade_occurence = 0;

        for (int j = 0; j < students[i].no_of_grades; j++)
        {
            if(students[i].grades.array[j] == 12){
                grade_occurence++;
            }
        }

        if(grade_occurence > 0) {
            print_student_data(1, &students[i]);
            printf("%s has %d max grades in total \n", students[i].firstname, grade_occurence);
            printf("\n");
        }

    }

}

float avr_grade_students_total(int size, struct Student students[]){

    float students_avr = 0;

    for (int i = 0; i < size; i++)
    {
        students_avr += students[i].avr_grade;
    }

    return students_avr/size;

}



