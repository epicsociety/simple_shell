#include "main.h"

/**
 * main - Main function creates a shell, calls other functions
 *
 * Return: 0 always
*/
int main(void)
{
	char *line;
	struct stat buf;
	
	while(1) /* True, infinite loop */
	{
		prompt(STDIN_FILENO, buf);/*STDIN_FILENO MACRO== file descriptor == 0*/
		line = _getline(stdin);/*FILE * line = input cmd*/
		if (_strncmp(line,  "\n", 1) == 0)
		{
			free(line);
			continue;
		}
	}
	
	return (0);
}
