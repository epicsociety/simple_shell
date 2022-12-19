#include "main.h"

/**
  * cd_p - changes the current directory of the process.
  * If no argument is given to cd the command must be interpreted like cd $HOME
  * @line: Astring representing the input from the user.
  */

void cd_p(char *line)
{
	int index, token_count;
	char **param_array;
	const char *delim = "\n\t ";

	token_count = 0;
	param_array = token_interface(line, delim, token_count);
	if (param_array[0] == NULL)
	{
		single_free(2, param_array, line);
		return;
	}
	if (param_array[1] == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(param_array[1], "-") == 0)
		print_str(param_array[1], 0);
	else
		chdir(param_array[1]);
	double_free(param_array);
}
