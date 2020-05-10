//integer array struct (used in Student struct etc.)
typedef struct {
  int *array;
  int used;
  int size;
} int_Array;

//student struct (used in Student array struct etc.)
struct Student {
    char student_no[20];
    char firstname[100];
    char lastname[100];
    int phone;
    int_Array grades;
    float avr_grade;
};

//struct array struct
typedef struct {
    struct Student *array;
    int used;
    int size;
} Student_Array;
