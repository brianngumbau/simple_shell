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
} in_;

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
	int (*funct)(in_ *);
} builtin_t;


/*loop.c */
int loop(in_ *in, char **argv);
int builtin(in_ *in);
void fcmd(in_ *in);
void f_cmd(in_ *in);

/* path.c */
int cmd_(in_ *info, char *p);
char *duplicate_chars(char *ps, int begin, int st);
char *findpath(in_ *info, char *ps, char *cmd);

/* loop_hsh.c */
int loop_hsh(char **);

/* errors.c */
void _puts(char *str);
int _putchar(char ch);
int _putf(char ch, int f);
int _putsf(char *str, int f);

/* string.c */
int _str_len(char *);
int _str_cmp(char *, char *);
char *starts(const char *, const char *);
char *_str_cat(char *, char *);

/* string1.c */
char *_str_cpy(char *, char *);
char *_str_dup(const char *);
void _puts(char *);
int _putchar(char);

/* exit.c */
char *str_ncpy(char *d, char *s, int i);
char *str_ncat(char *d, char *s, int i);
char *str_chr(char *str, char ch);

/* token.c */
char **strtok_(char *, char *);
char **strtok_(char *, char);

/* realloc.c */
char *mem_set(char *p, char byt, unsigned int i);
void f_ree(char **ss);
void *re_alloc(void *p, unsigned int o_size, unsigned int n_size);

/* mem.c */
void free_(void **add);

/*_atoi.c */
int inter_(in_ *);
int delim_(char, char *);
int isalpha_(int);
int atoi_(char *);

/* errors1.c */
int err_atoi(char *e);
void printerr(in_ *p, char *str);
int printd(int in, int fd);
char *convertnumber(long int n, int b, int f);
void rm_comments(char *buff);

/* builtin.c */
int _exit(in_ *in);
int _cd(in_ *in);
int help(in_ *in);

/* builtin1.c */
int _history(in_ *);
int unalias(in_ *);
int setalias(in_ *in, char *s);
int palias(list_t *nod);
int _alias(in_ *);

/*getline.c */
ssize_t _input(in_ *info, char **buff, size_t *length);
ssize_t inputbuff(in_ *info, char **buff, size_t *length);
ssize_t getinput(in_ *info);
ssize_t readbuff(in_ *info, char *buff, size_t *s);
int getline(in_ *info, char **add, size_t *len);
void handler(int);

/* getinfo.c */
void clear(in_ *info);
void set(in_ *info, char **q);
void free_in(in_ *info, int k);

/* environ.c */
char *getenv_(in_ *, const char *nm);
int _env(in_ *in);
int setenv(in_ *in);
int unsetenv(in_ *in);
int _env_list(in_ *in);

/* getenv.c */
char **_getenviron(in_ *in);
int unsetenv(in_ *in, char *v);
int setenv(in_ *in, char *v, char *val);

/* history.c */
char *gethistory_file(in_ *in);
int w_history(in_ *in);
int r_history(in_ *in);
int build_historylist(in_ *in, char *buff, int line_count);
int _numberhistory(in_ *in);

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
int chain(in_ *in, char *buff, size_t *add);
void ckchain(in_ *in, char *buff, size_t *add, size_t s, size_t length);
int rep_alias(in_ *in);
int rep_vars(in_ *in);
int rep_str(char **ol, char *nw);

#endif
