#include "shell.h"

/**
 * get_env - Gets an environment var
 * @var_env: The environment var to get
 * Return: A pointer to environment var or NULL
 */
char *get_env(const char *var_env)
{
	char **env_cp;
	char *var, *value, *path;
	int cmp;
	unsigned int path_len, env_len, len, i;

	env_len = 0;
	while (environ[env_len] != NULL)
		env_len++;
	env_cp = NULL;
	env_cp = _env(env_cp, env_len);

	len = _strlen((char *)var_env);
	i = 0;
	while (env_cp[i] != NULL)
	{
		var = env_cp[i];
		cmp = _strncmp((char *)var_env, var, len);
		if (cmp == 1)
		{
			value = strtok(var, "=");
			value = strtok(NULL, "\n ");
			if (value == NULL)
			{
				print_errors(4);
				exit(EXIT_FAILURE);
			}
			path_len = _strlen(value);
			path = malloc(sizeof(char) * path_len + 1);
			if (path == NULL)
			{
				print_errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(env_cp, env_len);
			return (path);
		}
		i++;
	}
	return (NULL);
}
