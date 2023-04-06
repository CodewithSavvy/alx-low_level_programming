#include "lists.h"
/**
 * free_listint_safe - frees a linked list lisint_t
 * @h: pointer to the first node in the list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
size_t lenth = 0;
int max;
listint_t *current;

/*checking if the list exist*/
if (!h || !*h)
return (0);

while (*h)
{
max = *h - (*h)->next;
if (max > 0)
{
current = (*h)->next;
free(*h);
*h = current;
lenth++;
}
else
{
free(*h);
*h = NULL;
lenth++;
break;
}
}

*h = NULL;
return (lenth);
}
