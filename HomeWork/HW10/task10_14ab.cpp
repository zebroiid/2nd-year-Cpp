#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50


typedef struct {
    int name_index;
    char gender; 
    double height;
} Person;


double calculate_average_female_height(const Person P[], int size) {
    double total_height = 0.0;
    int female_count = 0;

    for (int i = 0; i < size; i++) {
        if (P[i].gender == 'F' || P[i].gender == 'f') {
            total_height += P[i].height;
            female_count++;
        }
    }

    if (female_count == 0) {
        return 0.0;
    }

    return total_height / female_count;
}


const char* find_tallest_man_name(const Person P[], int size, const char L[][MAX_NAME_LEN]) {
    int max_index = -1;
    double max_height = -1.0;

    for (int i = 0; i < size; i++) {
        if (P[i].gender == 'M' || P[i].gender == 'm') {
            if (P[i].height > max_height) {
                max_height = P[i].height;
                max_index = i;
            }
        }
    }

    if (max_index == -1) {
        return NULL;
    }


    int name_idx = P[max_index].name_index;
    return L[name_idx];
}

int main(void) {

    const char L[][MAX_NAME_LEN] = {
        "Anna",     
        "Alexander", 
        "Maria",    
        "Dmytro",
        "Olena"
    };

    Person P[] = {
        {0, 'F', 165.5},
        {1, 'M', 182.0},
        {2, 'F', 170.0},
        {3, 'M', 191.5},
        {4, 'F', 158.0}
    };

    int n = sizeof(P) / sizeof(P[0]);


    double avg_female_h = calculate_average_female_height(P, n);
    if (avg_female_h > 0) {
        printf("Average height of females: %.2lf см\n", avg_female_h);
    } else {
        printf("No females found in the list.\n");
    }


    const char *tallest_man = find_tallest_man_name(P, n, L);
    if (tallest_man != NULL) {
        printf("Tallest man: %s\n", tallest_man);
    } else {
        printf("No men found in the list.\n");
    }

    return 0;
}