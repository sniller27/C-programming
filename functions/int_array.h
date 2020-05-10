// kilde: https://stackoverflow.com/questions/3536153/c-dynamically-growing-array

// intializes integer array with memory allocated, spaces used and size
void init_int_Array(int_Array *a, int initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

// inserts integer into array and updates array size if necessary
void insert_int_Array(int_Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

// free memory in integer array
void free_int_Array(int_Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}