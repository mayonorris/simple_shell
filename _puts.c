#include "shell.h"

/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: nothing
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}
