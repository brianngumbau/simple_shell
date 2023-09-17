#include "shell.h"

/**
 * err_atoi - converts a string into integer
 * @e: string to convert
 * Return: 0 otherwise 1 on error
 */

int err_atoi(char *e)
{
	int x = 0;
	unsigned long int res = 0;

	if (*e == '+')
		e++;
	for (x = 0; e[x] != '\0'; x++)
	{
		if (e[x] >= '0' && e[x] <= '9')
		{
			res *= 10;
			res += (e[x] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * printerr - prints error
 * @f: struct
 * @str: string with specified error type
 * Return: void
 */

void printerr(in_ *f, char *str)
{
	_puts(f->fname);
	_puts(": ");
	printd(f->line_count, STDERR_FILENO);
	_puts(": ");
	_puts(f->argv[0]);
	_puts(": ");
	_puts(str);
}

/**
 * printd - prints an integer
 * @in: input
 * @fd: filescriptor
 * Return: no. of characters printed
 */

int printd(int in, int fd)
{
	int (*put)(char) = _putchar;
	int y, count = 0;
	unsigned int ab, curr;

	if (fd == STDERR_FILENO)
		put = _putchar;
	if (in < 0)
	{
		ab = -input;
		put('-');
		count++;
	}
	else
		ab = in;
	curr = ab;
	for (y = 1000000000; y > 1; y /= 10)
	{
		if (ab / y)
		{
			put('0' + curr / y);
			count++;
		}
		curr %= y;
	}
	put('0' + curr);
	count++;

	return (count);
}
/**
 * convertnumber - convert function
 * @n: no.
 * @b: the base
 * @f: flags
 * Return: a string
 */
char *convertnumber(long int n, int b, int f)
{
	static char *arr;
	static char buff[50];
	char sg = 0;
	char *str;
	unsigned long k = n;

	if (!(f & CONVERT_UNSIGNED) && num < 0)
	{
		k = -n;
		sg = '-';
	}
	arr = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buff[49];
	*str = '\0';

	do {
		*--str = arr[n % base];
		k /= base;
	} while (k != 0);

	if (sg)
		*--str = sg;
		return (str);
}
/**
 * rm_comments - replaces '#' with '\0'
 * @buff: address of string to modify
 * Return: empty
 */
void rm_comments(char *buff)
{
	int u;

	for (u = 0; buff[u] != '\0'; u++)
		if (buff[u] == '#' && (!u || buff[u - 1] == ' '))
		{
			buff[u] = '\0';
			break;
		}
}
