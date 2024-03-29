#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - function for addition
 * @n: number of unknwon arguments
 * @...: unknwon arguments
 *
 * Return: the sum of the addition
*/

int sum_them_all(const unsigned int n, ...)
{
va_list list;
unsigned int sum = 0, i = 0;
if (n == 0)
{
return (0);
}
va_start(list, n);

while (i < n)
{
sum += va_arg(list, int);
i++;
}
va_end(list);

return (sum);
}
