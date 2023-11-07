#include "main.h"

/**
 *n_strncpy - function copies a string
 *@dest: destination string
 *@src: source string
 *@a: amount chars
 *Return: the concanated string
 */
char *n_strncpy(char *dest, char *src, int a)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < a - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < a)
	{
		j = i;
		while (j < a)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 *n_strncat - func that concats two strings
 *@dest: destination
 *@src: source
 *@a: amount of chars
 *Return: the concatenated string
 */
char *n_strncat(char *dest, char *src, int a)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < a)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < a)
		dest[i] = '\0';
	return (s);
}

/**
 *n_strchr - func that locates a chars in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: a pointer to the memory area
 */
char *n_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
