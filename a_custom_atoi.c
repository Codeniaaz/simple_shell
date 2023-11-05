#include "main.h"

/**
 *n_interactive - checks whether the current interaction 
 *with a program is happening in an interactive mode 
 *@memb: a struct object that will be used to access the structure
 *Return: (1) if in the interactive mode else (0)
 */
int n_interactive(memb_t *memb)
{
	return (isatty(STDIN_FILENO) && memb->readfd <= 2);
}

/**
 *n_is_delim - to check for the delimeter
 *@delimeter: is the delimeter to be passed
 *@c: a string that will be used to check for the delimiter
 *Return: (1) if the delimeter is found else (0)
 */
int n_is_delim(char delimeter, char *c)
{
	while (*c)
	{
		if (*c++ == delimeter)
			return (1);
	}
	return (0);
}

/**
 *n_isalpha - checks for alphabetic character
 *@p: The character to input
 *Return: (1) if p is alphabetic, else (0)
 */

int n_isalpha(int p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int n_atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
