#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - to print strings with a character
 * @separator: the character to be printed
 * @n: string count
 *
 * Retun: nothing
*/

void print_strings(const char *separator, const unsigned int n, ...)
{
va_list my_strings;
char *str;
unsigned int count;

va_start(my_strings, n);

for (count = 0; count < n; count++)
{
str = va_arg(my_strings, char *);
if (str == NULL)
{
printf("(nil)");
}
else
{
printf("%s", str);
}
if (count != (n - 1) && separator != NULL)
{
printf("%s", separator);
}
}
printf("\n");

va_end(my_strings);
}
