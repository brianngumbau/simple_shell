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
