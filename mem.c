#include "shell.h"
/**
 * *_memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: to each byte in memory area pointed by “s”
 * @n: the amount of bytes to be filled
 *
 * Credit By Brian Ngumbau, Javis Mathews
 * Return: (s) a pointer to the filled memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;
	return (s);
}

/**
 * ffree - free memory allocated for an array of strings
 * @pp: array of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}


/**
 * * _realloc - to reallocate a block of memory
 * @ptr: pointer to previous allocated memory block
 * @old_size: size (in bytes) of the old memory block
 * @new_size: size(in bytes) of the new memory block
 * Return: pointer “p” which now points to the newly
 * allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);

	return (p);
}
