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
	newhead->next = *head;
	*head = newhead;
	return (newhead);
	}

/**
 * addnode_end - adds a node at the end of a list
 * @head: address of head node pointer
 * @s: str of node
 * @n: node index
 * Return: list size
 */
list_t *addnode_end(list_t **head, const char *s, int n)
{
	list_t *new, *nod;

	if (!head)
		return (NULL);

	nod = *head;
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	_memset((void *)new, 0, sizeof(list_t);
			new->n = n;
			if (s)
			{
			free(new);
			return (NULL);
			}
			}
			if (nod)
			{
			while (nod->next)
			nod = nod->next;
			nod->next = new;
			}
			else
			*head = new;
			return (new);
			}
/**
 * print_strlist - prints the str of a linked list
 * @a: first node pointer
 * Return: size
 */

size_t print_strlist(const list_t *a)
{
	size_t b = 0;

	while (a)
	{
		_puts(a->s ? h->s : "(nil)");
		_puts("\n");
		a = a->next;
		b++;
	}
	return (b);
}

/**
 * delete_node - deletes a node ata a specified index
 * @head: first node address pointer
 * @ind: index of the node to be deleted
 * Return: 1 or 0 if it fails
 */

int delete_node(list_t **head, unsigned int ind)
{
	list_t *nod, *
