#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
char *_error(char *namefile, char **buf);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void _prompt(void);
char **splitInput(char *array);
void duplicateProcess(char *array, char **space);
void enviromentShell(char **space);
void exitof(char **space, char *array);
void writeInput(char *buf);
#endif
