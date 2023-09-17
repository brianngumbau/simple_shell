<<<<<<< HEAD
/*
 * File: getline.c
 * Auth: Brian ngumbau
 *       Javis mathews
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_concat(const char *s1, const char *s2);

int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    char *result = string_concat(str1, str2);

    if (result) {
        printf("Concatenated String: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

char *string_concat(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);

    if (result) {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}
=======
#include "shell.h"
/**
 * inputbuff - buffer chained command
 * @info: struct
 * @add: address
 * @length: address
 * Return: bytes
 */
ssize_t inputbuff(in_ *info, char **buff, size_t *length)
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

ssize_t getinput(in_ *info)
{
	static char *buff;
	static size_t a, b, length;
	ssize_t g = 0;
	char **buff_p = &(info->argc), *p;

	_putchar(BUFFLUSH);
	g = inputbuff
>>>>>>> ac4ce4eb285c3cf9e85adb0c0c668252c5d310eb

