#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeom/checknput.h>

CharVector* char_vector_new(size_t capacity)
{
    CharVector* darr = (CharVector*)malloc(sizeof(CharVector));
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

int char_vector_push_back(CharVector* v, char item)
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

void char_vector_free(CharVector* v)
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
                return ERROR_AFTER_FUNC;
            }
        }
        if (mass[i] == '-') {
            minus++;
        }
    }
    if (point > 3 || comma > 1 || comma < 1 || left_bracket > 1
        || left_bracket < 1 || right_bracket > 1 || left_bracket < 1
        || space < 1 || minus > 2) {
        return ERROR_IN_PARAMS;
    }
    if (!(mass[0] == 'c' && mass[1] == 'i' && mass[2] == 'r' && mass[3] == 'c'
          && mass[4] == 'l' && mass[5] == 'e' && mass[6] == '(')) {
        return ERROR_IN_SYNTAX;
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
        return ERROR_IN_ARGUE;
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
    CharVector* x = char_vector_new(30);
    CharVector* y = char_vector_new(30);
    CharVector* radius = char_vector_new(30);
    for (int i = 0; array[i] != ' '; i++) {
        char_vector_push_back(x, array[i]);
    }
    for (int i = x->size; array[i] != ','; i++) {
        char_vector_push_back(y, array[i]);
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
        char_vector_push_back(radius, array[i]);
    }
    out[0] = atof(x->data);
    out[1] = atof(y->data);
    out[2] = atof(radius->data);
    if (out[2] < 0) {
        char_vector_free(x);
        char_vector_free(y);
        char_vector_free(radius);
        return 0;
    }
    char_vector_free(x);
    char_vector_free(y);
    char_vector_free(radius);
    return 1;
}

int check_and_put(char* mass, double* out, int n, int len)
{
    int test = check_syntax(mass, len - 1);
    if (test == 1) {
        int tmp = string_to_number(mass, out, len - 1);
        if (tmp == 0) {
            printf("%s", mass);
            printf("in %d string {%lf} must be unsigned\n", n, out[2]);
            return 0;
        } else if (tmp == 1) {
            return 1;
        }
    } else if (test == ERROR_AFTER_FUNC) {
        printf("%s", mass);
        printf("After function circle must be empty\n");
    } else if (test == ERROR_IN_PARAMS) {
        printf("%s", mass);
        printf("Error in %d params\n", n);
    } else if (test == ERROR_IN_SYNTAX) {
        printf("%s", mass);
        printf("Error in %d 'circle'\n", n);
    } else if (test == ERROR_IN_ARGUE) {
        printf("%s", mass);
        printf("Error in %d params\n", n);
    }
    return 1;
}
