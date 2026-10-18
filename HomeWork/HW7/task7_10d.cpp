#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_perfect_square(int num) {
    if (num < 0) return 0;
    int root = (int)sqrt(num);
    return (root * root == num);
}

int input_array(int arr[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("Enter element %d: ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("wrong input\n");
            return i;
        }
    }
    return i;
}

void print_array(const int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int count_perfect_squares(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size / 2; i++) {
        int product = arr[i] * arr[size - 1 - i];
        if (is_perfect_square(product)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return 1;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    input_array(a, n);
    print_array(a, n);
    printf("Number of perfect squares: %d\n", count_perfect_squares(a, n));
    free(a);
    return 0;
}