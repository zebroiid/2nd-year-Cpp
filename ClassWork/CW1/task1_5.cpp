#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    
    long long int y=x*x;
    y*=y;
    y*=y;
    y*=y;
    y*=y;
    y*=y;
    
    
    printf("x^64=%lld\n", y);
}
