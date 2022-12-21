#include "main.h"

/**
 * single_free - Will free a n amount of pointers to a string.
 * @n: The number of pointers to free.
 */
void single_free(int n, ...)
{
	int i;
	char *str;
	va_list a_list;

	va_start(a_list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(a_list, char *);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(a_list);
}

/**
 * double_free - Free double pointer variables.
 * @to_be_freed: The address of the elements that need to be freed.
 */
void double_free(char **to_be_freed)
{
	int index;

	for (index = 0; to_be_freed[index] != NULL; index++)
		free(to_be_freed[index]);
	free(to_be_freed);
}

/**
 * _strlen - Calculates the lenght of a string.
 * @str: String that needs length to be found.
 * Return: Upon success returns the length of a string. otherwise 0.
 */
int _strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
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

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
