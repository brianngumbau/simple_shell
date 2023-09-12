#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double evaluate_expression(const char *expression);
char *remove_spaces(const char *input);

int main() {
    char input[100];
    printf("Enter a mathematical expression: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  

    char *cleaned_input = remove_spaces(input);
    double result = evaluate_expression(cleaned_input);

    printf("Result: %lf\n", result);

    free(cleaned_input);
    return 0;
}

double evaluate_expression(const char *expression) {
    return 0.0;
}

char *remove_spaces(const char *input) {
    return NULL;
}

