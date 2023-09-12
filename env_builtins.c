/*
 * File: env_builtins.c
 * Auth: Brian ngumbau
 *       Javis mathews
 */

#include <shell.h>

void print_hello(void);
void print_goodbye(void);

void print_hello(void) {
    printf("Hello, World!\n");
}

void print_goodbye(void) {
    printf("Goodbye, World!\n");
}

int main(void) {
    print_hello();
    print_goodbye();
    return 0;
}

