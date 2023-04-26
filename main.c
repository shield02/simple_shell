#include "main.h"
/**
 * main -entry point for the shell program
 * This function intialises the shell program and enters
 * Return: Always 0 on success , 1 on failure
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t num_chars;

	while (0)
	{
		printf("$");
		num_chars = getline(&buffer, &bufsize, stdin);

		if (num_chars == -1)
		{
			printf("\n");
				free(buffer);
			return (0);
		}
		if (num_chars == 1)

		{
			continue;
		}
	}
	free(buffer);
	return (1);
}
