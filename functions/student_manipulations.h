// inserts a new student in a student array according to the firstname (student array must already be sorted!)
// expects student array and data for new student (student id, firstname, lastname, phone and grades)
// The function does not take same firstnames or lastnames into consideration
void insert_student_by_name(Student_Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int_Array *grades) {

    //checks if student array should be extended
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    }

    for (int i = 0; i < a->used; i++)
    {

        // compares the firstname to other firstname by using strcmp. if strcmp returns -1 then the index should fit the firstname alphabetically.
        if (strcmp(firstname, a->array[i].firstname) == -1)
        {
            // moves indexes after fitting position to make space for the new student
            for (int j = a->used; j > i; j--)
            {
                a->array[j] = a->array[j-1];
            }

            // assigns student data to empty index (which is not completely empty...)
            strcpy(a->array[i].student_no, stud_id);
            strcpy(a->array[i].firstname, firstname);
            strcpy(a->array[i].lastname, lastname);

            a->array[i].phone = phone;
            
            //resets used values (due to already existing values in index)
            a->array[i].grades.used = 0;

            for (int j = 0; j < grades->used; j++)
            {
                insert_int_Array(&a->array[i].grades, grades->array[j]);
            }
            
            // increment to indicate new student has been added to student array
            a->used++;
            
            break;
        }
        
    }

}

// removes a student from a given student array according to the student_id of the student
// function expects a student array and a student_id of a student
void remove_student_by_id(Student_Array *a, char stud_id[50]) {

    for (int i = 0; i < a->used; i++)
    {

        if (strcmp(stud_id, a->array[i].student_no) == 0)
        {

            //remove student by "moving" everyone after the student 1 time in direction of the student's location. Thus student is overwritten.
            for (int j = i; j < a->used-1; j++)
            {
                a->array[j] = a->array[j+1];
            }

            // decrement number of students in array            
            a->used--;
            
            break;
        }
        
    }

}
