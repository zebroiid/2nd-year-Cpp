#include <stdio.h>

int main() {
    double A, B, C;


    if (scanf("A=%lf, B=%lf C=%lf", &A, &B, &C) != 3) {
        printf("Error in input!\n");
        return 1;
    }

 
    double arithmetic_mean = (A + B + C) / 3.0;


    double harmonic_mean = 3.0 / ((1.0 / A) + (1.0 / B) + (1.0 / C));


    printf("--- Format with fixed point ---\n");
    printf("Arithmetic mean: %.6f\n", arithmetic_mean);
    printf("Harmonic mean:  %.6f\n\n", harmonic_mean);


    printf("--- Scientific format ---\n");
    printf("Arithmetic mean: %.6e\n", arithmetic_mean);
    printf("Harmonic mean:  %.6e\n", harmonic_mean);

    return 0;
}
