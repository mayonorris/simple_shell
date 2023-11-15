#include "shell.h"
/**
 * main - Run basic shell
 * Return: 0 on success
 */
int main(void)
{
	struct stat buf;
	char *my_line, *path, *thepath;
	char **token;
	int flag, status, ch_status;

	while (1)
	{
		cmd(STDIN_FILENO, buf);
		my_line = _getline(stdin);
		if (_strcmp(my_line, "\n", 1) == 0)
		{
			free(my_line);
			continue;
		}
		token = get_token(my_line);
		if (token[0] == NULL)
			continue;
		status =  builtin_execute(token);
		if (status == 0 || status == -1)
		{
			free(token);
			free(my_line);
		}
		if (status == 0)
			continue;
		if (status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		path = get_env("PATH");
		thepath = _path(token[0], thepath, path);
		if (thepath == NULL)
			thepath = token[0];
		else
			flag = 1;
		ch_status = ch_pid(thepath, token);
		if (ch_status == -1)
			print_errors(2);
		_free(token, path, my_line, thepath, flag);
	}
	return (0);
}
