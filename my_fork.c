#include "shell.h"
/**
 * my_fork_and_wait - creates process
 * @status: checks status
 * Return: 0 success or -1 if fail
 */
pid_t my_fork_and_wait(int *status)
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        exit(0);
    }
    else if (pid == -1)
    {
        return (-1);
    }
    else
    {
        wait(status);
        return (pid);
    }
}

