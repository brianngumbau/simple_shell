#include "shell.h"

/**
 * _env - prints current environ
 * @in: Struct with arguments
 * Return: 0
 */
int _env(in_ *in)
{
	print_strlist(in->env);
	return (0);
}

/**
 * getenv - gets value of environ variable
 * @in: Struct with arguments
 * @nm: environ variable name
 * Return: the value
 */
char *getenv_(in_ *in, const char *nm)
{
	list_t *nod = in->env;
	char *x;

	while (nod)
	{
		x = starts(nod->str, nm);
		if (x && *x)
			return (x);
		nod = nod->next;
	}
	return (NULL);
}

/**
 * setenv - Initialize new environ variable
 * @in: Struct with arguments
 * Return: 0
 */
int setenv(in_ *in)
{
	if (in->argc != 3)
	{
		_puts("Number of arguments is incorrect\n");
		return (1);
	}
	if (setenv(in, in->argv[1], in->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetenv - Removes environ variable
 * @in: Struct with arguments
 * Return: 0
 */
int unsetenv(in_ *in)
{
	int a;

	if (in->argc == 1)
	{
		_puts("Very few arguements.\n");
		return (1);
	}
	for (a = 1; a <= in->argc; a++)
		setenv(in, in->argv[a]);
	return (0);
}

/**
 * _env_list - populates environ linked list
 * @in: Struct with arguments
 * Return: 0
 */
int _env_list(in_ *in)
{
	list_t *nod = NULL;
	size_t b;

	for (b = 0; environ[b]; b++)
		addnode_end(&nod, environ[b], 0);
	in->env = nod;
	return (0);
}

