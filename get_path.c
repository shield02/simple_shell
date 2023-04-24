#include "shell.h"
#include "string.h"
#include "stdlib.h"
/**
 * _get_path - get the value of the PATH  enviroment variable
 * @env:The enviroment variables
 *
 * Return: Apointer to a strong containing  the vakue of the PATH
 * NULL if the the variable is not found
 */

char *_get_path(char **env)
{
	char *path = NULL;
	size_t index;

	for (index = 0 ; env[index] != NULL; index++)
	{
		if (strncmp(env[index], "PATH=", 5) == 0)
		{
			path = strdup(env[index] + 5);
			break;
		}
	}
	return (path);
}

