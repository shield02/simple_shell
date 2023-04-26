#include "main.h"

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
    char *cmd = NULL, *cmd_cpy = NULL;
	size_t n = 0;
	ssize_t nchars;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i = 0;

	(void)argc;

	do
	{
		printf("%s", prompt);

		nchars = getline(&cmd, &n, stdin);

		if (nchars == -1)
		{
			return (-1);
		}

		cmd_cpy = malloc(sizeof(char) * nchars);
		if (cmd_cpy == NULL)
		{
			return (-1);
		}

		strcpy(cmd_cpy, cmd);

		token = strtok(cmd, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

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

	} while (1);

	free(argv);
	free(cmd);
	free(cmd_cpy);


	return (0);
}

