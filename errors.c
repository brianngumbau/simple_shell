/*
 * File: errors.c
 * Auth: Brian ngumbau
 *       Javis mathews
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Simple Calculator\n");
    printf("Enter an expression (e.g., 2 + 3): ");

    if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
        printf("Invalid input. Please enter a valid expression.\n");
        return 1;
    }

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator '%c'. Supported operators are +, -, *, and /.\n", operator);
            return 1;
    }

    printf("Result: %lf\n", result);

    return 0;
}

