#include "shell.h"
/**
* builtin_execute - A function to execute the built in functions
* @token: Arguments being passed
* Return: Tokens
**/
int builtin_execute(char **token)
{
	int status;
	unsigned int n;
	unsigned int i;
	unsigned int len;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (token[0] == NULL)
		return (1);

	len = _strlen(token[0]);

	n = shell_builtins(builtin);
	for (i = 0; i < n; i++)
	{
		if (_strcmp(token[0], builtin[i].name, len) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
**shell_builtins - Checks  built-ins
**@builtin: Takes the builtin to be counted
**Return: The number of built-ins
**/

int shell_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (i);
}
