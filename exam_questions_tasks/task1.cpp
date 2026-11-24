#include <stdio.h>

void f() {
    static int count = 0;
    count++;
    printf("%d\n", count);
}

int main() {
    f();
    f();
    f();
}
