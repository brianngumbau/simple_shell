#include <stdio.h>

unsigned long long calculateFactorial(int n);

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long factorial = calculateFactorial(number);
        printf("Factorial of %d is %llu\n", number, factorial);
    }
    
    return 0;
}

unsigned long long calculateFactorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * calculateFactorial(n - 1);
    }
}

