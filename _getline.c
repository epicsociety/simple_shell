#include "main.h"

/**
 * _getline - puts input from user into buffer line
 * fp: buffer that has the input
 *
 * Return: buffer with user input
*/
char *_getline(FILE *fp)
{
	char *buf;
	ssize_t stream;
	size_t len = 0;

	buf = NULL;

	stream = getline(&buf, &len, fp);
	if (stream == -1)
	{
		free(buf);
		exit(EXIT_SUCCESS);
	}

	return (buf);
}
