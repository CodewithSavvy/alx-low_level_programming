#include "lists.h"

/**
 * print_listint - prints all elements in a structure
 * @h: the head pointer of the nodes
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
size_t n = 0;

while (h)
{
printf("%d\n", h->n);
n++;
h = h->next;
}
return (n);
}

