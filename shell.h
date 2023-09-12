#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for reading and wrting buffers */
#define READ_BUFFSIZE 1024
#define WRITE_BUFFSIZE 1024
#define BUFFLUSH -1

/* command chaining */
#define CMDNORM	0
#define CMDOR		1
#define CMDAND		2
#define CMDCHAIN	3

/* convert_number */
#define CONVERT_LOWER_CASE	1
#define CONVERT_UNSIGNED_	2

/* getline */
#define _GETLINE 0
#define _STRTOK 0

#define H_FILE
#define H_MAX	4096

extern char **environ;


/**
 * struct listd - singly linked list
 * @num: number field
 * @str: string
 * @n: points to the next node
 */
typedef struct listd
{
	int num;
	char *str;
	struct listd *n;
} list_t;

/**
 *struct info - has arguements to pass into a function
 *@str: string with arguments from getline
 *@arr: array ofstrings from str
 *@path: string path for current command
 *@argc: argument count
 *@err_count: error count
 *@num_err: error code for exit
 *@linecount: counts this line of input
 *@filename: the program filename
 *@env: linked list copy of environ
 *@environ:copy of environ from LL env
 *@h: history node
 *@alias:alias node
 *@change_env: on if environ changes
 *@stat: return status of the last executed command
 *@buffcmd: address of pointer to cmd
 *@cmd_bufftype: CMD type
 *@readf: reads line input
 *@hcount: history line count
 */
typedef struct info
{
	char *str;
	char **arr;
	char *path;
	int argc;
	unsigned int err_count;
	int num_err;
	int linecount;
	char *filename;
	list_t *env;
	list_t *h;
	list_t *alias;
	char **environ;
	int change_env;
	int stat;

	char **buffcmd;
	int cmd_bufftype;
	int readf;
	int hcount;
} info_t;

#define INFO_INIT_ \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string
 *@type: builtin command flag
 *@funct: the function
 */
typedef struct builtin
{
	char *type;
	int (*funct)(info_t *);
} builtin_t;


/*loop.c */
int hsh(info_t *, char **);
int builtin(info_t *);
void cmd(info_t *);
void fork_cmd(info_t *);

/* path.c */
int cmd(info_t *, char *);
char *duplicate_chars(char *, int, int);
char *findpath(info_t *, char *, char *);

/* loop_hsh.c */
int loop_hsh(char **);

/* errors.c */
void _puts(char *str);
int _putchar(char ch);
int _putf(char ch, int f);
int _putsf(char *str, int f);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* exit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* token.c */
char **strtok(char *, char *);
char **strtok(char *, char);

/* realloc.c */
char *_memset(char *, char, unsigned int);
void free(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* mem.c */
int free(void **);

/* atoi.c */
int inter(info_t *);
int delim(char, char *);
int isalpha(int);
int atoi(char *);

/* errors1.c */
int err_atoi(char *e);
void printerr(info_t *p, char *str);
int printd(int in, int fd);
char *convertnumber(long int n, int b, int f);
void rm_comments(char *buff);

/* builtin.c */
int _exit(info_t *info);
int _cd(info_t *);
int help(info_t *);

/* builtin1.c */
int _history(info_t *);
int _alias(info_t *);

/*getline.c */
ssize_t _input(info_t *info, char **buff, size_t *length);
ssize_t inputbuff(info_t *info, char **buff, size_t *length);
ssize_t getinput(info_t *info);
ssize_t readbuff(info_t *info, char *buff, size_t *s);
int getline(info_t *info, char **add, size_t *len);
void handler(int);

/* getinfo.c */
void clear(info_t *info);
void set(info_t *info, char **q);
void free(info_t *info, int k);

/* environ.c */
char *getenv(info_t *, const char *);
int _env(info_t *);
int setenv(info_t *);
int unsetenv(info_t *);
int _env_list(info_t *);

/* getenv.c */
char **_getenviron(info_t *);
int unsetenv(info_t *, char *);
int setenv(info_t *, char *, char *);

/* history.c */
char *gethistory_file(info_t *info);
int w_history(info_t *info);
int r_history(info_t *info);
int build_historylist(info_t *info, char *buf, int linecount);
int _numberhistory(info_t *info);

/* lists.c */
list_t *addnode(list_t **, const char *, int);
list_t *addnode_end(list_t **, const char *, int);
size_t print_strlist(const list_t *);
int delete_node(list_t **, unsigned int);
void freelist(list_t **);

/* lists1.c */
size_t listlen(const list_t *);
char **liststrings(list_t *);
size_t printlist(const list_t *);
list_t *node_start(list_t *, char *, char);
ssize_t node_index(list_t *, list_t *);

/* var.c */
int chain(info_t *, char *, size_t *);
void checkchain(info_t *, char *, size_t *, size_t, size_t);
int rep_alias(info_t *);
int rep_vars(info_t *);
int rep_string(char **, char *);

#endif
