#ifndef SHELL_H
#define SHELL_H

/*Function Header*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - A function to get the singly linked "list_t" list
 * @num: represent the num to get the linked list
 * @str: A string source to be used
 * @next: A pointer to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_x;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - This function has all the related builtin functions
 * @func: the function
 * @type: The type of builtin flag
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_x *);
} builtin_table;



/* All Function Prototypes included Here */

/* shell.c prototypes*/
int hsh(info_x *, char **);

/* Custom.c prototypes */
int find_builtin(info_x *);
void find_cmd(info_x *);
void fork_cmd(info_x *);

/* path function protoypes*/
int is_cmd(info_x *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_x *, char *, char *);
int loophsh(char **);

/* error function prototypes*/
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* handle string prototypes*/
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/*put.c prototypes*/
void _puts(char *);
int _putchar(char);

/* special_stringfunc */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* memory functions */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);

/* interactive functions */
int interactive(info_x *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/*Special Function prototype */
int _erratoi(char *);
void print_error(info_x *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin functions */
int _myexit(info_x *);
int _mycd(info_x *);
int _myhelp(info_x *);
int _myhistory(info_x *);
int _myalias(info_x *);

/* getline functions */
ssize_t get_input(info_x *);
int _getline(info_x *, char **, size_t *);
void sigintHandler(int);

/* set_info functions */
void clear_info(info_x *);
void set_info(info_x *, char **);
void free_info(info_x *, int);

/* environment functions */
char *_getenv(info_x *, const char *);
int _myenv(info_x *);
int _mysetenv(info_x *);
int _myunsetenv(info_x *);
int populate_env_list(info_x *);
char **get_environ(info_x *);
int _unsetenv(info_x *, char *);
int _setenv(info_x *, char *, char *);

/* get history functions */
char *get_history_file(info_x *info);
int write_history(info_x *info);
int read_history(info_x *info);
int build_history_list(info_x *info, char *buf, int linecount);
int renumber_history(info_x *info);

/* handle node functions */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* handle vars functions*/
int is_chain(info_x *, char *, size_t *);
void check_chain(info_x *, char *, size_t *, size_t, size_t);
int replace_alias(info_x *);
int replace_vars(info_x *);
int replace_string(char **, char *);

#endif /*Credit  Brian Ngumbau, Javis Mathews*/
