#include <stdio.h>
/**
 * main - Entry piont
 *
 * Return: Always 0 (sucess)
 */
int main(void)
{
	int c;
	int d;

	c = 'a';
	d = 'A';

	while
		(c <= 'z') {
			putchar(c);
			c++;
		}
	while
		(d <= 'Z') {
			putchar(d);
			d++;
		}
	putchar('\n');
	return (0);
}


