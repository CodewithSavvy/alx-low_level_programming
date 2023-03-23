#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints the numbers with characters
 * @separator: the character to be printed
 * @n: the numbers to be printed
 *
 * Return: nothing
*/

void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list savy_numbers;
unsigned int count = 0;

va_start(savy_numbers, n);

while (count < n)
{
printf("%d", va_arg(savy_numbers, int));

if (count != (n - 1) && separator != NULL)
{
printf("%s", separator);
}
count++;
}
printf("\n");

va_end(savy_numbers);
}
