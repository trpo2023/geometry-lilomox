#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeom/checknput.h>

IntVector* int_vector_new(size_t capacity)
{
    IntVector* darr = (IntVector*)malloc(sizeof(IntVector));
    if (darr == NULL) {
        return NULL;
    }
    darr->size = 0;
    darr->capacity = capacity;
    darr->data = (char*)calloc(capacity, sizeof(char));
    if (darr->data == NULL) {
        free(darr);
        return NULL;
    }
    return darr;
}

int int_vector_push_back(IntVector* v, char item)
{
    int flag = -1;
    if (v->size == v->capacity) {
        v->data = (char*)realloc(v->data, v->size * 2);
        if (v->data != NULL) {
            v->data[v->size] = item;
            v->capacity = v->size * 2;
            flag = 0;
        } else {
            flag = -1;
        }

    } else {
        v->data[v->size] = item;
        flag = 0;
    }
    v->size++;
    return flag;
}

void p_arr(double* arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void int_vector_free(IntVector* v)
{
    free(v->data);
    v->data = NULL;
    free(v);
    v = NULL;
}

int check_syntax(char* mass, int len)
{
    int point = 0, comma = 0, left_bracket = 0, right_bracket = 0, space = 0,
        minus = 0;
    for (int i = 0; i < len; i++) {
        if (mass[i] == ' ') {
            space++;
        }
        if (mass[i] == '.') {
            point++;
        }
        if (mass[i] == ',') {
            comma++;
        }
        if (mass[i] == '(') {
            right_bracket++;
        }
        if (mass[i] == ')') {
            left_bracket++;
            if (mass[i + 1] != '\n') {
                return 10;
            }
        }
        if (mass[i] == '-') {
            minus++;
        }
    }
    if (point > 3 || comma > 1 || comma < 1 || left_bracket > 1
        || left_bracket < 1 || right_bracket > 1 || left_bracket < 1
        || space < 1 || minus > 2) {
        return 11;
    }
    if (!(mass[0] == 'c' && mass[1] == 'i' && mass[2] == 'r' && mass[3] == 'c'
          && mass[4] == 'l' && mass[5] == 'e' && mass[6] == '(')) {
        return 12;
    }
    int eror = 0;
    int place_of_arguments = 7;
    while (mass[place_of_arguments] != ',') {
        if (mass[place_of_arguments] == ' ') {
            eror++;
        }
        place_of_arguments++;
    }
    if (eror == 0) {
        return 13;
    }
    return 1;
}

int string_to_number(char* mass, double* out, int len)
{
    char array[len - 8];
    int count = 0;
    for (int i = 7; i < len; i++) {
        array[count] = mass[i];
        count++;
    }
    IntVector* x = int_vector_new(30);
    IntVector* y = int_vector_new(30);
    IntVector* radius = int_vector_new(30);
    for (int i = 0; array[i] != ' '; i++) {
        int_vector_push_back(x, array[i]);
    }
    for (int i = x->size; array[i] != ','; i++) {
        int_vector_push_back(y, array[i]);
    }
    int place_of_space = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] == ' ') {
            place_of_space = i;
        }
    }
    int place_of_comma = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] == ',') {
            place_of_comma = i;
        }
    }
    if (place_of_space < place_of_comma) {
        place_of_space = place_of_comma + 1;
    }
    for (int i = place_of_space; i < len - 1; i++) {
        int_vector_push_back(radius, array[i]);
    }
    out[0] = atof(x->data);
    out[1] = atof(y->data);
    out[2] = atof(radius->data);
    if (out[2] < 0) {
        int_vector_free(x);
        int_vector_free(y);
        int_vector_free(radius);
        return 1;
    }
    int_vector_free(x);
    int_vector_free(y);
    int_vector_free(radius);
    return 0;
}

int check_and_put(char* mass, double* out, int n, int len)
{
    int test = check_syntax(mass, len - 1);
    if (test == 1) {
        int tmp = string_to_number(mass, out, len - 1);
        if (tmp == 1) {
            printf("%s", mass);
            printf("in %d string {%lf} must be unsigned\n", n, out[2]);
            return 0;
        } else if (tmp == 0) {
            return 1;
        }
    } else if (test == 10) {
        printf("%s", mass);
        printf("After function circle must be empty\n");
    } else if (test == 11) {
        printf("%s", mass);
        printf("Error in %d params\n", n);
    } else if (test == 12) {
        printf("%s", mass);
        printf("Error in %d 'circle'\n", n);
    } else if (test == 13) {
        printf("%s", mass);
        printf("Error in %d params\n", n);
    }
    return 0;
}
