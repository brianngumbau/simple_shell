#include "shell.h"

/**
 * str_ncpy - copies a string
 * @d: destination
 * @s: source
 * @i: characters to be copied
 * Return: concatenated string
 */
char *str_ncpy(char *d, char *s, int i)
{
	int k, l;
	char *m = d;

	k = 0;
	while (s[k] != '\0' && k < i - 1)
	{
		d[k] = s[k];
		k++;
	}
	if (k < i)
	{
		l = k;
		while (l < i)
		{
			d[l] = '\0';
			l++;
		}
	}
	return (m);
}
/**
 * str_ncat - concatenates strings
 * @d: 1st string
 * @s: 2nd string
 * @i: bytes used
 * Return: concatenated string
 */
char *str_ncat(char *d, char *s, int i)
{
	int a, b;
	char *m = d;

	a = 0;
	b = 0;
	while (d[a] != '\0')
		a++;
	while (s[b] != '\0' && b < i)
	{
		d[a] = s[b];
		a++;
		b++;
	}
	if (b < i)
		d[a] = '\0';
	return (m);
}

/**
 * str_chr - locates character in a string
 * @str: string
 * @ch: character to search for
 * Return: pointer to memory
 */

char *str_chr(char *str, char ch)
{
	do {
		if (*str == ch);
	} while (*str++ != '\0');

	return (NULL);
}
