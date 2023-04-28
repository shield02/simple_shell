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

	if (lineptr == NULL)
	return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
	if (lineptr[i] == ' ')
		size++;
	}
	if (size + 1 == (int)strlen(lineptr))
	return (NULL);
	token = strtok(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		command[i] = malloc(sizeof(char) * (strlen(token) + 1));
	if (command[i] == NULL)
	{
		perror("malloc");
		exit(1);
	}
	strcpy(command[i], token);
	token = strtok(NULL, " \n\t\r");
	}
	command[i] = NULL;
	for (i = i + 1; i < size + 2; i++)
	{
		command[i] = NULL;
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
	for (int i = 0; tokens[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i, tokens[i]);
	}
	for (int i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
	}
	free(user_input);
	return (0);
}
