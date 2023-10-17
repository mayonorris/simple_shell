#include "shell.h"

int test()
{
	char *str;
	char *token;

	str = my_strdup("this is\t our shell\n");

	token = strtok(str, " \t\n");
	write(STDOUT_FILENO, &token, _strlen(token));
	return (0);
}
