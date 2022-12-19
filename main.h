#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int find_path(char *);
void double_free(char **);

/*Utility functions (string tools)*/
int _strncmp(char *name, char *var, unsigned int len);

/*Other essential functions */

/* builtin functions */
void cd_p(char *);

/*Holberton library functions*/
int _strcmp(char *, char *);
char *_strdup(char *);
void print_str(char *, int);
int print_number(int);
int _write_char(char);

#endif
