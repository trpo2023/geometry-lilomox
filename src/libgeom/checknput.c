#include <libgeom/checknput.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int check(char* mass, int n, int len)
{
    len--;
    int point = 0, zap = 0, lscobe = 0, rscobe = 0, probls = 0, minus = 0;
    for (int i = 0; i < len; i++) {
        if (mass[i] == ' ') {
            probls++;
        }
        if (mass[i] == '.') {
            point++;
        }
        if (mass[i] == ',') {
            zap++;
        }
        if (mass[i] == '(') {
            rscobe++;
        }
        if (mass[i] == ')') {
            lscobe++;
            if (mass[i + 1] != '\n') {
                printf("%s", mass);
                printf("After function circle must be empty\n");
                return 0;
            }
        }
        if (mass[i] == '-') {
            minus++;
        }
    }
    if (point > 3 || zap > 1 || zap < 1 || lscobe > 1 || lscobe < 1
        || rscobe > 1 || lscobe < 1 || probls < 1 || minus > 2) {
        printf("%s", mass);
        printf("Error in %d params\n", n);
        return 0;
    }
    if (!(mass[0] == 'c' && mass[1] == 'i' && mass[2] == 'r' && mass[3] == 'c'
          && mass[4] == 'l' && mass[5] == 'e' && mass[6] == '(')) {
        printf("%s", mass);
        printf("Error in %d 'circle'\n", n);
        return 0;
    }
    int eror = 0;
    int place = 7;
    while (mass[place] != ',') {
        if (mass[place] == ' ') {
            eror++;
        }
        place++;
    }
    if (eror == 0) {
        printf("%s", mass);
        printf("Error in %d params\n", n);
        return 0;
    }
    return 1;
}

void put(char* mass, double* out, int n, int len)
{
    len--;
    char array[len - 8];
    int count = 0;
    for (int i = 7; i < len; i++) {
        array[count] = mass[i];
        count++;
    }
    IntVector* first = int_vector_new(30);
    IntVector* second = int_vector_new(30);
    IntVector* third = int_vector_new(30);
    for (int i = 0; array[i] != ' '; i++) {
        int_vector_push_back(first, array[i]);
    }
    for (int i = first->size; array[i] != ','; i++) {
        int_vector_push_back(second, array[i]);
    }
    int p = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] == ' ') {
            p = i;
        }
    }
    int z = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] == ',') {
            z = i;
        }
    }
    if (p < z) {
        p = z + 1;
    }
    for (int i = p; i < len - 1; i++) {
        int_vector_push_back(third, array[i]);
    }
    out[0] = atof(first->data);
    out[1] = atof(second->data);
    out[2] = atof(third->data);
    if (out[2] < 0) {
        printf("%s", mass);
        printf("in %d string {%lf} must be unsigned\n", n, out[2]);
        int_vector_free(first);
        int_vector_free(second);
        int_vector_free(third);
        exit(1);
    }
    int_vector_free(first);
    int_vector_free(second);
    int_vector_free(third);
}

int check_and_put(char* mass, double* out, int n, int len)
{
    int test = check(mass, n, len);
    if (test == 1) {
        put(mass, out, n, len);
        return 1;
    }
    return 0;
}
