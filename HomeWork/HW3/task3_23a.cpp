#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_zero(double x) {
    return fabs(x) < 1e-9;
}

double onestep(double x) {
    if (x >= 0) {
        return 1;
    } else {
        return 0;
    }
}

double onestep_derivative(double x) {
    return 0;
}

int test_onestep() {
    if (!is_zero(onestep(-1))) {
        printf("Test onestep for -1 is failed\n");
        return 1;
    }
    if (!is_zero(onestep(0)-1)) {
        printf("Test onestep for 0 is failed\n");
        return 1;
    }
    if (!is_zero(onestep(2)-1)) {
        printf("Test onestep for 2 is failed\n");
        return 1;
    }
    return 0;
}

int test_onestep_derivative() {
    if (!is_zero(onestep_derivative(-1))) {
        printf("Test onestep_derivative for -1 is failed\n");
        return 1;
    }
    if (!is_zero(onestep_derivative(0))) {
        printf("Test onestep_derivative for 0 is failed\n");
        return 1;
    }
    if (!is_zero(onestep_derivative(2))) {
        printf("Test onestep_derivative for 2 is failed\n");
        return 1;
    }
    return 0;
}

int main() {
    if (test_onestep() != 0) {
        return 1;
    }
    if (test_onestep_derivative() != 0) {
        return 1;
    }
    printf("All tests passed\n");
    return 0;
}