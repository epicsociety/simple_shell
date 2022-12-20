#include "main.h"

/**
 * print_str - Prints a string character by character.
 * @str: String to be printed. If the string is NULL it will print (null)
 * @new_line: If integer is 0 a new line will be printed. Otherwise a new line
 * will not be printed.
 */

void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}

char *_strdup(char *src)
{
	int i;
	int len;
	char *dest;

	len = str_len(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}