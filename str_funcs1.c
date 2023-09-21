#include "shell.h"

/**
 * **strtow - splits a string into words
 * @str: the input string
 * @id: the delimeter string
 *
 * Credit By Brian Ngumbau, Javis Mathews
 * Return: a pointer to an array of strings
 * otherwise NULL if it fails
 */

char **strtow(char *str, char *id)
{
	int a, b, c, d, words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!id)
		id = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], id) && (is_delim(str[a + 1], id) || !str[a + 1]))
			words++;

	if (words == 0)
		return (NULL);
	s = malloc((1 + words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < words; b++)
	{
		while (is_delim(str[a], id))
			a++;
		c = 0;
		while (!is_delim(str[a + c], id) && str[a + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			s[b][d] = str[a++];
		s[b][d] = 0;
	}
	s[b] = NULL;
	return (s);
}



/**
 * **strtow2 - A function that splits a string into words
 * @str: the input string
 * @id: the delimeter
 *
 * Return: a pointer to an array of strings,
 * or return NULL on failure
 */

char **strtow2(char *str, char id)
{
	int a, b, c, d, words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != id && str[a + 1] == id) ||
				(str[a] != id && !str[a + 1]) || str[a + 1] == id)
			words++;
	if (words == 0)
		return (NULL);
	s = malloc((1 + words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < words; b++)
	{
		while (str[a] == id && str[a] != id)
			a++;
		c = 0;
		while (str[a + c] != id && str[a + c] && str[a + c] != id)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			s[b][d] = str[a++];
		s[b][d] = 0;
	}
	s[b] = NULL;

	return (s);
}
