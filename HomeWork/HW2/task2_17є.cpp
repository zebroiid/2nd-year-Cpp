#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool is_zero(double x) {
    return fabs(x) < 1e-6;
}

double sigmoid(double x) {
    return pow(1+exp(-x), -1);
}


double sigmoid_derivative(double x) {
    const double h = 1e-5;
    return (sigmoid(x+h)-sigmoid(x-h))/(2*h);
}


int test_sigmoid() {
    if (!is_zero(sigmoid(0) - 0.5)) {
        printf("test for sigmoid has failed\n");
        return 1;
    }
    if (!is_zero(sigmoid(1) - 0.73105857863)) {
        printf("test for sigmoid has failed\n");
        return 1;
    }
    if (!is_zero(sigmoid(-1) - 0.26894142137)) {
        printf("test for sigmoid has failed\n");
        return 1;
    }


    return 0;
}


int derivative_test_sigmoid() {
    if (!is_zero(sigmoid_derivative(0) - 0.25)) {
        printf("test for sigmoid derivative has failed\n");
        return 1;
    }
    if (!is_zero(sigmoid_derivative(1) - 0.19661193324)) {
        printf("test for sigmoid derivative has failed\n");
        return 1;
    }
    if (!is_zero(sigmoid_derivative(-1) - 0.19661193324)) {
        printf("test for sigmoid derivative has failed\n");
        return 1;
    }
    return 0;
}


int main() {
    if (test_sigmoid() != 0) {
        return 1;
    }
    if (derivative_test_sigmoid() != 0) {
        return 1;
    }
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("the evaluation of sigmoid in x is %lf\n", sigmoid(x));
    printf("the evaluation of the derivative of sigmoid in x is %lf\n", sigmoid_derivative(x));
}