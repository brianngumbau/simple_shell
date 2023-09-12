/*
 * File: getline.c
 * Auth: Brian ngumbau
 *       Javis mathews
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_concat(const char *s1, const char *s2);

int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    char *result = string_concat(str1, str2);

    if (result) {
        printf("Concatenated String: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

char *string_concat(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);

    if (result) {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

