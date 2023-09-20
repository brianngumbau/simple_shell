#include "shell.h"

/**
 * hsh - main shell loop
 * @in: struct
 * @argv: argument vector
 *
 * Return: 0, 1 on error
 */
int loop(in_ *in, char **argv)
{
	ssize_t t = 0;
	int built_t = 0;

	while (t != -1 && built_t != -2)
	{
		clear(in);
		if (inter_(in))
			_puts("$ ");
		_putchar(BUFFLUSH);
		t = getinput(in);
		if (t != -1)
		{
			set(in, argv);
			built_t = builtin(in);
			if (built_t == -1)
				f_cmd(in);
		}
		else if (inter_(in))
			_putchar('\n');
		free_(in, 0);
	}
	w_history(in);
	free_(in, 1);
	if (!inter_(in) && in->stat)
		exit(in->stat);
	if (built_t == -2)
	{
		if (in->num_err == -1)
			exit(in->stat);
		exit(in->err_num);
	}
	return (built_t);
}

/**
 * builtin - finds builtin commands
 * @in: struct
 * Return: 0 , -1 if not found, 1 if found but successful
 */
int builtin(in_ *in)
{
	int x, built_t = -1;
	builtintable bu[] = {
		{'exit', _exit},
		{'env', _env},
		{'help', help},
		{'history', _history},
		{'setenv', setenv},
		{'unsetenv', unsetenv},
		{'cd',_cd},
		{'alias', _alias},
		{NULL, NULL}
	};

	for (x = 0; bu[x].type; x++)
		if (_str_cmp(in->arr[0], bu[x].type) == 0)
		{
			in->linecount++;
			built_t = bu[x].func(in);
			break;
		}
	return (built_t);
}

/**
 * f_cmd - finds command in path
 * @in: struct
 * Return: empty
 */
void f_cmd(in_ *in)
{
	char *pt = NULL;
	int m, n;

	in->*pt = in->arr[0];
	if (in->linecount == 1)
	{
		in->linecount++;
		in->linecount = 0;
	}
	for (m = 0, n = 0; in->arr[m]; m++)
		if (!delim_(in->arr[m], " \t\n"))
			n++;
	if (!n)
		return;

	pt = findpath(in, getenv_(in, "Path="), in->arr[0]);
	if (pt)
	{
		in->pt = pt;
		f_cmd(in);
	}
	else
	{
		if ((inter_(in) || getenv_(in, "Path=")
					|| in->arr[0][0] == '/') && cmd_(in, in->arr[0]))
			f_cmd(in);
		else if (*(in->arr) != '\n')
		{
			in->stat = 127;
			printerr(in, "Not found\n");
		}
	}
}

/**
 * f_cmd - forks to run cmd
 * @in: struct
 * Return: empty
 */
void f_cmd(in_ *in)
{
	pid_t opp_tek;

	opp_tek = fork();
	if (opp_tek == -1)
	{
		perror("Error ");
		return;
	}
	if (opp_tek == 0)
	{
		if (execve(in->path, in->arr, _getenviron(in)) == -1)
		{
			free_in(in, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}}
	else
	{
		wait(&(in->stat));
		if (WIFEXITED(in->stat))
		{
			in->stat = WEXITSTATUS(in->stat);
			if (in->stat == 126)
				printerr(in, "Permission denied\n");
		}
	}
}

