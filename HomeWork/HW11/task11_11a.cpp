#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int passportNumber;
    int itemsCount;
    double totalWeight;
} Passenger;

double averageWeightPerItem(const Passenger* passenger) {
    if (passenger == NULL || passenger->itemsCount <= 0) {
        return 0.0;
    }
    return passenger->totalWeight / passenger->itemsCount;
}

int loadPassengers(const char* fileName, Passenger** passengers, int* count) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return 0;
    }

    if (fscanf(file, "%d", count) != 1 || *count < 0) {
        fclose(file);
        return 0;
    }

    *passengers = (Passenger*)malloc(sizeof(Passenger) * (*count));
    if (*passengers == NULL && *count > 0) {
        fclose(file);
        return 0;
    }

    for (int i = 0; i < *count; ++i) {
        if (fscanf(file, "%d %d %lf",
                  &(*passengers)[i].passportNumber,
                  &(*passengers)[i].itemsCount,
                  &(*passengers)[i].totalWeight) != 3) {
            free(*passengers);
            *passengers = NULL;
            fclose(file);
            return 0;
        }

        if ((*passengers)[i].itemsCount < 0 || (*passengers)[i].totalWeight < 0.0) {
            free(*passengers);
            *passengers = NULL;
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

int findPassenger(const Passenger* passengers, int count, double tolerance) {
    if (passengers == NULL || count <= 0) {
        return -1;
    }

    double totalWeight = 0.0;
    int totalItems = 0;

    for (int i = 0; i < count; ++i) {
        if (passengers[i].itemsCount > 0) {
            totalWeight += passengers[i].totalWeight;
            totalItems += passengers[i].itemsCount;
        }
    }

    if (totalItems <= 0) {
        return -1;
    }

    double overallAverage = totalWeight / totalItems;

    for (int i = 0; i < count; ++i) {
        if (passengers[i].itemsCount <= 0) {
            continue;
        }

        double passengerAverage = averageWeightPerItem(&passengers[i]);
        if (fabs(passengerAverage - overallAverage) <= tolerance) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    const char* fileName = "passengers.txt";
    Passenger* passengers = NULL;
    int count = 0;
    double tolerance = 0.0;
    int index = -1;

    if (!loadPassengers(fileName, &passengers, &count)) {
        fprintf(stderr, "Cannot open file '%s' or data is invalid.\n", fileName);
        return 1;
    }

    printf("Enter allowable deviation in kg: ");
    scanf("%lf", &tolerance);

    index = findPassenger(passengers, count, tolerance);
    if (index == -1) {
        printf("No passenger found that matches the condition.\n");
        free(passengers);
        return 0;
    }

    printf("Passenger with passport number %d satisfies the condition.\n", passengers[index].passportNumber);
    printf("Average weight of one item: %.2f kg\n", averageWeightPerItem(&passengers[index]));

    free(passengers);
    return 0;
}
