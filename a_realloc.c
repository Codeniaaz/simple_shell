#include "main.h"

/**
 **n_memset - fills memory with a constant bytes
 *@t: pointer to the memory area
 *@b: byte to fill *t with
 *@num: amount of bytes to be filled
 *Return: (t) a pointer to the memory area t
 */
char *n_memset(char *t, char b, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		t[i] = b;
	return (t);
}

/**
 * n_ffree - frees a string of strings
 * @dp: double pointer strings
 * Return: nothing, void.
 */
void n_ffree(char **dp)
{
	char **a = dp;

	if (!dp)
		return;
	while (*dp)
		free(*dp++);
	free(a);
}

/**
 * n_realloc - reallocates a block of memory
 * @ptr: pointer to previous memory allocated block
 * @_old_size: byte size of previous block
 * @_new_size: byte size of new block
 * Return: pointer to the old block.
 */
void *n_realloc(void *ptr, unsigned int _old_size, unsigned int _new_size)
{
	char *q;

	if (!ptr)
		return (malloc(_new_size));
	if (!_new_size)
		return (free(ptr), NULL);
	if (_new_size == _old_size)
		return (ptr);

	q = malloc(_new_size);
	if (!q)
		return (NULL);

	_old_size = _old_size < _new_size ? _old_size : _new_size;
	while (_old_size--)
		q[_old_size] = ((char *)ptr)[_old_size];
	free(ptr);
	return (q);
}
