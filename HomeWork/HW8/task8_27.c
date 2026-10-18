#include <stdio.h>
#include <stdlib.h>

void input_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void print_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}



int main() {
    int n;
    printf("Enter the size of the matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return 1;
    }

    const int size = 2 * n + 1;
    double (*matrix)[size] = malloc(size * sizeof(*matrix));
    if (matrix == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    input_matrix(size, matrix);
    printf("The matrix is:\n");
    print_matrix(size, matrix);
    printf("The transposed matrix is:\n");
    transpose_matrix(size, matrix);
    print_matrix(size, matrix);

    free(matrix);
    return 0;
}