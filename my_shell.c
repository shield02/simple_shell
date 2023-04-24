#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int line_num;

/**
 * get_line_number - gets current line number and/or add to it
 * @add: if not zero, add this amt
 * Return: the line number
 */
int get_line_number(int add)
{

	line_num = line_num + add;
	return (line_num);
}

/**
 * get_prog_name - gets the program name
 * @name: the name of the prog (first execution)
 * Return: the name of the program
 */
char *get_prog_name(char *name)
{
	static char *prog_name;

	if (!prog_name)
	{
		prog_name = name;
	}
	return (prog_name);
}

/**
 * print_error - custom error printing
 * @command: the message to print
 * @status: the type of error to print
 * @extra: any extra text
 */
void print_error(char *command, int status, char *extra)
{
	char *name = NULL;
	char *line_num = NULL;
	char *msg = NULL;

	name = get_prog_name(NULL);
	line_num = _itoa(get_line_number(0));
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line_num, _strlen(line_num));

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);

	switch (status)
	{
	case 2:
		msg = "not found";
		break;
	case 126:
		msg = "Permission denied";
		break;
	case 127:
		msg = "not found";
		break;
	case 9000:
		/* exit illegal number should exit with a code of 2*/
		msg = "Illegal number: ";
		break;
	default:
		msg = "Unknown error occured.";
	}
	write(STDERR_FILENO, msg, _strlen(msg));

	if (extra)
		write(STDERR_FILENO, extra, _strlen(extra));

	write(STDERR_FILENO, "\n", 1);
}


/**
  * main - simple shell
  * @argc: Number of arguments
  * @argv: list of arguments
  * @envp: environment
  * Return: 0 if successful
  */
static int line_num;
int main(int argc, char **argv, char **envp)
{
	char *filename = NULL;

	get_prog_name(argv[0]);

	if (argc > 2)
		return (-1);

	if (argv && argv[1])
		filename = argv[1];
	signal(SIGINT, SIG_DFL);
	do_env(envp[0], NULL);
	get_line_number(1);

	main_loop(filename);

	return (0);
}
