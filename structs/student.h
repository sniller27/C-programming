typedef struct {
  int *array;
  int used;
  int size;
} int_Array;

struct Student {
    char student_no[20];
    char firstname[1000];
    char lastname[1000];
    int phone;
    int_Array grades;
    float avr_grade;
};