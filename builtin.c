#include "shell.h"
/**
 * split_iput - This will Split the user input
 * @array: this  the string input
 * Return: will returnThe set of tokens
 */
char **split_iput(char *array)
{
	int i, num_tokens = 0;
	char *copy, *token;
	char **tokens;
	
	copy = strdup(input);
/**
 * @copy: token counting the number of tokens in the input
 */
token = strtok(copy, "\n\t");
while (token != NULL)
{
	num_tokens++;
	token = strtok(NULL, "\n\t");
}
free(copy);
/**
 * Allocates the memotry for the tokens array
 */
tokens = malloc(sizeof(char *) * (num_tokens + 1));
if (tokens == NULL)
	return (NULL);
/**
 *token copy tokens in to the array
 */
i = o;
token = strtok(input, "\n\t");
while (token != NULL)
{
	token[i] = strdup(token);
	token = strtok(NULL, "\n\t");
	i++;
}
token[i] = NULL;
return (tokens);
}
/**
 * duplicate_process - Duplicate the calling process and execute the command
 * @input: The user input string
 * @tokens: The set of tokens
 */
void duplicate_process(char *input, char **tokens)

{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("error: ");
		return;
	}
	if (pid == 0)
	{
		execve(tokens[0], tokens, NULL);
		perror("Error ocurred: ");
		exit(EXIT_FAILURE);
	}
	else
	wait(&status);
	free(input);
	free_tokens(tokens);
}
/**
 * print_env - Print the environment variables
 */
void print_env(void)
{
	int i;
	extern char **environ;

	for (i = 0; environ[i] !NULL; i++)
	printf("%s\n", environ[i]);
}
/**
 * exit_shell - Exit the shell program
 * @input: The user input string
 * @tokens: The set of tokens
 */
void exit_shell(char *input, char **tokens)
{
	free(input);
	free_token(tokens);
	exit(EXIT_SUCCESS);
}
/**
 * free_tokens - Free memoety allocated fo the tokens array
 * @tokens: The set of tokens
 */
void free_tokens(char **tokens)
{
	int i;

	for(i = 0; tokens[i] != NULL; i++)
		free (tokens[i]);
	free(token);
}

