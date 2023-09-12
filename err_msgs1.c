/*
 * File: err_msgs1.c
 * Auth: Brian ngumbau
 *       Javis mathews
 */

#include <shell.h>
#include <stdlib.h>

char *generate_welcome_message(const char *user_name) {
    int len = strlen(user_name) + 20;
    char *welcome_message = (char *)malloc(len * sizeof(char));
    if (!welcome_message) {
        perror("Error allocating memory");
        exit(1);
    }
    snprintf(welcome_message, len, "Welcome, %s!", user_name);
    return welcome_message;
}

int main() {
    char *welcome1 = generate_welcome_message("Alice");
    char *welcome2 = generate_welcome_message("Bob");

    printf("%s\n", welcome1);
    printf("%s\n", welcome2);

    free(welcome1);
    free(welcome2);

    return 0;
}

