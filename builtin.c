/*
 * File: builtin.c
 * Auth: JAVIS MATHEWS
 *       BRIAN NGUMBAU
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(unsigned int n);

int main() {
    unsigned int n;

    printf("Enter a positive integer: ");
    scanf("%u", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    unsigned long long result = factorial(n);
    printf("Factorial of %u is %llu\n", n, result);

    return 0;
}

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

