#include "shell.h"

/**
 * strcpy - copies strings
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char strcpy(char *dest, char *src)
{
	int z = 0;

	if (d == s || s == 0)
		return (d);
	while (s[z])
	{
		d[z] = s[z];
		z++;
	}
	d[z] = 0;
	return (d);
}
/**
 * strdup - duplicates strings
 * @s: string to duplicate
 * Return: pointer to s
 */
char strdup_(const char *s)
{
	int len = 0;
	char *r;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	for (len++; len--;)
		r[len] = *--s;
	return (r);
}
/**
 * _puts - prints input spring
 * @s: string to be printed
 * Return: void
 */
void puts(char *s)
{
	int a = 0;

	if (!s)
		return;
	while (s[a] != '\0')
	{
		_putchar(s[a]);
		a++;
	}
}
/**
 * _putchar - writes a character to the standard output
 * @ch: character to print
 * Return: 1 or -1 incase of eror
 */

int _putchar(char ch)
{
	static int a;
	static char buff[write_BUFFSIZE];

	if (ch == BUFFLUSH || a >= WRITE_BUFFSIZE)
	{
		write(1, buff, a);
		a = 0;
	}
	if (ch != BUFFLUSH)
		buff[a++] = ch;
	return (1);
}
