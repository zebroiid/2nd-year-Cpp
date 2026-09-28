#include <stdio.h>
#include <math.h>


void solve_quadratic(double a, double b, double c) {
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Infinite solutions.\n");
            } else {
                printf("No solution.\n");
            }
        } else {
            double x = -c / b;
            printf("One root: x = %g\n", x);
        }
        return;
    }

    double D = b * b - 4 * a * c;

    if (D < 0) {
        printf("No real solutions (D < 0).\n");
    } else if (D == 0) {
        double x = -b / (2 * a);
        printf("One root: x = %g\n", x);
    } else {
        double sqrt_D = sqrt(D);
        double x1 = (-b + sqrt_D) / (2 * a);
        double x2 = (-b - sqrt_D) / (2 * a);
        printf("Two roots: x1 = %g, x2 = %g\n", x1, x2);
    }
}



int main() {
    double a = 3, b = 100, c = 2;


    solve_quadratic(a, b, c);
    return 0;
}