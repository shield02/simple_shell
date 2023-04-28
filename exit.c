#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - This will returns a pointer which contains a coopi of the string
 * given as a parameter
 * @str: This is the string to print
 *
 *
 * Return: This is a pointer to the duplicated string or NULL if insufficient
 * memory was available
 */
char *_strdup(char *str)
{
	int i;
	char *coopi;

	if (str == '\0')
	{
		return ('\0');
	}
	i = _strlen(str);
	coopi = malloc(sizeof(char) * i + 1);
	if (coopi == '\0')
	{
		return ('\0');
	}
	else
	{
		for (i = 0 ; str[i] != '\0' ; i++)
		{
			coopi[i] = str[i];
		}
	}
	coopi[i] = '\0';
	return (coopi);
}
