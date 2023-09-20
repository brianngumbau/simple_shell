#include "shell.h"

/**
 * chain - finds out if current char in buff is a chain delimeter
 * @in: struct
 * @buff: pbuffer
 * @add: address of current buff position
 * Return: 1 if it's a chain del
 * 0 otherwise
 */

int chain(in_ *in, char *buff, size_t *add)
{
	size_t b = *add;

	if (buff[b] == '|' && buff[b + 1] == '|')
	{
		buff[b] = 0;
		b++;
		in->cmd_bufftype = CMDOR;
	}
	else if (buff[b] == ';')
	{
		buff[b] = 0;
		in->cmd_bufftype = CMDCHAIN;
	}
	else
		return (0);
	*add = b;
	return (1);
}
/**
 * ckchain - checks for continued chaining
 * @in: struct
 * @buff: charr buffer
 * @add: address of current buff pos
 * @s: starting pos
 * @length: length of buff
 * Return: void
 */
void ckchain(in_ *in, char *buff, size_t *add, size_t s, size_t length)
{
	size_t b = *add;

	if (in->cmd_bufftype == CMDAND)
	{
		if (in->stat)
		{
			buff[s] = 0;
			b = length;
		}
	}
	if (in->cmd_bufftype == CMDOR)
	{
		if (!in->stat)
		{
			buff[s] = 0;
			b = length;
		}
	}

	*add = b;
}

/**
 * rep_alias - replaces alias in token string
 * @in: struct
 * Return: 1 otherwise 0
 */

int rep_alias(in_ *in)
{
	int a;
	list_t *nod;
	char *add;

	for (a = 0; a < 10; a++)
	{
		nod = node_start(in->alias, in->arr[0], '=');
		if (!nod)
			return (0);
		free(in->arr[0]);
		add = str_chr(nod->str,'=');
	       if(!add)
	       	return (0);
	       add = _str_dup(add + 1);
	       if (!add)
		       return (0);
	       in->arr[0] = add;
	}
	return (1);
}
/**
 * rep_vars - replaces vars in token string
 * @in: struct
 * Return: 1 or 0 otherwise
 */

int rep_vars(in_ *in)
{
	int a = 0;
	list_t *nod;

	for (a = 0; in->arr[a]; a++)
	{
		if (in->arr[a][0] != '$' || !in->arr[a][1])
			continue;

		if (!_str_cmp(in->arr[a], "$?"))
		{
			rep_str(&(in->arr[a]),
					_str_dup(convertnumber(in->stat, 10, 0)));
			continue;
		}
		if (!_str_cmp(in->arr[a], "$$"))
		{
			rep_str(&(in->arr[a]),
					_str_dup(convertnumber(getpid(), 10, 0)));
			continue;
		}
		nod = node_start(in->env, &in->arr[a][1], '=');
		if (nod)
		{
			rep_str(&(in->arr[a]),
					_str_dup(str_chr(nod->str, '=') + 1));
			continue;
		}
		rep_str(&in->arr[a], _str_dup(""));
	}
	return (0);
}
/**
 * rep_str - replaces a string
 * @ol: address of the old string
 * @nw: new string
 * Return: 1 or 0 otherwise
 */
int rep_str(char **ol, char *nw)
{
	free(*ol);
	*ol = nw;
	return (1);
}
