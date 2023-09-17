#include "shell.h"

/**
 * strlen_ - returns length of str string
 * @str: string
 * Return: length of string
 */

int strlen_(char *str)
{
	int k = 0;

	if (!str)
		return (0);

	while (*str++)
		k++;
	return (k);
}

/**
 * strcmp_ - compares two strings
 * @t1: 1st string
 * @t2: 2nd string
 * Return: -if s1 < s2, 0 if s1 == s2, + if s1 > s2
 */

int strcmp_(char *t1, char *t2)
{
	while (*t1 && *t2)
	{
		if (*t1 != *t2)
			return (*t1 - *st);
		t1++;
		t2++;
	}
	if (*t1 == *t2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts - checks if n starts with h
 * @h: string to start
 * @n: substring
 * Return: address of of h or NULL if it fails
 */

char *starts(const char *h, const char *n)
{
	while (*n)
		if (*n++ != *h++)
			return (NULL);
	return ((char *)h);
}

/**
 * strcat_ - concatenates two strings
 * @d: dest buff
 * @s: source buff
 * Return: pointer to d
 */
char *strcat_(char *d, char *s)
{
	char *r = d;

	while (*d)
		d++;
	while (*s)
		*d++ = *s++;
	*d = *s;
	return (r);
}
