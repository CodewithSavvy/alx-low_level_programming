#include <stdio.h>
/**
* main - printing combination of three digit
*
*Return: Always 0 (success)
*/
int main(void)
{
	int tens = 0;
	int ones = 0;
	int hundreds = 0;

	for (hundreds = 0; hundreds <= 9; hundreds++)
	{
		for (tens = 0; tens <= 9; tens++)
		{
			for (ones = 0; ones <= 9; ones++)
			{
				if (!((ones == tens) || (tens == hundreds) ||
							(tens > ones) || (hundreds > tens)))
				{
					putchar(hundreds);
					putchar(tens);
					putchar(ones);
					if (!(ones == 9 && tens == 8 && hundreds == 7))
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
