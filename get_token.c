#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _get_token - This function will get tokens from a string.
 * @lineptr: The string entered by the user.
 * Return: A pointer to an array of tokens.
 */
char **_get_token(char *lineptr)
{
	char **command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;
/**
 * char *exit_value[] = {"0", "1", "126", "127", "128", "130", "255", NULL};
 */

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if (size + 1 == (int)strlen(lineptr))
		return (NULL);

	command = malloc(sizeof(char *));
	if (command == NULL)
	{
		perror("malloc");
		exit(1);
	}
	token = strtok(NULL, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		command = realloc(command, sizeof(char *) * (i + 1));
		if (command == NULL)
		{
			perror("realloc");
			exit(1);
		}
		command[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (command[i] == NULL)
		{
			perror("malloc");
			exit(1);
		}
		strcpy(command[i], token);
		token = strtok(NULL, "\n\t\r");
	}
	command = realloc(command, sizeof(char *) * (i + 1));
	if (command == NULL)
	{
		perror("realloc");
		exit(1);
	}
	command[i] = NULL;
	for (i = 0; builtins[i] != NULL; i++)
	{
		if (strcmp(command[0], builtins[i]) == 0)
		{
			free(command);
			return (NULL);
		}
	}
	return (command);
}

/**
 * main - The entry point of the program.
 * Return: Always 0.
 */
int main(void)
{
	char *user_input = NULL;
	char **tokens = NULL;

	user_input = malloc(sizeof(char) * 1024);
	if (user_input == NULL)
	{
		perror("malloc");
		exit(1);
	}
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		fgets(user_input, 1024, stdin);
		user_input[strcspn(user_input, "\n")] = '\0';
		tokens = _get_token(user_input);
		if (tokens == NULL)
		{
			printf("Invalid command\n");
			continue;
		}
		for (size_t i = 0; tokens[i] != NULL; i++)
		{
			printf("Token %zu: %s\n", i, tokens[i]);
		}
		for (size_t i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
	free(user_input);
	return (0);
}

