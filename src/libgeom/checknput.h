#define ERROR_AFTER_FUNC 10
#define ERROR_IN_PARAMS 11
#define ERROR_IN_SYNTAX 12
#define ERROR_IN_ARGUE 13

typedef struct CharVector {
    char* data;
    size_t size;
    size_t capacity;
} CharVector;

CharVector* char_vector_new(size_t capacity);

int char_vector_push_back(CharVector* v, char item);

void char_vector_free(CharVector* v);

int check_syntax(char* mass, int len);

int string_to_number(char* mass, double* out, int len);

int check_and_put(char* mass, double* out, int n, int len);