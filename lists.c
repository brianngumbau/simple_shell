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
	list_t *nod, *prevnod;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		nod = *head;
		*head = (*head)->next;
		free_(nod->s);
		free(nod);
		free(nod);
		return (1);
	}
	nod = *head;
	while (nod)
	{
		if (j == ind)
		{
			prevnode->next = nod->next;
			free_(nod);
			free_(nod);
			return (1);
		}
		j++;
		prevnod = nod;
		nod = nod->next;
	}
	return (0);
}

/**freelist - frees nodes
 * @headp: address of pointer to head node
 * Return: void
 */

void freelist(list_t **headp)
{
	list_t *nod, *nextnod, *head;

	if (!headp || !*headp)
		return;
	head = *headp;
	nod = head;
	while (nod)
	{
		nextnod = nod->next;
		free_(nod->s);
		free_(nod);
		nod = nextnod;
	}
	*headp = NULL;
}

