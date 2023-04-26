#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * _fork_fun - function that createS a child process and executes a command
 *@arg: command and arguments to execute
 *@av: name of our program
 *@env: environment variables
 *@lineptr: command line entered by the user
 *@np: id  proces
 *@c: Checker add new test
 *Return: 0 on success, or an error code
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t pid;
	int status;
	char *format = "%s: %d: %s: not Available\n";

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
			{
				free(arg[0]);
			}
			free(arg);
			free(lineptr);
			exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0)== -1)
		{
			perror("waitpid");
			return (1);
		}
		if (WIFEXITED(status))
		{
			{			
				if (WEXITSTATUS(status)!= 0)

				return (WEXITSTATUS(status));
			}
		}
		else if (WIFSIGNALED(status))
		{
			printf("proccess %d killed by signal %d\n",pid, WTERMSIG(status));
		}

	}
	return(0);
	}
}
