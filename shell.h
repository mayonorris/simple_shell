#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>


char *get_line(void);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *str);
int my_strcmp(const char *s1, const char *s2, size_t n);
int _strlen(char *s);
pid_t my_fork_and_wait(int *status);
int test();
char **my_token(char *my_line);
#endif
