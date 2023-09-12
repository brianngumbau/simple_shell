/*
 * File: helper.c
 * Auth: Brian ngumbau
 *       Javis mathews
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str);

int main() {
    char text[] = "Hello, World!";

    reverse_string(text);

    printf("Reversed String: %s\n", text);

    return 0;
}

void reverse_string(char *str) {
    if (!str)
        return;

    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

