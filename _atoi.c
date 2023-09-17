#include "shell.h"

/**
 * inter_ - checks if shell is in interactive mode
 * @in: address of struct
 * Return: 1 if it succeeds 0 otherwise
 */

int inter_(info_t *in)
{
	return (isatty(STDIN_FILENO) && in->readf <= 2);
}

/**
 * delim_ - checks for delimeter characters
 * @ch: char to check
 * @del: delimeter string
 * Return: 1 or 0 if it fails
 */
int delim_(char ch, char *del)
{
	while (*del)
		if (*del++ == ch)
			return (1);
	return (0);
}

/**
 * isalpha_ - checks for alphabetic chars
 * @ch: character
 * Return: 1 if ch is alapabetic 0 otherwise
 */

int isalpha_(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * atoi_ - converts string to integer
 * @str: string to convert
 * Return: integer or 0 if no numbers in string
 */

int atoi_(char *str)
{
	int a, s = 1, f = 0, out;
	unsigned int res = 0;

	for (a = 0; str[a] != '\0' && f != 2; a++)
	{
		if (str[a] == '-')
			s *= -1;

		if (str[a] >= '0' && str[a] <= '9')
		{
			f = 1;
			res *= 10;
			res += (str[a] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		out = -res;
	else
		out = res;

	return (out);
}
