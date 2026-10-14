#include <stdio.h>
#include <math.h>

int number_of_sign_changes() {
    double x,x_old = 0,count = 0;
    while(true){
        printf("Enter x: ");
        if (scanf("%lf", &x) != 1){
            printf("Invalid input. Please enter a valid number for x.\n");
            continue;
        }

        if (x == 0){
            break;
        }

        if ((x > 0 && x_old < 0) || (x < 0 && x_old > 0)){
            count++;
        }
        x_old = x;
    }
   return count;
}

int main(){
     printf("Number of sign changes: %d\n", number_of_sign_changes());
}

