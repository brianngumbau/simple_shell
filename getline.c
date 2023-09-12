#include "shell.h"
/**
 * inputbuff - buffer chained command
 * @info: struct
 * @add: address
 * @length: address
 * Return: bytes
 */
ssize_t inputbuff(info_t *info, char **buff, size_t *length)
{
	ssize_t g = 0;
	size_t l = 0;

	if (!*length)
	{
		free(*buff);
		*buff = NULL;
		
		signal(SIGINT, handler);
		
		g = getline(info, buff, &l);

		if (g > 0)
		{
			if ((*buff)[g - 1] == '\n')
			{
				(*buff)[g - 1] = '\0';
				g--;
			}
			info->linecountflag = 1;
			rm_comments(*buff);
			build_historylist(info, *buff, info->hcount++);
			{
				*length = g;
				info->buffcmd = buff;
			}
		}
	}
	return (g);
}
/**
 * getinput - gets a line less the newline
 * @info: struct
 * Return: bytes
 */

ssize_t getinput(info_t *info)
{
	static char *buff;
	static size_t a, b, length;
	ssize_t g = 0;
	char **buff_p = &(info->argc), *p;

	_putchar(BUFFLUSH);
	g = inputbuff

