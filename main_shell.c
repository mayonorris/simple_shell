#include "shell.h"
/**
 * main_shell - The main function of our shell
 * @ac: counts the number of arguments
 * @av: arguments array
 * Return: 0 Always for success case
*/
int main(int ac, char **argv)
{
        char *my_line = NULL;
        /*char **command = NULL;*/
        int check_exec = 0;
        (void) ac;
        (void) argv;

        while(1)
        {
        my_line = get_line();

        if(my_line == NULL)
        {
                write(STDOUT_FILENO, my_line, strlen(my_line));
		write(STDOUT_FILENO, "\n", 1);
                return (check_exec);

        }

        free(my_line);
        /*command = get_token(my_line);*/

        }


}
