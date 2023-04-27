#include "main.h"

/**
 * _get_path - Get the value of the PATH environment variable
 * @env: The local environment variables
 *
 * Return: The value of the PATH variable or NULL if it doesn't exist
 */
char *_get_path(char **env)
{
	size_t index, var, count;
	char *path = NULL;

	for (index = 0; strncmp(env[index], "PATH=", 5); index++)
	{
		if (env[index] == NULL)
			return (NULL);
	}

	for (count = 5; env[index][count]; count++)
		;

	path = malloc(sizeof(char) * (count + 1));
	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[index][var]; var++, count++)
	{
		path[count] = env[index][var];
	}
	path[count] = '\0';

	return (path);
}

