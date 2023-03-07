#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: pointer to the first row in the matrix
 */
void print_chessboard(char (*a)[8])
{
int i, c;
for (i = 0; i < 8; i++)
{
for (c = 0; c < 8; c++)
{
putchar(a[i][c]);
}
putchar('\n');
}
}
