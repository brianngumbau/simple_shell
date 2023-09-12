<<<<<<< HEAD
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

=======
#include "shell.h"

/**
 * _puts - prints an input string
 * @str: the string
 * Return: void
 */

void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}
/**
 * _putchar - writes character ch to stderr
 * @ch: character
 * Return: 1 on success
 */
int _putchar(char ch)
{
	static int x;
	static char buff[WRITE_BUFFSIZE];

	if (ch == BUFFLUSH || x >= WRITE_BUFFSIZE)
	{
		write(2, buff, x);
		x = 0;
	}
	if (ch != BUFFLUSH)
		buff[x++] = ch;
	return (1);
}

/**
 * _putf - writes ch to given file descriptor
 * @ch: character to print
 * @f: file descriptor to write
 * Return: 1
 */
int _putf(char ch, int f)
{
	static int x;
	static char buff[BUFF_SIZE];

	if (ch == BUFFLUSH || x >= WRITE_BUFFSIZE)
	{
		write(f, buff, x);
		x = 0;
	}
	if (ch != BUFFLUSH)
		buff[x++] = ch;
	return (1);
}
/**
 * _putsf - prints an input string
 * @str: string to be printed
 * @f: file descriptor
 * Return: number of chars
 */
int _putsf(char *str, int f)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putf(*str++, f);
	}
	return (x);
}
>>>>>>> ac4ce4eb285c3cf9e85adb0c0c668252c5d310eb
