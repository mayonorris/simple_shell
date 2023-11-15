#include "shell.h"

/**
 * _free - A function that frees all allocated memory
 * @token: pointer to tokens array
 * @path: pointer to path variable
 * @my_line: pointer to user input buffer
 * @thepath: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void _free(char **token, char *path, char *my_line, char *thepath, int flag)
{
	free(path);
	free(token);
	free(my_line);
	if (flag == 1)
		free(thepath);
}
