#include "main.h"

/**
 * builtin_execute - executes the built in functions
 * @tokens: arguments passed
 *
 * Return: tokens
*/
int builtin_execute(char **tokens)
{
	int status;
	unsigned int len, num, i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);

	len = _strlen(tokens[0]);

	num = shell_num_builtins(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strncmp(tokens[0], builtin[i].name, len) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
 * shell_num_builtins - checks the num of built-ins
 * @builtin: takes the list of builtin to be counted
 *
 * Return: num of built-ins
 */
int shell_num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (i);
}
