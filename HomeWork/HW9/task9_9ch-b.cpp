#include <stdio.h>
#include <stdlib.h>



void printMatrix(double** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
        printf("Error: Matrix is empty.\n");
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}


void addColumnAfterK(double** matrix, int rows, int* cols, int k) {

    if (k < 0 || k > *cols) {
        printf("Error: Column index k=%d is out of bounds (possibly from 0 to %d).\n", k, *cols);
        return;
    }

    int oldCols = *cols;
    int newCols = oldCols + 1;
    int targetIdx = k;

    for (int i = 0; i < rows; ++i) {

        double* newRow = (double*)malloc(newCols * sizeof(double));
        if (newRow == NULL) {
            printf("Error: Failed to allocate memory!\n");
            exit(1);
        }

        for (int j = 0; j < newCols; ++j) {
            if (j < targetIdx) {
                newRow[j] = matrix[i][j];
            } else if (j == targetIdx) {
                newRow[j] = (rand() % 100) / 10.0;
            } else {
                newRow[j] = matrix[i][j - 1];
            }
        }

        free(matrix[i]);
        matrix[i] = newRow;
    }

    printf("New column successfully added after position %d (filled with random numbers).\n", k);
    *cols = newCols;
}

void addColumnAfterBiggestSumCollumn(double** matrix, int rows, int* cols) {
    if (rows == 0 || *cols == 0) {
        printf("Error: Matrix is empty.\n");
        return;
    }

    int maxSumColIdx = 0;
    double maxSum = 0.0;

    for (int j = 0; j < *cols; ++j) {
        double sum = 0.0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxSumColIdx = j;
        }
    }

    addColumnAfterK(matrix, rows, cols, maxSumColIdx+1);
}

int main() {

    int N, M;
    printf("input number of rows N: ");
    if (scanf("%d", &N) != 1 || N <= 0) return 1;
    printf("input number of columns M: ");
    if (scanf("%d", &M) != 1 || M <= 0) return 1;


    double** A = (double**)malloc(N * sizeof(double*));
    if (A == NULL) return 1;

    for (int i = 0; i < N; ++i) {
        A[i] = (double*)malloc(M * sizeof(double));
        if (A[i] == NULL) return 1;
        
        for (int j = 0; j < M; ++j) {
            A[i][j] = (rand() % 100) / 10.0;
        }
    }

    printf("Your matrix:\n");
    printMatrix(A, N, M);


    int k;
    printf("Enter the column index k after which to insert a new column\n");
    printf("(0 - insert at the beginning, %d - insert at the end): ", M);
    if (scanf("%d", &k) != 1) return 1;


    addColumnAfterK(A, N, &M, k);

    printf("Matrix after modification\n");
    printMatrix(A, N, M);

    addColumnAfterBiggestSumCollumn(A, N, &M);
    printf("Matrix after adding a column after the column with the largest sum:\n");
    printMatrix(A, N, M);

    freeMatrix(A, N);

    return 0;
}
