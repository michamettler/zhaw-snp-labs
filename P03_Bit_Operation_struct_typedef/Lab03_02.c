#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 3;
    int b = 4;
    printf("a: %d; b: %d\n", a, b);

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    printf("a: %d; b: %d\n", a, b);
    return EXIT_SUCCESS;
}