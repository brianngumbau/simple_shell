#include "shell.h"
/* Credit By Brian Ngumbau, Javis Mathews*/

/**
 * _myenv - prints the current environment
 * @info: stores various pieces of information
 * and settings for a shell program
 * Return: Always 0
 */

int _myenv(info_x *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: stores various pieces of information
 * and settings for a shell program
 * @name: env var name
 *
 *
 * Return: the value
 */

char *_getenv(info_x *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}

	return (NULL);
}



/**
 * _mysetenv - A program to initialize a new environment variable,
 * or modify an existing one
 * @info: The structure of information for our shell program.
 *
 * Return: Always 0
 */

int _mysetenv(info_x *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - A function to remove an environment variable
 * @info: The structure of information for our shell program
 * Return: Always 0
 */

int _myunsetenv(info_x *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}

/**
 * populate_env_list - A function to populate "env" linked list
 * @info: The structure of information for our shell program
 * Return: 0 on success
 */

int populate_env_list(info_x *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
	add_node_end(&node, environ[a], 0);
	info->env = node;

	return (0);
}
