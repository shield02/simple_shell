#include "shell.h"

/**
 * _strncpy - Copies a string
 * @dest: The destination string to be copied to
 * @src: The source string
 * @n: The amount of characters to be copied
 *
 * Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strncat - Concatenates two strings
 * @dest: The first string
 * @src: The second string
 * @n: The amount of bytes to be maximally used
 *
 * Return: The concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0' && j < n; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}

/**
 * _strchr - Locates a character in a string
 * @s: The string to be parsed
 * @c: The character to look for
 *
 * Return: A pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (c == '\0')
		return (s);

	return (NULL);
}

