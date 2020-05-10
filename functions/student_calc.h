// calculates average grade by adding all grades of a student and then dividing by the number of grades.
// functions expect af student struct as parameter. The functions returns the average grade of the student as a float.
float calc_avg_grade(struct Student students){

    float total_grade = 0, grade_avr;

    for (int j = 0; j < students.grades.used; j++)
    {
        total_grade += students.grades.array[j];
    }

    grade_avr = total_grade/students.grades.used;

    students.avr_grade = grade_avr;
    
    return grade_avr;
}

// function determines student/students with highest grades and adds their indexes to integer array passed to function (which is returned indirectly by pass-by-reference)
// functions expects a student array, its size, an integer array for indexes and its size
void highest_grades_info(int size, struct Student students[], int highest_grade_indexes[size], int *array_size){

    int index_counter = 0;

    float highest_grade_avr, 
    grade_avr;

    // iterates through students average grades
    for (int i = 0; i < size; i++)
    {
        // if student doesn't have an average grade then it's calculated and added to student struct
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        // upon first iteration the highest grade is assigned tentatively
        if(i==0){
            highest_grade_avr = grade_avr;
            highest_grade_indexes[index_counter] = i;
            index_counter++;
        }

        // if other avr. grade is higher then this will become the new highest grade 
        // (thus indexcounter is reset to ensure value is placed in first index of array)
        if(grade_avr > highest_grade_avr){
            highest_grade_avr = grade_avr;
            //empty array indexes

            //new index counter
            index_counter = 0;

            //new max value
            highest_grade_indexes[index_counter] = i;

            index_counter++;
        } else if(grade_avr == highest_grade_avr){
            //if someone else has the same highest grade then their index will be added to the integer array as well
            highest_grade_indexes[index_counter] = i;
            index_counter++;
        }

    }

    // array size for indexes is passed to parameter
    *array_size = index_counter;
}

// function determines indexes of students with avr. grade below a given grade (as parameter)
// function expecs a student array, its size, an integer array for index and its size
void value_below_avr_grade_info(int size, struct Student students[], int low_grade_indexes[size], int *array_size, int value){

    int index_counter = 0;
    float grade_avr;

    // iterates through student array
    for (int i = 0; i < size; i++)
    {
        // if student doesn't have an average grade then it's calculated and added to student struct
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        // if student has avr. grade below the given value then the index of the student is added to the passed integer array.
        if(grade_avr < value){
            low_grade_indexes[index_counter] = i;
            index_counter++;
        }

    }

    // array size for indexes is passed to parameter
    *array_size = index_counter;
}

// function determines number of students with avr. grade above a given grade (as parameter)
// function expecs a student array, its size and a given integer value (the grade)
// returns the number as an integer
int value_above_avr_grade_info(int size, struct Student students[], int value){

    float grade_avr;
    int count = 0;

    // iterates through student array
    for (int i = 0; i < size; i++)
    {
        // if student doesn't have an average grade then it's calculated and added to student struct
        if(!students[i].avr_grade){
            students[i].avr_grade = calc_avg_grade(students[i]);
        }

        grade_avr = students[i].avr_grade;

        // if students avr. grade is above the given value (grade) then the counter increments
        if(grade_avr > value){
            count ++;
        }

    }

    // the total number of students with avr. grade above the given value is returned. which is the counter.
    return count;
}

// function determines which students have a top-grade (12) and then prints the information about them.
// function expectes as student array, its size and a filepointer for writing to file. the function returns nothing.
void print_students_with_top_grade(int size, struct Student students[], FILE* output_file){

    int grade_occurence = 0;

    // iterates through student array
    for (int i = 0; i < size; i++)
    {
        grade_occurence = 0;

        // checks if one of a student grade is a top-grade. If it is then its counted by incrementing a counter.
        for (int j = 0; j < students[i].grades.used; j++)
        {
            if(students[i].grades.array[j] == 12){
                grade_occurence++;
            }
        }

        // if the student has any top-grades (the counter is more than 0) then their information will be printed to console and file.
        // the number of top-grades will also be printed, which is the counter.
        if(grade_occurence > 0) {
            print_student_data(1, &students[i], output_file);
            
            printf("%s has %d max grades in total \n", students[i].firstname, grade_occurence);
            fprintf(output_file, "%s has %d max grades in total \n", students[i].firstname, grade_occurence);

            print_write_string("\n", output_file);
        }

    }

}

// function determines average grade of all students
// this is done by summing up all average grades of students and then dividing by the number of students.
// the function returns the total average grade as a float
float avr_grade_students_total(int size, struct Student students[]){

    float students_avr = 0;

    for (int i = 0; i < size; i++)
    {
        students_avr += students[i].avr_grade;
    }

    return students_avr/size;

}



