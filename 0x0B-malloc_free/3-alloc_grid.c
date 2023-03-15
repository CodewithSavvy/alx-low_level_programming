#include "main.h"
#include <stdlib.h>
/**
* alloc_grid - nested loop to make grid
* @width: width input
* @height: height input
* Return: pointer to 2 dim. array
*/
int **alloc_grid(int width, int height)
{
int **mee;
int x, y;

/*breaking the program if width and hight is 0*/
if (width <= 0 || height <= 0)
return (NULL);

/*Asingnig mee pointer to allocate memmory in the heap*/
mee = malloc(sizeof(int *) * height);

/*if pointer mee is 0 the program should terminate*/
if (mee == NULL)
return (NULL);

for (x = 0; x < height; x++)
{
mee[x] = malloc(sizeof(int) * width);
if (mee[x] == NULL)
{
for (; x >= 0; x--)
free(mee[x]);
free(mee);
return (NULL);
}
}
for (x = 0; x < height; x++)
{
for (y = 0; y < width; y++)
mee[x][y] = 0;
}
return (mee);
}

