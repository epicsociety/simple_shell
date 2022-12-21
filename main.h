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


char *_getline(FILE *fp);
void prompt(int fd, struct stat buf);
char **tokenizer(char *str);
char **token_interface(char *, const char *, int);
char **tokenize(int, char *, const char *);
int find_path(char *);
int str_len(char *);
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
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);


/* builtin functions */
void cd_p(char *);

/*Helper functions (string tools)*/
int _strcmp(char *, char *);
int _strlen(char *str);
char *_strdup(char *);
void print_str(char *, int);
int print_number(int);
int _write_char(char);
int _strncmp(char *name, char *var, unsigned int len);
char *_strcpy(char *dest, char *src);

#endif
