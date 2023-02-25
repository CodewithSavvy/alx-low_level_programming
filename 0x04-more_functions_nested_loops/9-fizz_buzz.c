#include <stdio.h>

/**
* main - a program that prints a digits from 1 t0 100 on the terminal
*
*Return: 0
*/

int main(void)
{
int u;

for (u = 1; u <= 100; u++)
{
if (u % 3 == 0 && u % 5 != 0)
{
	printf(" Fizz");
}
else if (u % 5 == 0 && u % 3 != 0)
{
	printf(" Buzz");
}
else if (u % 5 == 0 && u % 3 == 0)
{
	printf(" FizzBuzz");
}
else if (u == 1)
{
	printf(" %d", u);
}
else
{
	printf(" %d", u);
}
	printf("\n");
}
return (0);
}
