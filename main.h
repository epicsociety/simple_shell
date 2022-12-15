#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "$ " /* error strings */
#define BUFFER 1024

char *_getline(FILE *fp);
void prompt(int fd, struct stat buf);
char **tokenizer(char *str);

/*Utility functions (string tools)*/
int _strncmp(char *name, char *var, unsigned int len);

/*Other essential functions */



#endif
