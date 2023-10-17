#include "shell.h"
/**
 * my_token - A function that tokanize the input from the stream
 *@my_line: an input string
 * Return: the command
 */
char **my_token(char *my_line)
{
char *the_token = NULL;
char **command = NULL;
int counter = 0;
char *temp;
int i = 0;

if (!my_line)
	return (NULL);
temp = my_strdup(my_line);

the_token = strtok(temp, " ");

if (the_token == NULL)
	return (NULL);
while (the_token)
{
counter++;
the_token = strtok(NULL, " ");
}
free(temp);

command = malloc(sizeof(char *) * (counter + 1));
if (!command)
{
	free(my_line);
	return (NULL);
}
the_token = strtok(my_line, " ");

while (the_token)
{
command[i] = the_token;
the_token = strtok(NULL, " ");
i++;
}
free(my_line);
free(command[i]);
return (command);
}

