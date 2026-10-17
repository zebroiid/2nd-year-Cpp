#include <stdio.h>
#include <math.h>

long double cosh(long double x, long double epsilon = 1e-9L) {
    long double sum = 1.0L, term = 1.0L;
    long double x_squared = x * x;
    int n = 1;

    while (term > epsilon) {
        term *= x_squared / (2 * n * (2 * n - 1));
        sum += term;
        n++;
    }

    return sum;
}

bool cosh_test() {
    if (fabs(cosh(0.0L) - 1.0L) > 1e-9L) return false;
    if (fabs(cosh(1.0L) - 1.5430806348152437L) > 1e-9L) return false;
    if (fabs(cosh(-1.0L) - 1.5430806348152437L) > 1e-9L) return false;
    if (fabs(cosh(2.0L) - 3.7621956910836314L) > 1e-9L) return false;
    return true;
}

int main() {
    long double x;
    printf("Enter x: ");
    if (scanf("%Lf", &x) != 1) {
        printf("Invalid input. Please enter a valid number for x.\n");
        return 1;
    }
    long double result = cosh(x);
    printf("cosh(%.10Lf) = %.10Lf\n", x, result);
    if (!cosh_test()) {
        printf("Some tests failed.\n");
    } else {
        printf("All tests passed.\n");
    }
    return 0;
}