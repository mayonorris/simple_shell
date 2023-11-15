#include "shell.h"

/**
 * tokenizer - Tokenization
 * @str: The input string
 * Return: pointer to array of tokens
 */
char **get_token(char *str)
{
	char **token;
	char *tok;
	unsigned int i;

	token = malloc(sizeof(char) * BUFFER);
	if (token == NULL)
	{
		print_errors(3);
		exit(EXIT_FAILURE);
	}

	tok = strtok(str, "\n\t\r ");

	i = 0;
	while (tok != NULL)
	{
		token[i] = tok;
		tok = strtok(NULL, "\n\t\r ");
		i++;
	}

	token[i] = NULL;

	return (token);
}
