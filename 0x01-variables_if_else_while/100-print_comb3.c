#include <stdio.h>
/**
* main - printing combination of two digit
*
*Return: Always 0 (success)
*/
int main(void)
{
	int tens = 0;
	int ones = 0;

	for (tens = 0; tens <= 9; tens++)
	{
		for (ones = 0; ones <= 9; ones++)
		{
			if (!((ones == tens) || (tens > ones)))
			{
				putchar(tens);
				putchar(ones);
				if (!(tens == 8 && ones == 9))
				{
					putchar(',');
					putchar(' ');
			}	}
		}
	}
	putchar('\n');
	return (0);
}
