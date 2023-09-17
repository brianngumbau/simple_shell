#include "shell.h"

/**
 * mem_set - fills memory with a given byte
 * @p: pointer to memory
 * @byt: byte to fill memory area
 * @i: amount of bytes
 * Return: pointer to memory area (p)
 */

char *mem_set(char *p, char byt, unsigned int i)
{
	unsigned int a;
	for (a = 0; a < i; a++)
		p[a] = byt;
	return (p);
}

/**
 * f_ree - frees string of strings
 * @ss: string to be freed
 * Return: void
 */

void f_ree(char *ss)
{
	char **z = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(z);
}

/**
 * re_alloc - reallocates block of memory
 * @p: pointer to previous block with malloc
 * @o_size: previous block byte size
 * @n_size: newblock byte size
 * Return: pointer to new block
 */

void *re_alloc(void *p, unsigned int o_size, unsigned int n_size)
{
	char *x;

	if (!p)
		return (malloc(n_size));
	if (!n_size)
		return (free(p), NULL);
	if (n_size == o_size)
		return (p);

	x = malloc(n_size);
	if (!x)
		return (NULL);

	o_size = o_size < n_size ? o_size : n_size;
	while (o_size--)
		x[o_size] = ((char *)p)[o_size];
	free(p);
	return (x);
}

