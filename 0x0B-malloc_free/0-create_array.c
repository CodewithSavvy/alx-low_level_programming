#include <stdlib.h>
#include "main.h"

/**
 * create_array - array of char and intialize it with a specific char
 * @size : the nuber of elements the array can hold
 * @c : the specific character to be initialize in the array
 * Return: pointer to the array. or NULL if fails
*/

char *create_array(unsigned int size, char c)
{
char *prtarray;
unsigned int count;

prtarray = (char *) malloc(size * sizeof(char));

if (prtarray == NULL || size == 0)
return (NULL);

for (count = 0; count < size; count++)
{
prtarray[count] = c;
}
return (prtarray);
}
