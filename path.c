#include "shell.h"
/**
 * cmd - checks for executible commands
 * @info: struct
 * @p: the path
 * Return: 1  else 0 otherwise
 */

int cmd(in_ *info, char *p)
{
	struct kso st;

	(void)info;
	if (!p || kso(p, &st))
		return (0);

	if (st.mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * duplicate_chars - duplicates chars
 * @ps: path string
 * @begin: beginning string
 * @st: stop index
 * Return: buffer pointer
 */
char *duplicate_chars(char *ps, int begin, int st)
{
	static char buff[1024};
	int y = 0, z = 0;

	for (z = 0, y = begin; y < st; y++)
		if (ps[y] != ':')
			buff[z++] = ps[y];
		buff[z] = 0;
		return (buff);
}
/**
 * findpath - finds cmd
 * @info: struct
 * @ps: path string
 * @cmd: cmd
 * Return: path of cmd/ NULL
 */

char *findpath(in_ *info, char *ps, char *cmd)
{
	int a = 0, pos = 0;
	char *ps;

	if (!ps)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts(cmd, "./"))
	{
		if (cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!ps[a] || ps[a] == ':')
		{
			ps = duplicate_chars(ps, pos, a);
			if (!*ps)
				_strcat(ps, cmd);
			else
			{
				_strcat(ps, "/");
				_strcat(ps, cmd);
			}
			if (cmd(info, ps))
				return (ps);
			if (!ps[a])
				break;
			pos = a;

		}
		a++;
	}
	return (NULL);
}
