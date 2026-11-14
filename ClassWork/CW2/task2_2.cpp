#include <stdio.h>
#include <math.h>

int main()
{
   double a, b;
   printf("Enter legs a and b of the triangle: ");
   scanf("%lf %lf", &a, &b);
   
   if (a <= 0 || b <= 0) {
       printf("Error: Legs must be positive numbers.\n");
       return 1;
   }

   double c=sqrt(a*a+b*b);
   printf("Hypotenuse is %.2f\n", c);
}