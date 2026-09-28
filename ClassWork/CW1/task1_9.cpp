#include <iostream>
#include <math.h>

using namespace std;
double avg(float a, float b){
    return (a+b)/2.0;
}
double harmonic_mean(float a, float b){
    return 2.0/(1.0/a+1.0/b);
}
int main()
{
    float x, y;
    printf("Enter two real numbers: ");
    scanf("%f", &x);
    scanf("%f", &y);
    
    printf("average= %f\n", avg(x, y));
    printf("harmonic_mean= %f\n", harmonic_mean(x, y));
}
