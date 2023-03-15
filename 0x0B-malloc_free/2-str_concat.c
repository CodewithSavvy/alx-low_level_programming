#include "main.h"
#include <stdlib.h>
/**
* str_concat - get ends of input and add together for size
* @s1: input one to concat
* @s2: input two to concat
* Return: concat of s1 and s2
*/
char *str_concat(char *s1, char *s2)
{
char *conct;
int i, ci;

/*setting the NULL character to anemty string of both strings*/
if (s1 == NULL)
s1 = "";

if (s2 == NULL)
s2 = "";

/*finding the length of each string*/
i = ci = 0;
while (s1[i] != '\0')
i++;
while (s2[ci] != '\0')
ci++;
/*setting the conct pointer to allocate a block of memmory for s1 and s2*/
conct = malloc(sizeof(char) * (i + ci + 1));
/*if no memmory is allocated then the program should stop*/
if (conct == NULL)
return (NULL);
/*Asigning the strings characters to fill the memmory allocation */
i = ci = 0;
while (s1[i] != '\0')
{
conct[i] = s1[i];
i++;
}
while (s2[ci] != '\0')
{
conct[i] = s2[ci];
i++, ci++;
}
/*Asigning the pointer to the end of both strings*/
conct[i] = '\0';
/*the program is returning a pointer as sucess*/
return (conct);
}
