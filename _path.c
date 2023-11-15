#include "shell.h"
/**
 * _path - Looks for directories
 * @cmd: To search for
 * @thepath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *_path(char *cmd, char *thepath, char *path)
{
	char *pc, *tok;
	unsigned int cmd_length, len, main_path_len;

	cmd_length = _strlen(cmd);
	main_path_len = _strlen(path);
	pc = malloc(sizeof(char) * main_path_len + 1);
	if (pc == NULL)
	{
		print_errors(3);
		return (NULL);
	}
	_strcpy(pc, path);

	tok = strtok(pc, ":");
	if (tok == NULL)
		tok = strtok(NULL, ":");
	while (tok != NULL)
	{
		len = _strlen(tok);
		thepath = malloc(sizeof(char) * (len + cmd_length) + 2);
		if (thepath == NULL)
		{
			print_errors(3);
			return (NULL);
		}
		_strcpy(thepath, tok);
		thepath[len] = '/';
		_strcpy(thepath + len + 1, cmd);
		thepath[len + cmd_length + 1] = '\0';
		if (access(thepath, X_OK) != 0)
		{
			free(thepath);
			thepath = NULL;
			tok = strtok(NULL, ":");
		}
		else
			break;
	}
	free(pc);
	return (thepath);
}
