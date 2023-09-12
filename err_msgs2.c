/*
 * File: err_msgs2.c
 * Auth: Brian ngumbua
 *       Javis mathews
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}

int main() {
    int result;
    int num1 = 10;
    int num2 = 5;

    char operation[10] = "add";

    if (strcmp(operation, "add") == 0) {
        result = add(num1, num2);
    } else if (strcmp(operation, "subtract") == 0) {
        result = subtract(num1, num2);
    } else if (strcmp(operation, "multiply") == 0) {
        result = multiply(num1, num2);
    } else if (strcmp(operation, "divide") == 0) {
        result = divide(num1, num2);
    } else {
        fprintf(stderr, "Error: Invalid operation\n");
        exit(1);
    }

    printf("Result: %d\n", result);

    return 0;
}

