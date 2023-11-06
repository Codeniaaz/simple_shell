#include "main.h"

/**
 * n_bfree - Frees a ptr and sets it to NULL.
 * @ptr: Address of the ptr to free.
 *
 * Return: 1 if the ptr was freed, otherwise 0.
 */
int n_bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
