#include "shell.h"

/**
 * _strlen - A function that returns the length of a string
 * @s: the string whose length to check
 *
 * Credit By Brian Ngumbau, Javis Mathews
 * Return: length of string
 */

int _strlen(char *s)
{
	int length = 0;

	if (!s)
		return (0);

	while (*s++)
		length++;
	return (length);
}

/**
 * _strcmp - A program to compare two strings
 * @fs: first string to be used
 * @ss: the second string to be used
 *
 * Return: negative if fs < ss, positive if fs > ss, zero if fs == ss
 */

int _strcmp(char *fs, char *ss)
{
	while (*fs && *ss)
	{
		if (*fs != *ss)
			return (*fs - *ss);
		fs++;
		ss++;
	}
	if (*fs == *ss)
		return (0);
	else
		return (*fs < *ss ? -1 : 1);
}


/**
 * *starts_with - A functon to check if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle && *haystack)
		if (*needle++ != *haystack++)
			return (NULL);
	if (*needle)
		return (NULL);
	return ((char *)haystack);
}

/**
 * *_strcat - This function concatenates two strings
 *  @dest: the destination buffer to be used
 *  @src: the source buffer to be used
 *
 *  Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


/**
 * _strcpy - A function that copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}
