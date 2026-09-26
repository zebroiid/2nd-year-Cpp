#include <stdio.h>
#include <math.h>



int count_intersections(double r, double a, double b, double c) {
    const double EPS = 1e-9;

    double y_min = b;
    double y_max = b + c * c;
    double abs_a = fabs(a);

    int count = 0;

    if (abs_a  > r + EPS) {
        count = 0;
    }
    else if (fabs(abs_a - r) <= EPS) {
        if (y_min - EPS <= 0 && 0 <= y_max + EPS) {
            count = 1;
        } else {
            count = 0;
        }
    }
    else {
        double y_offset = sqrt(r * r - a * a);
        double y1 = -y_offset;
        double y2 = y_offset;

        if (y1 >= y_min - EPS && y1 <= y_max + EPS) {
            count++;
        }
        if (y2 >= y_min - EPS && y2 <= y_max + EPS) {
            count++;
        }
    }

    printf("Number of points of intersection: %d\n", count);

    return 0;
}

int main(){
    double r, a, b, c;
    count_intersections(2, 0, 0, 1);
    count_intersections(2, 0, 0, 4);
    count_intersections(2, 1, -4, 10);
    printf("Enter the radius of the circle r: ");
    if (scanf("%lf", &r) != 1 || r < 0) {
        printf("Error: the radius must be a non-negative number.\n");
        return 1;
    }

    printf("Enter the coordinate of the line a: ");
    scanf("%lf", &a);

    printf("Enter the start of the segment b: ");
    scanf("%lf", &b);

    printf("Enter the parameter c: ");
    scanf("%lf", &c);
    count_intersections(r, a, b, c);
}