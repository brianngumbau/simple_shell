#include "shell.h"

/**
 * _getenviron - returns string array copy of environ
 * @in: Struct with arguments
 * Return: 0
 */
char **_getenviron(in_ *in)
{
	if (!in->environ || in->change_env)
	{
		in->environ = list_to_strings(info->env);
		in->change_env = 0;
	}

	return (in->environ);
}

/**
 * unsetenv - Remove environ variable
 * @in: Struct with arguments
 * Return: 1
 * @v:
 */
int unsetenv(in_ *in, char *v)
{
	list_t *nod = in->env;
	size_t a = 0;
	char *ch;

	if (!nod || !v)
		return (0);

	while (nod)
	{
		ch = starts(nod->str, v);
		if (ch && *ch == '=')
		{
			in->change_env = delete_node(&(in->env), a);
			a = 0;
			nod = in->env;
			continue;
		}
		nod = nod->next;
		a++;
	}
	return (in->change_env);
}

/**
 * setenv - Initializes  new environ variable
 * @in: Struct with potential arguments
 * @v: string environ variable
 * @val: string environ v value
 *  Return: 0
 */
int setenv(in_ *in, char *v, char *val)
{
	char *buff = NULL;
	list_t *nod;
	char *x;

	if (!v || !val)
		return (0);

	buff = malloc(_str_len(v) + _str_len(val) + 2);
	if (!buff)
		return (1);
	_str_cpy(buff, v);
	_str_cat(buff, "=");
	_str_cat(buff, val);
	nod = in->env;
	while (nod)
	{
		x = starts(nod->str, v);
		if (x && *x == '=')
		{
			free(nod->str);
			nod->str = buff;
			info->change_env = 1;
			return (0);
		}
		nod = nod->next;
	}
	addnode_end(&(in->env), buff, 0);
	free(buff);
	info->change_env = 1;
	return (0);
}

