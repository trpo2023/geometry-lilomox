#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IntVector {
    char* data;
    size_t size;
    size_t capacity;
} IntVector;

IntVector* int_vector_new(size_t capacity);

int int_vector_push_back(IntVector* v, char item);

void p_arr(double* arr, int n);

void int_vector_free(IntVector* v);

int check_syntax(char* mass, int len);

int string_to_number(char* mass, double* out, int len);

int check_and_put(char* mass, double* out, int n, int len);