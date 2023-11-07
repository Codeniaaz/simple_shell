#include "main.h"

/**
 *n_erratoi - converts a string to a integer
 *@c: string to be converted and should be numerics
 *Return: success and -1 on error
 */
int n_erratoi(char *c)
{
	int i = 0;
	unsigned long int result = 0;

	if (*c == '+')
		c++;
	for (i = 0;  c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			result *= 10;
			result += (c[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 *n_print_error - prints error messages
 *@member: Struct containing all the needed arguments
 *@str: a string
 *Return: success and -1 on error
 */
void n_print_error(memb_t *member, char *str)
{
	n_eputs(member->fname);
	n_eputs(": ");
	n_print_d(member->line_count, STDERR_FILENO);
	n_eputs(": ");
	n_eputs(member->argv[0]);
	n_eputs(": ");
	n_eputs(str);
}

/**
 *n_print_d - function tat prints decimal integer
 *@buffer: the input
 *@fd: the file descriptor
 *Return: num of chars printed
 */
int n_print_d(int buffer, int fd)
{
	int (*__putchar)(char) = n_putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = n_eputchar;
	if (buffer < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = buffer;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 *n_convert_number - clone of itoa
 *@num: number
 *@base: base
 *@flags: argument flags
 *Return: string
 */
char *n_convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 *n_remove_comments - function replaces first instance of '#' with '\0'
 *@buffer: address of the string to modify
 *Return: always success
 */
void n_remove_comments(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}
