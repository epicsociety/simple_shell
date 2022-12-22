#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define PROMPT "$ " /* error strings */
#define BUFFER 1024

#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions
*/
typedef struct built_s{
	char *name;
	int (*p)(void);
} built_s;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
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
} info_t;


typedef struct builtin_d
{
	char *built;
	void (*f)(char *);
} builtin_t;

char *_getline(FILE *fp);
void prompt(int fd, struct stat buf);
char **tokenizer(char *str);
char **token_interface(char *, const char *, int);
char **tokenize(int, char *, const char *);
int find_path(char *);
int str_len(char *);
void exit_b(char *line);
char *_strcat(char *dest, char *src);
char **list_to_strings(list_t *head);
void double_free(char **);
void single_free(int, ...);
int count_token(char *, const char *);
char *path_finder(char *command);
char **tokenize_path(int index, char *str);
char *build_path(char *directory, char *command);
char *search_directories(char **path_tokens, char *command);
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
char *_which(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void errors(int error);
size_t list_len(const list_t *h);
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);


/* builtin functions */
void cd_b(char *);
void (*check_built_ins(char *str))(char *str);
int built_in(char **command, char *line);
/*Helper functions (string tools)*/
int _strcmp(char *, char *);
int _strlen(const char *);
char *_strdup(const char *);
char *starts_with(const char *, const char *);
void print_str(char *, int);
int print_number(int);
int _write_char(char);
char *_memset(char *, char, unsigned int);
char **get_environ(info_t *);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
int _strncmp(char *name, char *var, unsigned int len);
char *_strcpy(char *dest, char *src);

#endif
