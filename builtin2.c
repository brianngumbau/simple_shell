#include "shell.h"

/**
 * _history - displays the history list
 * @info: Struct with arguments
 *  Return: 0
 */
int _history(in_ *in)
{
	printlist(in->h);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unalias(in_ *in, char *s)
{
	char *q, x;
	int rt;

	q = str_chr(s, '=');
	if (!q)
		return (1);
	x = *q;
	*q = 0;
	rt = delete_node(&(in->alias),
		node_index(in->alias, node_start(in->alias, s, -1)));
	*q = x;
	return (rt);
}

/**
 * setalias - sets alias
 * @in: struct
 * @s: string alias
 * Return: 0, 1 on error
 */
int setalias(in_ *in, char *s)
{
	char *g;

	g = str_chr(str, '=');
	if (!g)
		return (1);
	if (!*++g)
		return (unalias(in, s));

	unalias(in, s);
	return (addnode_end(&(in->alias), s, 0) == NULL);
}

/**
 * palias - prints alias
 * @nod: node
 * Return: 0, 1 on error
 */
int palias(list_t *nod)
{
	char *b = NULL, *z = NULL;

	if (nod)
	{
		b = str_chr(nod->s, '=');
		for (z = node->s; z <= p; z++)
		_putchar(*z);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - man alias
 * @in: Struct with arguments
 *  Return: 0
 */
int _alias(in_ *in)
{
	int k = 0;
	char *g = NULL;
	list_t *nod = NULL;

	if (in->argc == 1)
	{
		nod = in->alias;
		while (nod)
		{palias(nod);
			nod = nod->next;
		}
		return (0);
	}
	for (k = 1; info->argv[k]; k++)
	{
		g = str_chr(in->argv[k], '=');
		if (p)
			setalias(in, in->argv[k]);
		else
			palias(node_starts(in->alias, info->argv[k], '='));
	}

	return (0);
}

