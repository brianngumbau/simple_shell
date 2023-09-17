#include "shell.h"

/**
 * clear - initializes info struct
 * @info: address of structure
 * Return: empty
 */

void clear(in_ *info)
{
	info->str = NULL;
	info->arr = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * set - initializes struct
 * @info: address of struct
 * @q: argv
 * Return: empty
 */
void set(in_ *info, char **q)
{
	int t = 0;

	info->filename = q[0];
	if (info->str)
	{
		info->arr = strtow(info->str, "\t");
		if (!info->arr)
		{
			info->arr = malloc(sizeof(char *) * 2);
			if (info->arr)
			{
				info->arr[0] = _strdup(info->arg);
				info->arr[1] = NULL;
			}
		}
		for (t = 0; info->arr && info->arr[t]; t++)
			;
		info->argc = q;

		rep_alias(info);
		rep_vars(info);
	}
}

/**
 * free - frees strucs
 * @info: address of struct
 * @k: true
 */

void free(in_t *info, int k)
{
	free(info->arr);
	info->arr = NULL;
	info->path = NULL;
	if (k)
	{
		if (!info->buffcmd)
			free(info->arr);
		if (info->env)
			freelist(&(info->h));
		if (info->alias)
			freelist(&(info->alias));
		free(info->environ);
		info->environ = NULL;
		f_ree((void **)info->buffcmd);
		if (info->readf > 2)
			close(info->readf);
		_putchar(BUFFLUSH);
	}
}
