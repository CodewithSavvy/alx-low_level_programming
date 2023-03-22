#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - write the name
 * @name: name to be written
 * @f: funtion pointer
 * Return: always 0 as sucess
*/

void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
{
return;
}
f(name);
}
