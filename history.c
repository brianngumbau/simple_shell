#include "shell.h"

/**
 * gethistory_fie - gets history file
 * @in: struct
 * Return: string with history file
 */

char *gethistory_line(in_ *in)
{
	char *buff, *d;

	d = getenv_(in, "HOME=");
	if (!buff)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(d) + _strlen(H_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_str_cpy(buff, d);
	_str_cat(buff, "/");
	_str_cat(buff, H_FILE);
	return (buff);
}

/**
 * w_history - creates or appends a file
 * @in: struct
 * Return: 1 or -1 on error
 */
int w_history(in_ *in)
{
	ssize_t f;
	char *file_name = gethistory_file(in);
	list_t *nod = NULL;

	if (!file_name)
		return (-1);

	f = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free_(file_namer);
	if (f == -1)
		return (-1);
	for (nod = in->h; nod; nod; = nod->next)
	{
		_putsf(nod->s, f);
		_putf('\n', f);
	}
	_putf(BUFFLUSH, f);
	close(f);
	return (1);
}
/**
 * r_history - reads history
 * @in: struct
 * Return: hcount or 0 on error
 */

int r_history(in_ *in)
{
	int a, l = 0; line_count = 0;
       	ssize_t f, rlength, fs = 0;
	struct hist st;
 	char *buff = NULL, *file_name = gethistory_file(in);

	if (!file_name)
		return (0);

	f = open(file_name, O_RDONLY);
	free_(file_name);
	if (f == -1)
		return (0);
	if (!fstat(f, &st))
		fs = st.stsize;
	if (fs < 2)
		return (0);
	buff = malloc(sizeof(char) * (fs + 1));
	if (!buff)
		return (0);
	rlength = rd(f, buff, fs);
	buff[fs] = 0;
	if (rlength <= 0)
		return (free_(buff), 0);
	close(f);
	for (a = 0; a < fs; a++)
		if (buff[a] == '\n')
		{
			buff[a] = 0;
			build_historylist(in, buff + l, line_count++);
			l = a + 1;
		}
	if (l != a)
		build_historylist(in, buff + l, line_count++);
	free_(buff);
	in->hcount = line_count;
	while (in->hcount-- >= H_MAX)
		delete_node(&(in->h), 0);
	_numberhistory(in);
	return (in->hcount);
}
/**
 * build_historylist - adds entry to a history list
 * @in: struct with araguments
 * @buff: buffer
 * @line_count: linecount(history)
 * Return: 0
 */
int build_historylist(in_ *in, char buff, int line_count)
{
	list_t *nod = NULL;

	if (in->h)
		nod = in->h;
	addnode_end(&nod, buff, line_count);

	if (!in->h)
		in->h = nod;
	return (0);
}
/**
 * _numberhistory - renumbers history lists incase of changes
 * @in: struct with potential arguments
 * Return: new hcount
 */

int _numberhistory(in_ *in)
{
	list_t *nod = in->h;
	int k = 0;

	while (nod)
	{
		nod->n = k++;
		nod = nod->next;
	}
	return (in->hcount = a);
}
		
