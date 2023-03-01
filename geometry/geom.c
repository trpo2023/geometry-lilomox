#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


typedef struct IntVector{
    char* data;
    size_t size;
    size_t capacity;
}IntVector;

IntVector* int_vector_new(size_t capacity) {
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

int int_vector_push_back(IntVector* v, char item) {
    int flag = -1;
    if (v->size == v->capacity) {
        v->data = (char*)realloc(v->data, v->size*2);
        if (v->data != NULL) {
            v->data[v->size] = item;
            v->capacity = v->size*2;
            flag = 0;
        }else {
            flag = -1;
        }
        
    }else {
        v->data[v->size] = item;
        flag = 0;
    }
    v->size++;
    return flag;
}

void p_arr(double *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%lf ", arr[i]);
	}
	printf("\n");
}


void int_vector_free(IntVector* v) {
    free(v->data);
    v->data = NULL;
    free(v);
    v = NULL;

}

void check_and_put(char *mass, double *out, int n) {
	int len = strlen(mass);
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
		}
		if (mass[i] == '-') {
			minus++;
		}
	}
	if (point > 3 || zap > 1 || zap < 1 || lscobe > 1 || lscobe < 1 || rscobe > 1 || lscobe < 1 || probls < 1 || minus > 2) {
		printf("Error in %d params\n", n);
		exit(1);
	}
	if (!(mass[0] == 'c' && mass[1] == 'i' && mass[2] == 'r' && mass[3] == 'c' && mass[4] == 'l' && mass[5] == 'e' && mass[6] == '(')) {
		printf("Error in %d 'circle'\n", n);
		exit(1);
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
		printf("Error in %d params\n", n);
		exit(-1);
	}
	char array[len-8];
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
		p = z+1;
	}
	for (int i = p; i < len-1; i++) {
		int_vector_push_back(third, array[i]);
	}

	out[0] = atof(first->data);
	out[1] = atof(second->data);
	out[2] = atof(third->data);
	if (out[2] < 0) {
		printf("in %d string last number must be unsigned\n", n);
		int_vector_free(first);
		int_vector_free(second);
		int_vector_free(third);
		exit(1);
	}
	int_vector_free(first);
	int_vector_free(second);
	int_vector_free(third);
}


int main()
{
	FILE *file;
	file = fopen("geommi.txt", "r");
	char mass[100], darr[100], dd[100];
	fgets(mass, sizeof(mass), file);
	fgets(darr, sizeof(darr), file);
	fgets(dd, sizeof(dd), file);
	
	printf("%s", mass);
	printf("%s", darr);
	printf("%s", dd);

	double out1[3], out2[3], out3[3];
	check_and_put(mass, out1, 1);
	check_and_put(darr, out2, 2);
	check_and_put(dd, out3, 3);

	fclose(file);
}
