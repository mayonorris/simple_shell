#include "shell.h"

/**
 * _env - copies environment var
 * @env_cp: pointer to copy of environment var
 * @env_len: len of environment var
 * Return: double pointer to copy of environment var
 */
char **_env(char **env_cp, unsigned int env_len)
{
	char *var;
	unsigned int var_len;
	unsigned int i;

	env_cp = malloc(sizeof(char **) * (env_len));
	if (env_cp == NULL)
	{
		print_errors(3);
		return (NULL);
	}

	i = 0;
	while (i < env_len)
	{
		var = environ[i];
		var_len = _strlen(var);

		env_cp[i] = malloc(sizeof(char) * var_len + 1);
		if (env_cp[i] == NULL)
		{
			print_errors(3);
			return (NULL);
		}
		_strcpy(env_cp[i], environ[i]);
		i++;
	}

	return (env_cp);
}
