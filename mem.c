#include "shell.h"

/**
 * free_ - frees memory previously alocated
 * @add: adddress of pointer to free
 * Return: empty
 */
void free_(void *add)
{
	if (add && *add)
	{
		free_(*add);
		*add = NULL;
	}
}
