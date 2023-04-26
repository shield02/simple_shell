#include "shell.h"

/**
 * handle_command - handles a single command input
 * @command: the input command string
 * @envp: the environment variable array
 * @path_value: the value of the PATH environment variable
 * @exit_status: the current exit status
 *
 * Return: the new exit status
 */
int handle_command(char *command, char **envp, int path_value, int exit_status)
{
	char *args = NULL;
	char *input_file = NULL;
	char *output_file = NULL;
	int n = 0;

	args = _get_token(command);
	if (!args)
		return (exit_status);

	for (int i = 0; args[i]; i++)
	{
		if (!strcmp(args[i], "<"))
		{
			input_file = args[i + 1];
			args[i] = NULL;
			break;
		}
		else if (!strcmp(args[i], ">"))
		{
			output_file = args[i + 1];
			args[i] = NULL;
			break;
		}
	}

	if ((!_strcmp(args[0], "exit")) && args[1] == NULL)
	{
		_exit_command(args, command, exit_status);
	}
	else if (!_strcmp(args[0], "env"))
	{
		_getenv(envp);
	}
	else
	{
		n = _values_path(&args[0], envp);
		exit_status = _fork_fun(args, envp, command, path_value, 
				n, input_file, output_file);
		if (n == 0)
			free(args);
	}

	free(args);

	return (exit_status);
}

/**
 * handle_input - handles a single line of input
 * @envp: the environment variable array
 * @path_value: the value of the PATH environment variable
 * @exit_status: the current exit status
 *
 * Return: the new exit status
 */
int handle_input(char **envp, int path_value, int exit_status)
{
	char *command = NULL;

	command = _getline_command();
	if (!command)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(exit_status);
	}

	path_value++;
	exit_status = handle_command(command, envp, path_value, exit_status);

	free(command);

	return (exit_status);
}

/**
 * main - main functions that runs the shell
 * @agrc: argument  count
 * @argv: array of arguments strings
 * @envp: array of environment variables strings
 *
 * Return: exit status
 */
int main(int argc, char **argv, char **envp)
{
	int exit_status = 0;
	int path_value = 0;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		exit_status = handle_input(envp, path_value, exit_status);
	}

	return (exit_status);
}

