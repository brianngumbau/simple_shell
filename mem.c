#include "shell.h"

/**
 * free_ - frees memory previously alocated
 * @add: adddress of pointer to free
 * Return: empty
 */
void f_ree(void *add)
{
	if (add && *add)
	{
		free_(*add);
		*add = NULL;
	}
}
