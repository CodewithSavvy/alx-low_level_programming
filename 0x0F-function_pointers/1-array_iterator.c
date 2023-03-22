#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a function as its parameter
 * @array: array of integers to be executed
 * @size: size of array
 * @action: the function to be executed in this function
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
unsigned int i;
if (array == NULL || action == NULL)
{
return;
}

for (i = 0; i < size; i++)
{
action(array[i]);
}
}
