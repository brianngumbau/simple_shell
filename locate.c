#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void sig_handler(int sig);
void search_files(const char *directory, const char *filename);

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	signal(SIGINT, sig_handler);

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	const char *filename = argv[1];
	const char *search_directory = "/";

	search_files(search_directory, filename);

	return (0);
}

/**
 * sig_handler - sig handler
 * @sig: signal
 * Return: void
 */
void sig_handler(int sig)
{
	(void)sig;
	signal(SIGINT, sig_handler);
	printf("\n");
}

/**
 * search_files - searches for files
 * @directory: directory of the file
 * @filename: filename of file required
 * Return: empty
 */
void search_files(const char *directory, const char *filename)
{
	DIR *dir;
	struct dirent *entry;

	if ((dir == opendir(directory)) == NULL)
	{
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") == 0
			|| strcmp(entry->d_name, "..") == 0) {
			continue;
		}

		char path[1024];

		snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

		if (entry->d_type == DT_DIR)
			search_files(path, filename);
		else if (strcmp(entry->d_name, filename) == 0)
		{
			printf("Found: %s\n", path);
		}
	}

	closedir(dir);
}

