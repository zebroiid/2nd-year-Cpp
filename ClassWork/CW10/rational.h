#include <stdbool.h>

typedef struct {
    int numerator;
    unsigned denominator;
} Rational;

void vyvod(Rational x);
int input(Rational* x);
bool equal(const Rational* a, const Rational* b);
unsigned gcd(unsigned a, unsigned b);
Rational reduce(Rational x);
void reduce_inplace(Rational* x);


Rational add(Rational a, Rational b);
Rational mul(Rational a, Rational b);

int cmp(const Rational* a, const Rational* b);
