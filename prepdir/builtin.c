#include "main.h"

/**
 * split_input - Split the user input into tokens
 * @array: The string input
 *
 * Return: The set of tokens
 */
char **split_input(char *array)
{
        int counter = 0, i = 0;
        char *tokenC;
        char *token;
        char **space;
        char *array_copy;

        array_copy = strdup(array);
        tokenC = strtok(array_copy, " \n\t");

        while (tokenC != NULL)
        {
                tokenC = strtok(NULL, " \n\t");
                counter++;
        }
        free(array_copy);

        space = malloc(sizeof(char *) * (counter + 1));
        token = strtok(array, " \n\t");

        while (token != NULL)
        {
                space[i] = token;
                token = strtok(NULL, " \n\t");
                i++;
        }
        space[i] = NULL;
        return (space);
}

/**
 * duplicate_process - Duplicate the calling process
 * @array: The string input
 * @space: The set of tokens
 *
 * Return: Nothing
 */
void duplicate_process(char *array, char **space)
{
        pid_t pid;
        int status;

        pid = fork();

        if (pid > 0)
        {
                wait(&status);
        }
        else if (pid == -1)
        {
                perror("Error:");
                free(array);
                free(space);
                exit(0);
        }
        else if (pid == 0)
        {
                if ((execve(space[0], space, NULL) == -1))
                {
                        perror("Does not execute, write valid command");
                        free(array);
                        free(space);
                        exit(0);
                }
        }
}

/**
 * environment_shell - Display the environment variables
 * @space: The set of tokens
 *
 * Return: Nothing
 */
void environment_shell(char **space)
{
        extern char **environ;
        int i = 0;

        if (_strcmp(space[0], "env") == 0)
        {
                while (environ[i] != NULL)
                {
                        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
                        write(STDOUT_FILENO, "\n", strlen(environ[i]));
                        i++;
                }
        }
}

/**
 * exit_shell - Exit the shell
 * @space: The set of tokens
 * @array: The string input
 *
 * Return: Nothing
 */
void exit_shell(char **space, char *array)
{
        if (_strcmp(space[0], "exit") == 0)
        {
                free(space);
                free(array);
                exit(0);
        }
}

