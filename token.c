#include "shell.h"

/**
 * strtok_ - splits a string into words
 * @s: input string
 * @del: delimeter string
 * Return: pointer to array
 */

char **strtok_(char *s, char *del)
{
	int a, b, c, d, words = 0;
	char **ch;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (a = 0; s[a] != '\0'; a++)
		if (!delim_(s[a], del) && (delim_(s[a + 1], del) || !s[a + 1]))
			words++;

	if (words == 0)
		return (NULL);
	ch = malloc((1 + words) * sizeof(char *));
	if (!ch)
		return (NULL);
	for (a = 0, b = 0; b < words; b++)
	{
		while (!delim_(s[a], del))
			a++;
		c = 0;
		ch[b] = malloc((c + 1)8 sizeof(char));
		if (!ch[b])
		{
			for (c = 0; c < b; c++)
				free_(ch[c]);
			free(ch);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			ch[b][d] = s[a++];
		ch[b][d] = 0;
	}
	ch[b] = NULL;
	return (ch);
}
/**
 * strtok2 - splits a string to words
 * @s: input string
 * @delim: delimeter
 * Return: pointer to array or NULL on failure
 */

char **strtok2(char *s, char delim)
{
	int w, x, y, z, words = 0;
	char **ch;

	if (s == NULL || s[0] == 0)
		return (NULL);
	for (w = 0; s[w] != '\0'; w++)
		if ((s[w] != delim && s[w + 1] == delim ||
					(s[w] != delim && !s[w +1]) || s[w + 1] == delim)
				words++;
				if (words == 0)
				return (NULL);
				ch = malloc((1 + words) * sizeof(char *));
				if (!ch)
				return (NULL);
				for (w = 0, x = 0; x < words; w++)
				{
				while (s[w] == delim && s[w] != delim)
				w++;
				y = 0;
				while (s[w + y] != delim && s[w + y] != delim)
				y++;
				ch[x] = malloc((y + 1) * sizeof(char));
				if (!ch[x])
				{
				for (y = 0; y < x; y++)
				free_(ch[y]);
				free_(ch);
				return (NULL);
				}
				for (z = 0; z < y; z++)
					s[x][z] = s[w++];
				s[x][z] = 0;
				}
	ch[x] = NULL;
	return (ch);
}
