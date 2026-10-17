#include <stdio.h>


long double calc_product(int n) {
    if (n < 0) {
        return 0;
    }

    const long double initial_terms[] = {
        1.0L,
        1.0L / 3.0L,
        3.0L / 9.0L
    };
    long double product = 1.0L;
    for (int k = 0; k < 3 && k <= n; ++k) {
        product *= initial_terms[k];
    }

    long double a0 = 1.0L, a1 = 1.0L, a2 = 3.0L;
    long double inverse_power_of_two = 0.25L;
    long double power_of_three = 27.0L;
    long double ak;

    for (int k = 3; k <= n; ++k) {
        ak = a0 + a1 * inverse_power_of_two;
        product *= ak / power_of_three;
        a0 = a1;
        a1 = a2;
        a2 = ak;
        inverse_power_of_two /= 2.0L;
        power_of_three *= 3.0L;
    }
    return product;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer for n.\n");
        return 1;
    }
    long double product = calc_product(n);
    printf("Product for n = %d: %.10Lf\n", n, product);
    return 0;
}
