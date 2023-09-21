#include "shell.h"

/**
 * *_strdup - duplicates a string
 * _strdup - A program that duplicates a string
 * * @str: the string to duplicate
 * Credit By Brian Ngumbau, Javis Mathews
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	for (length++; length--;)
		ptr[length] = *--str;
	return (ptr);
}



/**
 * *_strncpy - A function that copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @cp: the amount of characters to be copied
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int cp)
{
	int a, b;
	char *s = dest;

	a = 0;

	while (src[a] != '\0' && a < cp - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < cp)
	{
		b = a;
		while (b < cp)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}


/**
 * *_strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @cp: the amount of bytes to be maximally used
 * *Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int cp)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < cp)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < cp)
		dest[a] = '\0';
	return (s);
}

/**
 * *_strchr - A function to locate a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
