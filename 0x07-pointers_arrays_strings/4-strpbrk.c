#include "main.h"

/**
 * _strpbrk - function
 * @s : pointer to check if the value is inside
 * @accept : the value to check
 * Return:  a pointer to the byte in s that matches one of the bytes in
 * accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
int i;
while (*s != '\0')
{
i = 0;
while (accept[i] != '\0')
{
if (*s == accept[i])
{
return (s);
}
i++;
}
s++;
}
return (0);
}
