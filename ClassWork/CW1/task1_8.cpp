#include <iostream>
#include <math.h>


int main()
{
    float x, y;
    printf("Enter two real numbers: ");
    scanf("%f", &x);
    scanf("%f", &y);
    float sum=x+y;
    float diff=x-y;
    float prod=x*y;
    float quot=x/y;
    printf("Sum: %.2f\n", sum);
    printf("Difference: %.2f\n", diff);
    printf("Product: %.2f\n", prod);
    printf("Quotient: %.2f\n", quot);
}