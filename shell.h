#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER 1024
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct list_s - A linked list of variables
 * @value: value
 * @next: pointer to next node
 *
 * Description: generic linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - A linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: Structure for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void cmd(int file_descriptor, struct stat buf);
char *_getline(FILE *p);
char **get_token(char *str);
char *_path(char *cmd, char *thepath, char *path);
int ch_pid(char *thepath, char **token);
void print_errors(int er);

void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_builtins(built_s builtin[]);

char *get_env(const char *var_env);
char **_env(char **env_cp, unsigned int env_len);
list_s *pathlist(char *variable, list_s *head);
void _free(char **token, char *path, char *my_line, char *thepath, int flag);
void free_dp(char **array, unsigned int length);

#endif /* SHELL_H */
