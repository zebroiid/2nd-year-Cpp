#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int find_max(const int arr[], int size) {
    if (size <= 0) return -1; // Return -1 for empty array
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int find_min(const int arr[], int size) {
    if (size <= 0) return -1; // Return -1 for empty array
    int min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int find_closest_to_average(const int arr[], int size) {
    if (size <= 0) return -1;
    double average = (find_max(arr, size) + find_min(arr, size)) / 2.0;
    int closest_index = 0;
    double closest_diff = fabs(arr[0] - average);
    for (int i = 1; i < size; i++) {
        double diff = fabs(arr[i] - average);
        if (diff < closest_diff) {
            closest_diff = diff;
            closest_index = i;
        }
    }
    return arr[closest_index];
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
    printf("Maximum element: %d\n", find_max(a, n));
    printf("Minimum element: %d\n", find_min(a, n));
    printf("Element closest to average: %d\n", find_closest_to_average(a, n));
    free(a);
    return 0;
}