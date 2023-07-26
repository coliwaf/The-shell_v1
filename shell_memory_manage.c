#include "shell.h"

/**
 * free_bytes - frees and Nulls the address
 * @ptr: pointer addr to free
 * Return: if freed return 1, otherwise 0
 */
int free_bytes(void **ptr)
{
	if (ptr && *ptr)
	{
		free (*ptr);
		*ptr = NULL;
		return (1);
	}
	
	return (0);
}
