#include "main.h"

/**
 * _strncmp -  compares two strings to find out if they are exactly the same
 * @name: input supplied by the user
 * @var: variable to compare against
 * @len: length of the input
 *
 *Return: 1 if strings are equal, -1 if they are not
*/
int _strncmp(char *name, char *var, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		if (name[i] != var[i])
			return (-1);
		i++;
	}
	return (1);
}

