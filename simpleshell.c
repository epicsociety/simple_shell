#include "main.h"

/**
 * main - Main function creates a shell, calls other functions
 *
 * Return: 0 always
*/
int main(void)
{
	char *line, *path, *fullpath;
	char **tokens;
	struct stat buf;
	int builtin_status, flag, child_status;

	while (1) /* True, infinite loop */
	{
		prompt(STDIN_FILENO, buf);/*STDIN_FILENO MACRO== file descriptor == 0*/
		line = _getline(stdin);/*FILE * line = input cmd*/
		if (_strncmp(line,  "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = tokenizer(line);
		if (tokens[0] == NULL)
			continue;
		builtin_status = builtin_execute(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens);
			free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0; /* 0 if full_path is not malloc'd */
		path = _getenv("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1; /* if fullpath was malloc'd, flag to free */
		child_status = child(fullpath, tokens);
		if (child_status == -1)
			errors(2);
		free_all(tokens, path, line, fullpath, flag);
	}

	return (0);
}
