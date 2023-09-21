#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: stores various pieces of information
 * and settings for a shell program
 * Credit By Brian Ngumbau, Javis Mathews
 * Return: Always 0
 */

int _myhistory(info_x *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: stores various pieces of information
 * and settings for a shell program
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_x *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - This sets alias to string
 * @info: stores various pieces of information
 * and settings for a shell program
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_x *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - A function to print an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin
 * @info: stores various pieces of information
 * and settings for a shell program
 * Return: Always 0 on success
 */

int _myalias(info_x *info)
{
	int a = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		p = _strchr(info->argv[a], '=');
		if (p)
			set_alias(info, info->argv[a]);
	else
		print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}
	return (0);
}
