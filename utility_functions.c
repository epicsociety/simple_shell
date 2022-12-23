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

/**
 * _strdup - duplicates one string into another
 * @src: the source string to be duplicated
 *
 * Return: a pointer to a duplicate of the string
*/

/**
char *_strdup(const char *src)
{
	int i;
	int len;
	char *dest;

	len = _strlen(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
*/

/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 *
 * Return: the pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * print_list_str - prints the list
 * @list_t: the list
 *
 * Return: printed list
*/
size_t print_list_str(const list_t *list)
{
	size_t i;

	for (i = 0; list != NULL; i++) 
	{
		printf("%s\n", list->str);
		list = list->next;
	}
	return (i);
}
