#include "shell.h"
/**
 * _getline - Puts input from user
 * @p: buffer for user input
 * Return: buffer with user input
 */
char *_getline(FILE *p)
{
	char *my_line;
	ssize_t msg;
	size_t len;

	my_line = NULL;
	len = 0;
	msg = getline(&my_line, &len, p);
	if (msg == -1)
	{
		free(my_line);
		exit(EXIT_SUCCESS);
	}

	return (my_line);
}
