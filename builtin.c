#include "shell.h"

/**
 * _exit - exits shell
 * @in: Struct with arguments
 * Return: exit status
 */
int _exit(in_ *in)
{
	int exitch;

	if (in->argv[1])
	{
		exitch = err_atoi(in->argv[1]);
		if (exitch == -1)
		{
			in->stat = 2;
			printerror(in, "Illegal: ");
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		} in->num_err = err_atoi(in->argv[1]);
		return (-2);
	}
	in->num_ = -1;
	return (-2);
}

/**
 * _cd - changes directory
 * @in: Struct with arguments
 * Return: 0
 */
int _cd(in_ *in)
{
	char *c, *d, buff[1024];
	int cdir_t;

	c = getcwd(buff, 1024);
	if (!c)
		_puts("TODO: >>getcwd failure here<<\n");
	if (!in->argv[1])
	{
		d = getenv_(in, "Home=");
		if (!d)
			cdir_t =
				chdir((d = getenv(in, "Pwd=")) ? d : "/");
		else
			cdir_t = chdir(d);
	}
	else if (_str_cmp(in->argv[1], "-") == 0)
	{
		if (!getenv_(in, "Oldpwd="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getenv_(in, "Olpwd=")), _putchar('\n');
		cdir_t =
			chdir((dir = _getenv(info, "OLDPWD=")) ? d : "/");
	}
	else
		cdir_t = chdir(in->argv[1]);
	if (cdir_t == -1)
	{
		printerr(in, "can't change directory ");
		_puts(in->argv[1]), _putchar('\n');
	}
	else
{
		setenv(in, "Olpwd", getenv_(in, "Pwd="));
		setenv(in, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
 * help - changes the current directory of the process
 * @in: Struct with arguments
 * Return: 0
 */
int help(in_ *in)
{
	char **arr;

	arr = in->argv;
	_puts("Function not yet implemented help call works \n");
	if (0)
		_puts(*arr);
	return (0);
}
