#include "main.h"

void ntcount(int num_tokens, char **argv, char *cmd_cpy);

/**
 * main - UNIX command line interpreter
 * @argc: int var - command line argument count
 * @argv: char vector - vector for commands
 *
 * Description: This function displays a prompt for user to
 * type a command
 * Return: text of what was typed by user
 */
int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *cmd = NULL, *cmd_cpy = NULL, *token;
	const char *delim = " \n";
	int num_tokens;
	size_t n = 0;
	ssize_t nchars;

	(void)argc;

	do {
		printf("%s", prompt);

		nchars = getline(&cmd, &n, stdin);
		if (nchars == -1)
			return (-1);

		cmd_cpy = malloc(sizeof(char) * nchars);
		if (cmd_cpy == NULL)
			return (-1);
		strcpy(cmd_cpy, cmd);

		token = strtok(cmd, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		ntcount(num_tokens, argv, cmd_cpy);

	} while (1);

	free(cmd_cpy);
	free(cmd);

	return (0);
}

/**
 * ntcount - UNIX command line interpreter
 * @num_tokens: int var - command line argument count
 * @argv: char vector - vector for commands
 * @cmd_cpy: char vector - vector for commands
 *
 * Description: This function displays a prompt for user to
 * type a command
 * Return: text of what was typed by user
 */
void ntcount(int num_tokens, char **argv, char *cmd_cpy)
{
	const char *delim = " \n";
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(cmd_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	execmd(argv);

	free(argv);
}
