#include <stdio.h>
#include <math.h>


long double factors_product(double n){
    long double product = 1;
    for (int i = 3; i <= n; i++){
        product *= 1- 1.0/(i*i);
    }
    return product;

}

int main(){
    double n;
    printf("Enter n: ");
    if (scanf("%lf", &n) != 1 || n <= 2){
        printf("Invalid input. Please enter a positive number for n > 2.\n");
        return 1;
    }
    printf("Product of factors: %.10Lf\n", factors_product(n));
    return 0;
}

