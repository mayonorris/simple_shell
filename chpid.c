#include "shell.h"

/**
 * ch_pid - Child process
 * @thepath: The executable path
 * @token: tokenized user input
 * Return: 0 on success
 */
int ch_pid(char *thepath, char **token)
{
	pid_t child_pid;
	int status, stat_exec;
	char **env_process = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		stat_exec = execve(thepath, token, env_process);
		if (stat_exec == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
