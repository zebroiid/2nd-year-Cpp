//
// Created by markp on 23/11/2026.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    char b;
    short c;
    long d;
    long long e;

    scanf("%d %hhd %hd %ld %lld", &a, &b, &c, &d );

    long long sum= (long long)a + b + c + d;
    double m = (double)sum / 5.0;

    unsigned long long mod_a = (unsigned long long)llabs((long long)a);
    unsigned long long mod_b = (unsigned long long)llabs((long long)b);
    unsigned long long mod_c = (unsigned long long)llabs((long long)c);
    unsigned long long mod_d = (unsigned long long)llabs((long long)d);
    unsigned long long mod_e = (unsigned long long)llabs((long long)e);

    unsigned long long bitwise_sum = mod_a | mod_b | mod_c | mod_d | mod_e;
    printf("%llu", bitwise_sum);



}