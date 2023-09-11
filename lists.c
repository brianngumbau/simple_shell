#include "shell.h"

/**
 * *addnode - adds node at beginning of a list
 * @head: address of pointer to head node
 * @str: string of node
 * @index: index used
 * Return: size of list
 */

list *addnode(list_t **head, const char *str, int index)
{
	list_t **newhead;

	if (!head)
		return (NULL);
	newhead = malloc(sizeof(list_t);
	if (!newhead)
		return (NULL);
	*_memset((void *)newhead, 0, sizeof(list_t));
	newhead->index = index;
	if (str)
	{
		newhead->str = *_strdup(str);
		if (!newhead->str)
		{
			free(newhead);
			return (NULL);
			}
	
	}


