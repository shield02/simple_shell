#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*
 * extern char **environ;
 * int _strlen(char *s);
 * char **_get_token(char *lineptr);
 * void _exit_command(char **args, char *lineptr, int _exit);
 * int _fork_fun(char **arg, char **av, char **env,
 * char *_strcpy(char *dest, char *src);
 * char *_strcat(char *dest, char *src);
 * int _putchar(char c);
*
*/

char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
void ntcount(int num_tokens, char **argv, char *cmd_cpy);
void execmd(char **argv);
char **_get_token(char *lineptr);
char *_strcpy(char *dest, char *src);
char *_get_path(char **env);
char *_strcat(char *dest, char *src);
extern char *builtins[];
int _execve(char **);
char *_strncpy(char *dest, char *src, int n);
char **splitInput(char *array);
  
/*
 *char *_get_path(char **env);
 * int _values_path(char **arg, char **env);
 * char *_getline_command(void);
 * void _getenv(char **env);
 *
 * char *lineptr, int np, int c);
 * char *_strtok(char *str, const char *delim);
 * i nt _strcmp(char *s1, char *s2);
 * size_t _strncmp(char *s1, char *s2, size_t n);
*/

#endif

