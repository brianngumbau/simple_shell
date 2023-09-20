#include "shell.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1 on error
 */

int main(int argc, char **argv)
{
	in_ in[] = { INFO_INIT_ };
	int f = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (f)
			: "r" (f));

	if (argc == 2)
	{
		f = open(argv[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts(argv[0]);
				_puts(": 0: Cannot open ");
				_puts(argv[1]);
				_putchar('\n');
				_putchar(BUFFLUSH);
				exit (127);
			}
			return(EXIT_FAILURE);
		}
		in->readf = f;
	}
	_env_list(in);
	r_history(in);
	hsh(in, argv);
	return (EXIT_SUCCESS);
}
