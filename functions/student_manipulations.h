void insert_student_by_name(Student_Array *a, char stud_id[50], char firstname[50], char lastname[50], int phone, int_Array *grades) {


    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct Student *)realloc(a->array, a->size * sizeof(struct Student));
    }

    for (int i = 0; i < a->used; i++)
    {

        //Tager ikke hensyn til andre med samme navn og sorterer ikke efter efternavn!
        if (strcmp(firstname, a->array[i].firstname) == -1)
        {

            for (int j = a->used; j > i; j--)
            {
                a->array[j] = a->array[j-1];
            }

            strcpy(a->array[i].student_no, stud_id);
            strcpy(a->array[i].firstname, firstname);
            strcpy(a->array[i].lastname, lastname);

            a->array[i].phone = phone;
            
            //resets used values (due to existing values in index)
            a->array[i].grades.used = 0;

            for (int j = 0; j < grades->used; j++)
            {
                insert_int_Array(&a->array[i].grades, grades->array[j]);
            }
            
            a->used++;
            
            break;
        }
        
    }

}

void remove_student_by_id(Student_Array *a, char stud_id[50]) {

    for (int i = 0; i < a->used; i++)
    {

        if (strcmp(stud_id, a->array[i].student_no) == 0)
        {

            //remove student
            for (int j = i; j < a->used-1; j++)
            {
                a->array[j] = a->array[j+1];
            }

            // free(a->array[10]);
            
            a->used--;
            
            break;
        }
        
    }

}
