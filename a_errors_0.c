#include "main.h"

/**
 * n_eputs - Prints an input string to stderr.
 * @str: String to be printed
 * Return: void
 */
void n_eputs(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		n_putchar(str[i]);
		i++;
	}
}

/**
 * n_eputchar - Writes the char r to stderr.
 * @r: The char to print.
 * Return: 1 on success. On error, -1 and errno
 */
int n_eputchar(char r)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (r == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (r != BUF_FLUSH)
	{
		buf[i++] = r;
	}
		return (1);
}

/**
 * n_putfd - Writes the char r to the given fd.
 * @r: Character to print.
 * @fd: File descriptor to write to.
 * Return: On success 1. On error, -1 is returned and errno
 */
int n_putfd(char r, int fd)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (r == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(fd, buf, n);
		n = 0;
	}

	if (r != BUF_FLUSH)
	{
		buf[n++] = r;
	}
		return (1);
}

/**
 * n_putsfd - Prints an input string to the specified file descriptor.
 * @str: String to be printed.
 * @fd: Filedescriptor to write into.
 * Return: The number of characters put.
 */
int n_putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str)
	{
		i += n_putfd(*str++, fd);
	}

	return (i);
}
