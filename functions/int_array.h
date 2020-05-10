// kilde: https://stackoverflow.com/questions/3536153/c-dynamically-growing-array
void init_int_Array(int_Array *a, int initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insert_int_Array(int_Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void free_int_Array(int_Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}