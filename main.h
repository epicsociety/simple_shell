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

/*Utility functions (string tools)*/
int _strncmp(char *name, char *var, unsigned int len);
int _strcmp(char *, char *);
char *_strdup(char *);
void print_str(char *, int);
int print_number(int);
int _write_char(char);

/*Other essential functions */

/* builtin functions */
void cd_p(char *);


#endif
