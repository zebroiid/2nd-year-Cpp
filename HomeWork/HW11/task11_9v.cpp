#include <stdio.h>
#include <stdlib.h>

#define FILE_F "F.txt"
#define FILE_H "H.txt"
#define FILE_G "G.txt"

int readIntegers(const char* fileName, int** arr, int* count) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return 0;
    }

    int capacity = 16;
    int used = 0;
    int* data = (int*)malloc(sizeof(int) * capacity);
    if (data == NULL) {
        fclose(file);
        return 0;
    }

    while (fscanf(file, "%d", &data[used]) == 1) {
        used++;

        if (used == capacity) {
            capacity *= 2;
            int* temp = (int*)realloc(data, sizeof(int) * capacity);
            if (temp == NULL) {
                free(data);
                fclose(file);
                return 0;
            }
            data = temp;
        }
    }

    fclose(file);
    *arr = data;
    *count = used;
    return 1;
}

int writeArrayToFile(const char* fileName, const int* arr, int count) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
    return 1;
}

int processFiles(void) {
    int* source = NULL;
    int count = 0;
    int positiveCount = 0;
    int negativeCount = 0;
    int* positives = NULL;
    int* negatives = NULL;
    int* result = NULL;
    int written = 0;

    if (!readIntegers(FILE_F, &source, &count)) {
        printf("Cannot open file %s or it is empty.\n", FILE_F);
        return 1;
    }

    if (count == 0) {
        printf("File is empty.\n");
        free(source);
        return 0;
    }

    for (int i = 0; i < count; ++i) {
        if (source[i] > 0) {
            positiveCount++;
        } else if (source[i] < 0) {
            negativeCount++;
        } else {
            printf("Zero found. The condition is not satisfied.\n");
            free(source);
            return 0;
        }
    }

    if (positiveCount != negativeCount) {
        printf("The file does not contain the same number of positive and negative numbers.\n");
        free(source);
        return 0;
    }

    if (!writeArrayToFile(FILE_H, source, count)) {
        printf("Cannot create helper file %s.\n", FILE_H);
        free(source);
        return 1;
    }

    positives = (int*)malloc(sizeof(int) * positiveCount);
    negatives = (int*)malloc(sizeof(int) * negativeCount);
    if (positives == NULL || negatives == NULL) {
        printf("Memory allocation error.\n");
        free(source);
        free(positives);
        free(negatives);
        return 1;
    }

    int p = 0;
    int n = 0;
    for (int i = 0; i < count; ++i) {
        if (source[i] > 0) {
            positives[p++] = source[i];
        } else {
            negatives[n++] = source[i];
        }
    }

    result = (int*)malloc(sizeof(int) * count);
    if (result == NULL) {
        printf("Memory allocation error.\n");
        free(source);
        free(positives);
        free(negatives);
        return 1;
    }

    for (int i = 0; i < positiveCount; i += 2) {
        if (i + 1 < positiveCount && i + 1 < negativeCount) {
            result[written++] = positives[i];
            result[written++] = positives[i + 1];
            result[written++] = negatives[i];
            result[written++] = negatives[i + 1];
        } else {
            printf("The sequence cannot be formed exactly in the required pattern.\n");
            printf("The last two numbers are: %d and %d\n",
                   positives[i], negatives[i]);
            break;
        }
    }

    if (written > 0) {
        writeArrayToFile(FILE_G, result, written);
    }

    free(source);
    free(positives);
    free(negatives);
    free(result);
    return 0;
}

int main(void) {
    return processFiles();
}
