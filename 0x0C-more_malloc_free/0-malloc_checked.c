#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * malloc_chack - allocate a block of memmory for an array
 * @b: number of bytes to be allocated
 *
 * Return: 98 for a normal termination
*/

void *malloc_checked(unsigned int b)
{
int *ptr;

ptr = malloc(b);

if (ptr == NULL)
exit(98);

return (ptr);
}
