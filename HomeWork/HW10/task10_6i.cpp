#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    double *elements;
} Vector;





void input_vector(Vector *v) {
    printf("Enter the size of the vector (positive integer): ");
    if (scanf("%zu", &v->size) != 1 || v->size == 0) {
        printf("Error: The size must be a positive integer.\n");
        v->size = 0;
        v->elements = NULL;
        return;
    }


    v->elements = (double *)malloc(v->size * sizeof(double));
    if (v->elements == NULL) {
        printf("Error: Failed to allocate memory.\n");
        v->size = 0;
        return;
    }

    printf("Enter %zu real elements of the vector:\n", v->size);
    for (size_t i = 0; i < v->size; i++) {
        printf("Element [%zu]: ", i + 1);
        scanf("%lf", &v->elements[i]);
    }
}


void print_vector(const Vector *v) {
    if (v == NULL || v->elements == NULL || v->size == 0) {
        printf("Error: The vector is empty or not initialized.\n");
        return;
    }

    printf("Vector (size %zu): (", v->size);
    for (size_t i = 0; i < v->size; i++) {
        printf("%.2lf", v->elements[i]);
        if (i < v->size - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}


void free_vector(Vector *v) {
    if (v->elements != NULL) {
        free(v->elements);
        v->elements = NULL;
    }
    v->size = 0;
}

int main(void) {
    Vector vec = {0, NULL};

    printf("Input vector\n");
    input_vector(&vec);

    printf("Output vector\n");
    print_vector(&vec);
    free_vector(&vec);

    return 0;
}