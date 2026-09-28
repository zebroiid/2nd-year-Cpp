# include <stdio.h>

int main(){
    float v, m, E;
    printf("Enter velocity (v), mass (m): ");
    scanf("%f %f", &v, &m);
    E = (m * v * v)/2;
    printf("Kinetic energy (E): %f\n", E);

}